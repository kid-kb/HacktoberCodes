# Keshav Bhalla
# 11812046

from sklearn.metrics import classification_report, confusion_matrix
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


def main():

    data = pd.read_csv('ML_LAB_EXAM.csv')
    X = data.drop('Species', axis=1)
    y = data['Species']

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20)

    svclassifier = SVC(kernel='rbf')
    svclassifier.fit(X_train, y_train)
    y_pred = svclassifier.predict(X_test)

    correct = incorrect = 0
    for i in range(len(y_pred)):
        if(y_pred[i] == y_test[i]):
            correct += 1
        else :
            incorrect += 1
    # print(confusion_matrix(y_test, y_pred))
    # print(classification_report(y_test, y_pred))
    # for i in classification_report(y_test, y_pred):
    #     print(i, end=" ")

    acc_svm = round(correct/(correct+incorrect), 2)

main()