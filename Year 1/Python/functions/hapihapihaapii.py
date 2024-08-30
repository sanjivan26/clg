def perf(num):
    sum=0
    for i in range(1,num):
        if num%i==0:
            sum+=i
    if sum==num:
        return 1
    else:
        return 0     

def hapi(x):
    sum=0
    while x!=0:
        sum+=x%10
        x=int(x/10)
    if sum%10==1:
        return 1
    else:
        return 0              

n=int(input("enter number"))
print(perf(n),hapi(n))

