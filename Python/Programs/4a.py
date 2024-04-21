p=[]
for i in range(2,int(input("Enter the value for n"))+1):
    flag=0
    for j in range(2,i):
        if i%j==0:
            flag=1
    if flag==0:
        p.append(i)    
print("The prime numbers until n are",p)    