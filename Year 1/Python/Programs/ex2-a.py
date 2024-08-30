import math as m

menu = int(input("Enter 0 for triangle, 1 for parallelogram, 2 for cylinder, 3 for cone, 4 for sphere and 5 for rectangular prism"))

if menu==0:
	a=int(input("Enter the Base and Height"))
	b=int(input())
	
	ans=1/2*a*b
	
if menu==1:
	a=int(input("Enter the Base and Height"))
	b=int(input())
	ans=a*b
	
if menu==2:
	a=int(input("Enter the Radius and Height"))
	b=int(input())	
	ans=m.pi*a*a*b
	
if menu==3:
	a=int(input("Enter the Radius and Length"))
	b=int(input())	
	ans=m.pi*a*b
	
if menu==4:
	a=int(input("Enter the Radius"))
		
	ans=4/3*m.pi*a**3
	
if menu==5:
	a=int(input("Enter the Length Breadth and Height"))
	b=int(input())
	c=int(input())	
	ans=2*(a*b+b*c+c*a)	
	
print("The area is",round(ans,2))	
