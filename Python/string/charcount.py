s=input()
c=[100000]
v=[""]
le=0
for i in range(len(s)):
    for j in range(le):
        if s[i]==v[j]:
            c[j]+=1
            x=j+1
            break
    else:
        v.append(s[i])
        c.append(1)
        le+=1 
        x=le  

    print(c,v)      

     

    while c[x]>=c[x-1] and c[x-1]!=100000:
        print("a")
        temp= c[x]
        c[x]= c[x-1]
        c[x-1]=temp
        tem=v[x]
        v[x]=v[x-1]
        v[x-1]=tem
        x-=1

print("The counts are:")
for k in range(1,le+1):
    print(v[k]," ",c[k])