x=int(input())
for i in range(x):
    n=int(input())
    l=list(map(int,input().split()))

    if(n%2==0):
        k=n/2
        for i in range(n+1):
            if i%2==0:
                k+=i
            else:
                k-=i
            if l[:k+1].count(0)>=k/2 and l[k+1:].count(1)>=(n+k)/2:
                print(k)
                break
    else:
        k=n//2
        for i in range(n+1):
            if i%2==0:
                k-=i
            else:
                k+=i
            if l[:k].count(0)>=k/2 and l[k:].count(1)>=((n+k)/2-k):
                print(k)
                break        

