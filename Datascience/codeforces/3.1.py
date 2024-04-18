x=int(input())
for i in range(x):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    print(2*(l[n-1]+l[n-2]-l[0]-l[1]))    