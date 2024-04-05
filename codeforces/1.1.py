loopcount=int(input())
for i in range(loopcount):
    n=int(input())
    l1=list(map(int,input().split()))
    sum=0
    for i in range(n):
        sum+=abs(l1[i])
    print(sum)    
