a=int(input("Enter angles in degrees"))
b=int(input())
c=int(input())
d=int(input())
p=int(input("Enter length of side"))
q=int(input())
r=int(input())
s=int(input())

if a+b+c+d==360:
	if a==90 and b==90 and c==90 and d==90:
		if p==r and q==s and p==q:
			print("The given quadrilateral is a square")
		elif p==r and q==s:
			print("The given quadrilateral is a rectangle")
		else:
			print("The given quadrilateral is neither a rectangle nor a square")	
	else:
			print("The given quadrilateral is neither a rectangle nor a square")			
else:
	print("The given quadrilateral is invalid")
