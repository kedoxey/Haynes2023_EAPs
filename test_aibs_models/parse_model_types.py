import os
import numpy as np
import pandas as pd
import yaml
from pprint import pprint

inh_cres = ['Pvalb', 'Sst', 'Vip']
exc_cres = ['Rorb-Ires2', 'Scnn1a-Tg2', 'Scnn1a-Tg3', 'Nr5a1', 'Rbp4']  # pyramidal

file_dir = file_dir = os.path.dirname(os.path.realpath(__file__))

f = os.path.join(file_dir,'aibs_model_types.csv')
cell_tags_df = pd.read_csv(f)

model_ids = cell_tags_df.id.tolist()
cre_lines = cell_tags_df.cre_lines.tolist()
model_types = cell_tags_df.model_type.tolist()

model_class = {'inh': [], 'exc': []}

for model_id, cre, model_type in zip(model_ids, cre_lines, model_types):
    tag1 = model_id
    tag2 = cre.split("-")[0]

    if model_type == 'perisomatic':
        tag3 = 'ps'
    else:
        tag3 = 'aa'

    if tag2 in inh_cres:
        tag4 = 'inh'
        model_class['inh'].append(f"{tag1}_{tag2}_{tag3}_{tag4}")
    else:
        tag4 = 'exc'
        model_class['exc'].append(f"{tag1}_{tag2}_{tag3}_{tag4}")

num_inh = len(model_class['inh'])
num_exc = len(model_class['exc'])

padding = ['']*(num_exc - num_inh)
model_class['inh'].extend(padding)

model_class_df = pd.DataFrame(model_class)

with open(os.path.join(file_dir,'model_class.yml'), 'w') as outfile:
    yaml.dump(model_class, outfile, default_flow_style=False)
