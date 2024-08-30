d1={"a":1,"b":2}
d2={"b":3,"c":4}
for i in list(d2.keys()):
    if i in list(d1.keys()):
        d1[i]+=d2[i]
    else:
        d1[i]=d2[i] 
print(d1)        