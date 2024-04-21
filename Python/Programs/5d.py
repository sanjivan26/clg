s=input()
s2=""
for i in s:
    if i not in s2:
        s2+=i
l=[]
for i in s2:
    l.append(s.count(i))

while(1):
    max=0
    for i in range(len(s2)):    
        if l[max]<=l[i]:
            max=i
    if l[max]==0:
        break
    else:        
        print(s2[max]," : ",l[max]," , ")
        l[max]=0
