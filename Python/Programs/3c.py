a=int(input("Enter 3 numbers"))
b=int(input())
c=int(input())

if a>=b:
	if a>=c:
		x=a
	else:
		x=c
else:
	if b>=c:
		x=b
	else:
		x=c
					
print("The highest number is",x)			
