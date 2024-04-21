import math as m

#i
a=int(input("Enter first variable"))
b=int(input("Enter second variable"))
c=int(input("Enter angle"))
print("{:e}".format(a*m.cos(c)-b*m.sin(c)))

#ii
a=int(input("Enter first variable"))
b=int(input("Enter second variable"))
print("{:e}".format(a*m.cos(2*m.pi*b)))

#iii
a=int(input("Enter first variable"))
b=int(input("Enter second variable"))
print("{:e}".format(m.exp(a*b)))

#iv
a=int(input("Enter coordinates for first point"))
b=int(input())
c=int(input("Enter coordinates for second point"))
d=int(input())
print("{:e}".format(((c-a)**2+(d-b)**2)**0.5))

#v
a=int(input("Enter angle in radians"))
print("{:e}".format(m.degrees(a)))


#vi
n=float(input("Enter the value"))
print("{:e}".format(m.log2(n)),"{:e}".format(m.log10(n)))

