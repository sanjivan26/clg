import math

def fact(x):
    if(x==1):
        return 1
    return x*fact(x-1)

def sine(x,N):
    sum=x
    n=3
    temp=-1
    for i in range(1,N):
        sum+=(temp*(x**n)/fact(n))
        n+=2
        temp*=-1
    return sum

def cosine(x,N):
    sum=1
    n=2
    temp=-1
    for i in range(1,N):
        sum+=(temp*(x**n)/fact(n))
        n+=2
        temp*=-1
    return sum    

x=math.radians(int(input("Enter x in degrees")))
N=int(input("Enter value for N, -1 if no value"))
if(N==-1):
    N=25
print("The sine is ",sine(x,N))    
print("The cosine is ",cosine(x,N))        
