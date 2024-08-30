d={"hi":1,"hulo":2,"yo":3,"hey":4}
d2={}
d3={}
for i in d.keys():
    d2[d[i]]=i
l=list(d.values())
l.sort()    
for i in l:
    d3[d2[i]]=i
print(d3)      