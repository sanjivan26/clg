x=int(input())
for i in range(x):
    l=list(map(int,input().split(":")))
    s="PM"
    if l[0]>12:
        s="AM"
        l[0]%=12
    if l[0]==0:
        l[0]=12
    if(l[0]<10):
        l[0]="0"+str(l[0])    
    if(l[1]<10):
        l[1]="0"+str(l[1])       
    l=map(str,l)
    x=":".join(l)    
    print(x,s)