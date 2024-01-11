import os
from operator import itemgetter
from itertools import groupby

outFile = open("out.txt", "w")
interimFile = open ("temp.txt", "w")
directory = 'traces'
items = []
for fileName in os.listdir(directory):
    traceFile = os.path.join(directory, fileName)
    f = open(traceFile, 'r')
    for line in f:
        interimFile.write(line)
    f.close()

with open("temp.txt") as f:

    data=f.readlines()
    data.sort(key=lambda x:float(x.split(',')[0]))
    #unique_list = list(map(itemgetter(0), groupby(data)))



    for item in data:
        # write each item on a new line
        outFile.write("%s" % item)
outFile.close()
