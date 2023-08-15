import requests
import json
import yaml
import pandas as pd
import numpy as np
from zipfile import ZipFile
from urllib.request import urlopen


# get NEURON model from neuroml-db from Allen model id and return neuroml-db model id
def download_neuroml_model(model_id):

    # get neuroml-db model id
    search_url = 'http://neuroml-db.org/api/search?q=' + model_id

    nmldb_model_response = requests.get(search_url)

    search_result = nmldb_model_response.content
    json_search = json.loads(search_result)
    nmldb_id = json_search[0]['Model_ID']

    # get NEURON version of model
    neuron_url = f'https://neuroml-db.org/GetModelZip?modelID={nmldb_id}&version=NEURON'
    neuron_resp = urlopen(neuron_url)

    neuron_response = requests.get(neuron_url)
    open(f'/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_zips/{model_id}_neuron.zip', 'wb').write(neuron_response.content)

    with ZipFile(f"/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_zips/{model_id}_neuron.zip", 'r') as zObject:
        zObject.extractall(path='/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models')

    return nmldb_id


models_fname = '/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_class.yml'

with open(models_fname, 'r') as file:
    models = yaml.load(file, Loader=yaml.Loader)

models_df = pd.DataFrame.from_dict(models)

model_columns = ['model_id', 'cre_line', 'model_type', 'cell_type', 'nmldb_id']

exc_models_df = pd.DataFrame(columns=model_columns)
inh_models_df = pd.DataFrame(columns=model_columns)

for _, model_row in models_df.iterrows():
    exc_model = model_row['exc']
    inh_model = model_row['inh']

    if exc_model != '':
        exc_model_data = exc_model.split('_')
        exc_nmbdb_id = download_neuroml_model(exc_model_data[0])
        exc_model_data.append(exc_nmbdb_id)

        exc_models_df.loc[len(exc_models_df.index)] = exc_model_data
    
    if inh_model != '':
        inh_model_data = inh_model.split('_')
        inh_nmbdb_id = download_neuroml_model(inh_model_data[0])
        inh_model_data.append(inh_nmbdb_id)

        inh_models_df.loc[len(inh_models_df.index)] = inh_model_data
