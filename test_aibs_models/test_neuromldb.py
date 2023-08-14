import requests
import json
from zipfile import ZipFile
from urllib.request import urlopen
from io import BytesIO

# get neuroml-db model id
search_url = 'http://neuroml-db.org/api/search?q=473863035'

nmldb_model_response = requests.get(search_url)
search_result = nmldb_model_response.content

json_search = json.loads(search_result)

nmldb_id = json_search[0]['Model_ID']

# get NEURON version of model
neuron_url = f'https://neuroml-db.org/GetModelZip?modelID=NMLCL001535&version=NEURON'

neuron_resp = urlopen(neuron_url)

# tempzip = open("/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/test.zip",'wb')
# tempzip.write(neuron_resp.read())
# tempzip.close()

# zf = ZipFile('/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/test.zip')
# zf.extractall(path='/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/test')
# zf.close()

neuron_response = requests.get(neuron_url)
open('/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_neuron.zip', 'wb').write(neuron_response.content)

with ZipFile("/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_neuron.zip", 'r') as zObject:
    zObject.extractall(path='/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/model_neuron')



temp = 5