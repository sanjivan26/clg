for x in range(int(input())):
    flag=1
    n=list(map(int,input().split()))
    l=list(map(int,input().split()))
    smol=min(l)
    loopflag=1
    for i in range(n[0]):
        if loopflag==0:
            break
        for j in range(n[0]):
            if (smol+(i*n[2])+(j*n[1])) not in l:
                flag=0
                loopflag=0
                break
            else:
                l.remove(smol+(i*n[2])+(j*n[1]))
    if flag==1:
        print("YES")
    else:
        print("NO")