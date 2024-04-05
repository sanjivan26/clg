l=list(map(int,input().split()))
for i in range(len(l)):
    if sum(l[:i])==sum(l[i+1:]):
        print(l[i])
        break