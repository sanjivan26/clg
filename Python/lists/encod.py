l=list(map(int,input().split()))
s=[]
global i
i=0
while i<len(l):
    if i==len(l)-1 or l[i]!=l[i+1]:
        s.append(l[i])
    else:
        n=i
        while(l[i]==l[i+1]):
            i+=1
        s.append([l[i],i-n+1])
    i+=1    
print(s)            
