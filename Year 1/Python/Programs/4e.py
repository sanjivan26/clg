sum=1
x=1
y=2
for i in range(1,int(input("Enter value for n"))):
    sum+=((x**(i+1))*((-1)**i))
    z=y
    y+=x
    x=z
print("The sum of the series is ",sum)    