# Keshav Bhalla
# 11812046

import csv

def cand_elim(s, g, data, output_file):
    for row in data[1:]:
        if row[-1] == "yes":
            for j in range(len(s)):
                if row[j] != s[j]:
                    s[j] = '?'
                    g[j][j] = '?'
        elif row[-1] == "no":
            for j in range(len(s)):
                if row[j] != s[j]:
                    g[j][j] = s[j]
                else:
                    g[j][j] = "?"
        output_file.write("Steps of Candidate Elimination Algorithm " + str(data.index(row)+1))
        output_file.write("\nSpecific hypothesis " + str(s))
        output_file.write("\nGeneral hypothesis " + str(g) + '\n')

    gh = []
    for row in g:
        for j in row:
            if j != '?':
                gh.append(row)
                break
    output_file.write("\nFinal specific hypothesis:\n")
    output_file.write(str(s))
    output_file.write("\nFinal general hypothesis:\n")
    output_file.write(str(gh))

    # Version space
    vs = []
    for row in gh:
        for i in range(len(row)):
            if row[i] != '?':
                temp = list('?'*len(row))
                temp[i] = row[i]
                for j in range(i + 1, len(row)):
                    if s[j] != '?':
                        temp2 = []
                        for x in temp:
                            temp2.append(x)
                        temp2[j] = s[j]
                        vs.append(temp2)
    output_file.write("\n\nVersion Space\n")
    output_file.write(str(vs))


def main():
    output_file = open('result_candidate.txt', 'w')

    with open("a2.csv") as f:
        csv_file = csv.reader(f)
        data = list(csv_file)    
    s = data[1][:-1]
    g = [['?' for i in range(len(s))] for j in range(len(s))]

    cand_elim(s, g, data, output_file)
    output_file.close()

main()
