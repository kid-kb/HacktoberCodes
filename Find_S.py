# Keshav Bhalla
# 11812046

import pandas as pd
import numpy as np

def train(c, t, file):
    specific_hypothesis = []
    for i, val in enumerate(t):
        if val == 'yes':
            specific_hypothesis = c[i].copy()
            break
             
    for i, val in enumerate(c):
        if t[i] == 'yes':
            for x in range(len(specific_hypothesis)):
                if val[x] != specific_hypothesis[x]:
                    specific_hypothesis[x] = '?'

    file.write("Hypothesis\n")
    file.write(str(specific_hypothesis))
    

def main():
    
    output_file = open('result_finds.txt', 'w')
    data = pd.read_csv('dataset_finds.csv')

    d = np.array(data)[:,:-1]
    output_file.write("Atrributes\n")
    output_file.write(str(d) + '\n')
    target = np.array(data)[:,-1]
    output_file.write("Target\n")
    output_file.write(str(target) + '\n')

    train(d, target, output_file)
    output_file.close()

main()


'''

Find-S Algo

Intialize ‘h’ with the most specific hypothesis, generally, it is the first positive example in the data set.
Check for each positive example. If the example is negative, skip it otherwise follow below steps.
Check if each attribute in the example is equal to the hypothesis value.
If the value matches, then no changes are made.
If the value does not match, the value is changed to ‘?’.
Do this until the last positive example in the data set.

'''