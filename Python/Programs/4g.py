n=float(input("Enter a value for n"))
l=float(input("Enter the limit"))
x=n
while(abs(x-0.5*(x+(n/x)))>l):
    x=0.5*(x+(n/x))
print("The square root according to the given limit is",x)
