file=open("example.txt")
d1={}
d2={}
lines=0
words=0
characters=0
for i in file:
    lines+=1
    l=(list(i.split()))
    words+=len(l)
    for k in l:
        if k in d2:
            d2[k]+=1
        else:
            d2[k]=1         
    for j in i:
        characters+=1
        if j in d1:
            d1[j]+=1
        else:
            d1[j]=1
print('The no of lines is ',lines)
print('The no of words is ',words)      
print('The no of characters is ',characters)      
print('No of occurences of each character :')
for i in d1:
    print(i," : ",d1[i])
for i in d2:
    print(i," : ",d2[i])