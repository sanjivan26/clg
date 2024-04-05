x=int(input())
for i in range(x):
    n=list(map(int,input().split()))
    l=[n[2]-1]
    for i in range(1,n[1]+1):
        l1=input()
        if l1[2]=="0":
            for j in range(len(l)):
                l[j]=(l[j]+int(l1[0]))%n[0]
        elif l1[2]=="1":
            for j in range(len(l)):
                if int(l1[0])>l[j]:
                    l[j]-=int(l1[0]) 
                    l[j]+=n[0]
                else:
                    l[j]-=int(l1[0])    
        else:
            for j in range(len(l)): 
                l.append((l[j]+int(l1[0]))%n[0])
                if int(l1[0])>l[j]:
                    l[j]-=int(l1[0]) 
                    l[j]+=n[0]
                else:
                    l[j]-=int(l1[0])
        l=list(set(l))

    def temp(x):
        return (x+1)
    ans=list(map(temp,l))  
    print(len(ans))
    print(" ".join(list(map(str,sorted(ans)))))
