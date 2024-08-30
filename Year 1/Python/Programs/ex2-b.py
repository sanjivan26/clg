p=float(input("Enter the principal amount"))
r=int(input("Enter the rate of interest"))
t=int(input("Enter time in years"))
n=int(input("Enter the no. of times interest is compounded per year"))

print("The Simple interest is",(p*r*t)/100)
print("The Compound interest is",round(p*(1+r/(100*n))**(n*t)-p,4))	

