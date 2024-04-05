s=input()
c=[0,0,0,0]
for i in range(len(s)):
    if s[i].isupper()==True:
        c[0]+=1
    elif s[i].islower()==True:
        c[1]+=1
    elif s[i].isdigit()==True:
        c[2]+=1    
    else:
        c[3]+=1
print("The number of upper, lower, number and spl characters are ",c[0],c[1],c[2],c[3])        