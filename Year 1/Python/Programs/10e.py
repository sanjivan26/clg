d={"Even":[],"Odd":[]}
for i in list(map(int,input().split())):
    if i%2==0:
        d["Even"].append(i)
    else:
        d["Odd"].append(i)
print(d)        