import re
file=open("example.txt")
d0={}
d1={}
d2={}
d3={}
d4={}
lines=0
linelist=file.readlines()
for i in linelist:
    lines+=1
    i=re.sub("[^a-zA-Z0-9\s]","",i)
    l=(list(i.split()))
    
    for k in l:
        if k in d1:
            d1[k]+=1
        else:
            d1[k]=1

    for j in range(len(l)-1):
        k=l[j]+" "+l[j+1]
        if k in d2:
            d2[k]+=1
        else:
            d2[k]=1      

    for j in range(len(l)-2):
        k=l[j]+" "+l[j+1]+" "+l[j+2]
        if k in d3:
            d3[k]+=1
        else:
            d3[k]=1    

    if l[0] in d1:
        d1[l[0]]+=1
    else:
        d1[l[0]]=1   

for i in d1:
    d1[i]=d1[i]/lines       
print(d1)   
print(d2)
for i in d2:
   d2[i]=d2[i]/d1[((i.split())[0])]