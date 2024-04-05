x=int(input())
for i in range(x):
    n=int(input())
    l=list(map(int,input().split()))
    flag=0
    for j in range(n-2):
        if l[j]<0:
            flag=1
            break        
        l[j+1]-=(2*l[j])
        l[j+2]-=l[j]
    if l[n-2]!=0 or l[n-1]!=0:
        flag=1
    if flag==0:
        print("YES")
    else:
        print("NO")    