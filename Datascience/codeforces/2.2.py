x=int(input())
for i in range(x):
    n=int(input())
    l1=input()
    l2=input()
    s=[]
    count=0
    for i in range(n):
        s.append(l1[:i+1]+l2[i:])

    print(s.sort)        

    # for i in range(n-1):
    #     if(int(l1[i+1])<=int(l2[i])):
    #         s=s+l1[i+1]
    #     else:
    #         s=s+l2[i:n-1]
    #         break   
    # s=s+l2[n-1]            
    # for i in range(n):
    #     if(l1[:i+1]+l2[i:]==s):
    #         count+=1                

