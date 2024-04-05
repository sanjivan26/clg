import re
def conv(a):
    if re.findall(r"[0-9]+\.?[0-9]*",a)!=[]:
        return float(a)
d={"a":"1.20","2.3":"b","c":"1"}   
for i in d:
    i=conv(i)
    d[i]=conv(d[i])    
print(d)