a=["Maths","Physics","Chemistry","Computer Science","English"]
total=0
for i in range(5):
	print("Enter marks in ",a[i])
	total+=int(input())
	
mean=total/5

if mean<40:
	print("Your grade is ","F")
elif mean<50:
	print("Your grade is ","E")	
elif mean<60:
	print("Your grade is ","D")	
elif mean<70:
	print("Your grade is ","C")	
elif mean<80:
	print("Your grade is ","B")	
elif mean<90:
	print("Your grade is ","A")	
else:
	print("Your grade is ","A+")
	
	
							
	
	
