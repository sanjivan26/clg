x=int(input())
for i in range(x):
    n=input()
    l=list(map(int,input().split()))
    count=0
    flag1=0
    for i in l:
        count+=i
        if i%3==1:
            flag1=1    
    if count%3==0:
        print(0)
    elif count%3==2 or (count%3==1 and flag1==1):
        print(1)
    else:
        print(2)   
