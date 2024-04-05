x=int(input("Give a value for x"))
n=int(input("Give a value for n"))
a=0
for i in range(1,n+1,2):
    if ((i-1)/2)%2==0:
        a+=(x**i)
    if ((i-1)/2)%2==1:
        a-=(x**i)
print("The total value is ",a)        
