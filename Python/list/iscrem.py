m=int(input())
n=list(map(int,input().split()))
for i in n:
    for j in n:
        if(i+j==m):
            print(i,j)