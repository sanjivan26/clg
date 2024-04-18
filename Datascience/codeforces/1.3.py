x=int(input())
for i in range(x):
    count=0
    l=list(map(int,input().split()))
    for k in range(1,l[2]+1):
        if(l[2]%k==0):
            m=0
            n=0
            flag=0
            while(l[0]**m<=l[2]):
                while(l[0]**m+l[1]**n<=l[2]):
                    if((k==l[0]**m)*(l[1]**n)):
                        flag=1                     
                    n+=1
                m+=1
        if flag==1:
            count+=1
    print(count)                  