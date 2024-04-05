def bincheck(x):
    for i in x:
        if i not in [0,1]:
            return 0
    return 1

def nextprime(x):
    for j in range(2, int((x+1)/2)+1):
        if i % j == 0:
            return nextprime(x+1)
    return x+1    

x=int(input())
for y in range(x):
    n=int(input())
    flag=1
    while flag==1:
        if bincheck(str(int(n)))==1:
            flag=2
            break
        i=2
        while(1):
            b=int(str(format(i,"b")))
            if b > n:
                flag=0
                break
            if n%b==0:
                n=int(n/b)
                print(b,n)
                if bincheck(str(n))==1:
                    flag=2  
                break
            i=nextprime(i)
    if flag==0:
        print("NO")
    elif flag==2:
        print("YES")   