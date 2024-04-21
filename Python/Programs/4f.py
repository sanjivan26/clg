x=int(input("Enter the required number"))
sum=0
while(x>0):
    sum+=(x%10)
    x=int(x/10)
print(sum)    
