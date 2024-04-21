l=list(map(int,input().split()))
num=int(input("Enter number to search"))
flag=0
for i in range(len(l)):
    if l[i]==num:
        flag=i
        break



if flag==0:
    print("The given number is not present in the list")
else:
    print("The given number present in position %d in the list" %(flag+1))    
    