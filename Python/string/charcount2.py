s=input("Enter a string")
c=[]
v=[]
le=-1
for i in range(len(s)):
    if s[i] not in v:
        v.append(s[i])
        c.append(s.count(s[i]))
        le+=1   
        x=le
        while c[x]>=c[x-1] and x>0:
            temp=c[x]
            c[x]=c[x-1]
            c[x-1]=temp
            tem=v[x]
            v[x]=v[x-1]
            v[x-1]=tem
            x-=1

print("The counts are:")
for k in range(le+1):
    print(v[k]," ",c[k])