x=int(input())
for i in range(x):
    n=list(map(int,input().split()))
    l=list(map(int,input().split()))
    r=list(map(int,input().split()))
    count=0
    for i in l:
        if i>=n[2]:
            continue
        for j in r:
            if i+j<=n[2]:
                count+=1
    print(count)            