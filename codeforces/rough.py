for x in range(int(input())):
    flag=1
    n=list(map(int,input().split()))
    l=list(map(int,input().split()))
    right=n[1]//2
    left=right+n[1]%2
    count=0
    while left>0:
        if l!=[]:
            if left>=l[0]:
                left-=l[0]
                l.pop(0)
                count+=1
            else:
                l[0]-=left
                break
        else:
            break
    while right>0:
        if l!=[]:
            ele=l.pop()
            if right>=ele:
                left-=ele
                count+=1
            else:
                break
        else:
            break    
    print(count)    