def arm(x):
    n=x
    sum=0
    while(n!=0):
        sum+=n//10
        n=int(n/10)
    if(sum==x):
        return 1
    else:
        return 0

def defi(x):
    n=x
    for i in range(1,x):
        if(x%i==0):
            n-=i         
    if(n>=0):
        return 1
    else:
        return 0
    
def pal(x):
    if(str(x)==str(x)[::-1]):
        return 1
    else:
        return 0

x=int(input("Enter a integer"))
temp=0
while(temp==0):
    print("1.Armstrong number check \n2.Deficient number check\n3.Palindrome check\n4.Exit")
    n=int(input())
    if n==1:
        print(arm(x))
    elif n==2:
        print(defi(x))
    elif n==3:
        print(pal(x))
    else:
        temp=1            