import requests
import json
import os
from zipfile import ZipFile
from urllib.request import urlopen
from io import BytesIO

top_dir = os.getcwd()

# get neuroml-db model id
model_id = 472430904  # 473863035

search_url = f'http://neuroml-db.org/api/search?q={model_id}'

nmldb_model_response = requests.get(search_url)

search_result = nmldb_model_response.content

json_search = json.loads(search_result)

if json_search:
    print(f'MODEL {model_id} FOUND!')

    nmldb_id = json_search[0]['Model_ID']

    # get NEURON version of model
    neuron_url = f'https://neuroml-db.org/GetModelZip?modelID={nmldb_id}&version=NEURON'

    # neuron_resp = urlopen(neuron_url)

    zip_path = f'{top_dir}/test_aibs_models/model_zips/{nmldb_id}-NEURON.zip'
    unzip_path = f'{top_dir}/test_aibs_models/model_neuron/{nmldb_id}-NEURON'

    neuron_response = requests.get(neuron_url)
    open(zip_path, 'wb').write(neuron_response.content)

    if not os.path.exists(unzip_path):
        os.makedirs(unzip_path)

    with ZipFile(zip_path, 'r') as zObject:
        zObject.extractall(path=unzip_path)
else:
    print(f'MODEL {model_id} NOT FOUND!')


temp = 5