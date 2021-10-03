# Keshav Bhalla
# 11812046

import math

import numpy as np
import pandas as pd


class Node:
    def __init__(self):
        self.children = []
        self.value = ""
        self.isLeaf = False
        self.pred = ""

def entropy(examples):
    pos = 0.0
    neg = 0.0
    for _, row in examples.iterrows():
        if row["Answer"] == "yes":
            pos += 1
        else:
            neg += 1
    if pos == 0.0 or neg == 0.0:
        return 0.0
    else:
        p = pos / (pos + neg)
        n = neg / (pos + neg)
        return -(p * math.log(p, 2) + n * math.log(n, 2))

def information_gain(examples, attr):
    uniq = np.unique(examples[attr])
    gain = entropy(examples)
    for u in uniq:
        subdata = examples[examples[attr] == u]
        #print ("\n",subdata)
        sub_e = entropy(subdata)
        gain -= (float(len(subdata)) / float(len(examples))) * sub_e
    return gain

def ID3(examples, attrs):
    root = Node()
    max_gain = 0
    max_feat = ""
    for feature in attrs:
        gain = information_gain(examples, feature)
        if gain > max_gain:
            max_gain = gain
            max_feat = feature
    root.value = max_feat
    uniq = np.unique(examples[max_feat])

    for u in uniq:
        subdata = examples[examples[max_feat] == u]
        #print ("\n",subdata)
        if entropy(subdata) == 0.0:
            newNode = Node()
            newNode.isLeaf = True
            newNode.value = u
            # np.unique returns an array.
            newNode.pred = np.unique(subdata["Answer"])[0]
            root.children.append(newNode)
        else:
            childNode = Node()
            childNode.value = u
            new_attrs = attrs.copy()
            new_attrs.remove(max_feat)
            grandChild = ID3(subdata, new_attrs)
            childNode.children.append(grandChild)
            root.children.append(childNode)
    return root

def predict_output(input_data, curr_root, data):
    if not curr_root:
        return "Can't predict"

    if curr_root.isLeaf:
        return curr_root.pred

    header_index = -1
    headers = np.array(data.columns)[:-1]
    for i in range(len(headers)):
        if headers[i] == curr_root.value:
            header_index = i
    for i in range(len(curr_root.children)):
        if curr_root.children[i].value == input_data[header_index]:
            return predict_output(input_data, curr_root.children[i], data)
    return predict_output(input_data, curr_root.children[0], data)

def printTree(root: Node, file, depth=0):
    for i in range(depth):
        file.write("\t")
    file.write(root.value)
    if root.isLeaf:
        file.write(" --> " + root.pred)
    file.write("\n")
    for child in root.children:
        printTree(child, file, depth + 1)


def main():
    data = pd.read_csv("dataset_id3.csv")
    features = [feat for feat in data]
    features.remove("Answer")
    root = ID3(data, features)
    output_file = open('result_id3.txt', 'w')
    printTree(root, output_file)
    output_file.write("\n")
    testing_input = np.array(pd.read_csv("dataset_id3.csv"))
    for x in testing_input:
        output_file.write("Test Data:" + str(x))
        output_file.write("\tOutput:"+ predict_output(x, root, data))
        output_file.write("\n")
    output_file.close()

main()
