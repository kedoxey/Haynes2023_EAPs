import requests
import json
import yaml
import os
import pandas as pd
import numpy as np
from zipfile import ZipFile
from urllib.request import urlopen


top_dir = os.getcwd()

# get NEURON model from neuroml-db from Allen model id and return neuroml-db model id
def download_neuroml_model(model_id):

    # get neuroml-db model id
    search_url = f'http://neuroml-db.org/api/search?q={model_id}'

    nmldb_model_response = requests.get(search_url)

    search_result = nmldb_model_response.content

    json_search = json.loads(search_result)
    status = False
    nmldb_id = 0

    if json_search:

        status = True
        nmldb_id = json_search[0]['Model_ID']

        # get NEURON version of model
        neuron_url = f'https://neuroml-db.org/GetModelZip?modelID={nmldb_id}&version=NEURON'

        zip_path = f'{top_dir}/test_aibs_models/model_zips/{nmldb_id}-NEURON.zip'
        unzip_path = f'{top_dir}/test_aibs_models/model_neuron/{nmldb_id}-NEURON'

        neuron_response = requests.get(neuron_url)
        open(zip_path, 'wb').write(neuron_response.content)

        if not os.path.exists(unzip_path):
            os.makedirs(unzip_path)

        with ZipFile(zip_path, 'r') as zObject:
            zObject.extractall(path=unzip_path)

    return status, nmldb_id


models_fname = f'{top_dir}/test_aibs_models/model_class.yml'

with open(models_fname, 'r') as file:
    models = yaml.load(file, Loader=yaml.Loader)

models_df = pd.DataFrame.from_dict(models)

model_columns = ['model_id', 'cre_line', 'model_type', 'cell_type', 'nmldb_id']

exc_models_df = pd.DataFrame(columns=model_columns)
inh_models_df = pd.DataFrame(columns=model_columns)

found = 0
not_found = 0

# iterate over main df 
for _, model_row in models_df.iterrows():
    exc_model = model_row['exc']
    inh_model = model_row['inh']

    if exc_model != '':
        # if excitatory model is in row, extract info and download model
        exc_model_data = exc_model.split('_')
        exc_status, exc_nmbdb_id = download_neuroml_model(exc_model_data[0])

        if exc_status:
            # if model exists on neuroml-db, add to excitatory df
            print(f'MODEL {exc_model_data[0]} FOUND!')
            found += 1

            exc_model_data.append(exc_nmbdb_id)
            exc_models_df.loc[len(exc_models_df.index)] = exc_model_data
        else:
            # if model does not exist on neuroml-db, add to excitatory df but not found flag
            print(f'MODEL {exc_model_data[0]} NOT FOUND!')
            not_found += 1
            exc_model_data.append('NOT FOUND')
            exc_models_df.loc[len(exc_models_df.index)] = exc_model_data
    
    if inh_model != '':
        # if inhibitory model is in row, extract info and download model
        inh_model_data = inh_model.split('_')
        inh_status, inh_nmbdb_id = download_neuroml_model(inh_model_data[0])

        if inh_status:
            # if model exists on neuroml-db, add to inhibitory df
            print(f'MODEL {inh_model_data[0]} FOUND!')
            found += 1

            inh_model_data.append(inh_nmbdb_id)
            inh_models_df.loc[len(inh_models_df.index)] = inh_model_data
        else:
            # if model does not exist on neuroml-db, add to inhibitory df but not found flag
            print(f'MODEL {inh_model_data[0]} NOT FOUND!')
            not_found += 1

            inh_model_data.append('NOT FOUND')
            inh_models_df.loc[len(inh_models_df.index)] = inh_model_data

print(f'{found} models found')
print(f'{not_found} models not found')

# save dfs in pickle and yaml format
exc_models_df.to_pickle(f'{top_dir}/test_aibs_models/model_neuron/exc_models.pkl', protocol=3)
with open(f'{top_dir}/test_aibs_models/model_neuron/exc_models.yaml', 'w') as outfile:
    yaml.dump(exc_models_df.to_dict(),outfile)

inh_models_df.to_pickle(f'{top_dir}/test_aibs_models/model_neuron/inh_models.pkl', protocol=3)
with open(f'{top_dir}/test_aibs_models/model_neuron/inh_models.yaml', 'w') as outfile:
    yaml.dump(inh_models_df.to_dict(),outfile)
