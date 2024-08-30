def py1(m,n):
    return m**2-n**2
def py2(m,n):
    return 2*m*n
def py3(m,n):
    return m**2+n**2


N=int(input("Enter value for N"))
for m in range(1,N):
    for n in range(1,m):
        if(py3(m,n)<=N):
            print(py1(m,n),py2(m,n),py3(m,n))
        else:
            break