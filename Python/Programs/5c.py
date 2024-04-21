s=input()
n=int(input())
i=0

while(n*(i+1)<len(s)):
    print(s[n*i:n*(i+1)],"\n")
    i+=1
print(s[i*n:])    