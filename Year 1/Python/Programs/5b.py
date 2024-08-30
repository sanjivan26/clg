
s=input()
l=[]
for i in range(len(s)):
    if s[i]==s[0]:
        for j in range(i,len(s)):
            if s[j]==s[-1]:
                l.append(s[i:j+1])
print(l)                
