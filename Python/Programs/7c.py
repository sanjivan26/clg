def fib(x):
    if x<=1:
        return x
    else:
        return (fib(x-1)+fib(x-2))

def ap(x,d,n):
    if(n==0):
        return x
    else:
        return d + ap(x,d,n-1)

def gp(x,d,n):
    if(n==0):
        return x
    else:
        term = d * ap(x,d,n-1)
        return term
    
def tri(x):
    if x==1:
        return x
    else:
        return(x+tri(x-1))

 

temp=0
while(temp==0):
    print("\n1.Fibonacci Series\n2.Arithmetic Progression\n3.Geometric Progression\n4.Harmonic progression\n5.Triangular numbers\n6.exit")
    a=int(input())
    if a==1:
        n=int(input("Enter a value for n"))
        for i in range(n):   
            print(fib(i),end=" ")
    elif a==2:
        x=int(input("Enter a value for x"))
        d=int(input("Enter a value for d"))
        n=int(input("Enter a value for n"))
        for i in range(n):   
            print(ap(x,d,i),end=" ")
    elif a==3:
        x=int(input("Enter a value for x"))
        d=int(input("Enter a value for d"))
        n=int(input("Enter a value for n"))
        for i in range(n):   
            print(gp(x,d,i),end=" ")
    elif a==4:
        x=int(input("Enter a value for x"))
        d=int(input("Enter a value for d"))
        n=int(input("Enter a value for n"))
        for i in range(n):   
            print(1/(ap(x,d,i)),end=" ")
    elif a==5:
        x=int(input("Enter a value for x"))
        for i in range(1,x+1):   
            print(tri(i),end=" ")          
    else:
        temp=1   