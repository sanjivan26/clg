n=int(input("Enter value for n"))
for i in range(2,n+1):
    a=0
    for j in range(2,n):
        if i%j==0:
            a=1
            break
    if a==0:
        print(i)