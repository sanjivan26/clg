x=float(input("Enter coordinates"))
y=float(input())
r=float(input("Enter Radius"))

if (x**2+y**2)>r**2:
	print("The point lies outside the circle")
elif (x**2+y**2)<r**2:
	print("The point lies inside the circle")	
else:
	print("The point lies on the circle")		
