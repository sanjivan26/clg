s=input()
r=input()

for i in range(len(s)):
    flag=0
    if s[i]!=r and flag==0:
        print(s[i],end="")
    else:
        flag=1    
