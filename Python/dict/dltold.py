input={'Science':[88,89,62,95],'Language':[77,78,84,80]}
output=[]
for i in range(len(list(input.values())[0])):
    d={}
    for j in list(input.keys()):
        d[j]=input[j][i]
    output.append(d)    
print(output)        