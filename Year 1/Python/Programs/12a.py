import re
import sys
n = len(sys.argv)
file=open("example.txt")
d0={}
d1={}
d2={}
d3={}
d4={}
lines=0
words=0
linelist=file.readlines()
for i in linelist:
    lines+=1
    i=re.sub("[^a-zA-Z0-9\s]","",i)
    l=(list(i.split()))
    
    for k in l:
        words+=1
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

    if l[0] in d0:
        d0[l[0]]+=1
    else:
        d0[l[0]]=1   

for i in d0:
    d0[i]=d0[i]/lines         

for i in d1:
    d1[i]=d1[i]/lines

d4=dict(d2)
for i in d2:
   d2[i]=d2[i]/d1[((i.split())[0])]
print(d2)   

for i in d3:
    d3[i]=d3[i]/d4[(((i.split())[0])+" "+((i.split())[1]))]

if (n<2):
    print("Inadequate arguements")
elif n<3:
    try:
        print("The chance of given arguement being a sentence is : ",d0[sys.argv[1]])
    except Keyerror:
        print("The chance of given arguement being a sentence is : 0")
        
elif n<4:
    print("The chance of given arguement being a sentence is : ",d0[sys.argv[1]]*d2[sys.argv[1]+" "+sys.argv[2]])
elif n<5:
    print("The chance of given arguement being a sentence is : ",d0[sys.argv[1]]*d2[sys.argv[1]+" "+sys.argv[2]]*d3[sys.argv[1]+" "+sys.argv[2]+" "+sys.argv[3]])
else:
    print("Excess of arguements given")