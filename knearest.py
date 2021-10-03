# Keshav Bhalla
# 11812046

import csv
from math import sqrt
import random
 

def knearest(training_data, test_case, k, file):
    l = []
    i = 0
    for data in training_data:
        dist = sqrt((test_case[1]-data[1])**2 + (test_case[2]-data[2])**2 + (test_case[3]-data[3])**2 + (test_case[4]-data[4])**2)
        l.append((dist, i))
        i += 1
    l.sort()

    i = 0
    a = b = c = 0
    for i in range(k):
        if training_data[l[i][1]][5] == "Iris-setosa":
            a+=1
        elif training_data[l[i][1]][5] == "Iris-versicolor":
            b+=1
        elif training_data[l[i][1]][5] == "Iris-virginica":
            c+=1
    
    if a>b and a>c:
        file.write("For test case :" + str(test_case[:-1]) + "\n")
        # print("For test case :", test_case[:-1])
        file.write("Prediction Iris-setosa\n")
        if "Iris-setosa" == test_case[5]:
            file.write("Correct Prediction\n")
        else :
            file.write("Incorrect Prediction\n")
    elif b>a and b>c:
        file.write("For test case :" + str(test_case[:-1])+ "\n")
        file.write("Prediction Iris-versicolor\n")
        if "Iris-versicolor" == test_case[5]:
            file.write("Correct Prediction\n")
        else :
            file.write("Incorrect Prediction\n")
    else:
        file.write("For test case :" + str(test_case[:-1])+ "\n")
        file.write("Prediction Iris-virginica\n")
        if "Iris-virginica" == test_case[5]:
            file.write("Correct Prediction\n")
        else :
            file.write("Incorrect Prediction\n")


def main():
    output_file = open('result_knearest.txt', 'w')

    with open("dataset_knearest.csv") as f:
        csv_file = csv.reader(f)
        data = list(csv_file)    

    training_data = []
    test_data = []
    used_indices = []
    for i in range(25):
        x = random.randrange(1, 150)
        while x in used_indices:
            x = random.randrange(1, 150)
        
        test_data.append(data[x])
        used_indices.append(x)

    for i in range(1, len(data)):
        for j in range(len(data[i])-1):
            data[i][j] = eval(data[i][j])
        if i not in used_indices:
            training_data.append(data[i])
    
    for test_case in test_data:
        knearest(training_data, test_case, 5, output_file)
        output_file.write("\n")

    output_file.close()

main()



