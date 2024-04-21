def large(x,max):
    if(x==0):
        return max
    if(x%10>max):
        max=x%10
    return(large(x//10,max)    )
x=int(input())
print(large(x,x%10))
