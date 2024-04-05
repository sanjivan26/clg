x=int(input())
for i in range(x):
    n=int(input())
    l=[15,10,6,3,1]
    count=0
    for j in l:
        while j<=n:
            if n==20 or n==12:
                count+=2
                n=0
            else:    
                n-=j
                count+=1
    print(count)            