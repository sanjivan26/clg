a=int(input("Enter the two integer numbers"))
b=int(input())

ba=bin(round(a))
bb=bin(round(b))

print("The binary forms are ",ba,bb)
print("The octal forms are ",oct(int(a)),oct(int(b)))
print("The hexadecimal forms are ",hex(int(a)),hex(int(b)))

print(a&b,float(a&b))
print(a|b,float(a|b))
print(~a,float(~a),~b,float(~b))
print(a>>1, b>>1,float(a>>1),float(b>>1))
print(a<<1, b<<1, float(a<<1),float(b<<1))



