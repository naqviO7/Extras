import matplotlib.pyplot as plt
import os
import pandas as pd
import seaborn as sns
from Bio.Blast.Applications import NcbiblastxCommandline

#add your files and folders here
datadir = os.path.join('data', 'kitasatospora')
outdir = os.path.join('output', 'kitasatospora')
os.makedirs(outdir, exist_ok=True) 

query = os.path.join(datadir, 'k_sp_CB01950_penicillin.fasta')
db = os.path.join(datadir, 'kitasatospora_proteins.faa') 
blastout = os.path.join(outdir, 'AMK19_00175_blastx_kitasatospora.tab')
cmd_blastx = NcbiblastxCommandline(query=query, out=blastout, outfmt=6, db=db)

print(cmd_blastx)

stdout, stderr = cmd_blastx()
print("STDOUT: %s" % stdout)
print("STDERR: %s" % stderr)

results = pd.read_csv(blastout, sep="\t", header=None)
results.head()

headers = ['query', 'subject',
           'pc_identity', 'aln_length', 'mismatches', 'gaps_opened',
           'query_start', 'query_end', 'subject_start', 'subject_end',
           'e_value', 'bitscore']

results.columns = headers
results.head()
results.describe()

print(results['subject'])

qaln_length = abs(results['query_end'] - results['query_start']) + 1
print(qaln_length)

results['qaln_length'] = qaln_length
results.head()

results.plot.scatter('pc_identity', 'e_value')
plt.title("E value vs %identity")


query = os.path.join(datadir, 'lantibiotic.fasta')                      
blastout = os.path.join(outdir, 'lantibiotic_blastx_kitasatospora.tab') 

cmd_blastx = NcbiblastxCommandline(query=query, out=blastout, outfmt=6, db=db)
stdout, stderr = cmd_blastx()
print("STDOUT: %s" % stdout)
print("STDERR: %s" % stderr)

results = pd.read_csv(blastout, sep="\t", header=None)
results.columns = headers

results.plot.scatter('bitscore', 'pc_identity')
plt.title("%identity vs bitscore")
