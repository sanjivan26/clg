a=["apple","banana","cherry","sweetlime"]
b=input("Enter letter")
c=[]
for j in range(3):
    for i in range(len(a[j])):
        if b == a[j][i]:
            c.append(a[j])
print(c)    


