def out(h,i,j,k):
    print((h,i,j,k))
    print((h,i,k,j))
    print((i,h,j,k))
    print((i,h,j,k))
    print((j,k,h,i))
    print((j,k,i,h))
    print((k,j,h,i))
    print((k,j,i,h))

l=list(set(map(int,input().split())))
for a in range(len(l)-3):
    h=l[a]
    for b in range(a+1,len(l)-2):
        i=l[b]
        for c in range(b+1,len(l)-1):
            j=l[c]
            for d in range(c+1,len(l)):
                k=l[d]
                if h*i==j*k:
                    out(h,i,j,k)
                elif h*k==i*j:
                    out(h,k,i,j)
                elif h*j==i*k:
                    out(h,j,i,k)