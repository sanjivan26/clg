s=list(input())
for i in range(len(s)):
    if s[i] == " ":
        s[i+1]=chr(ord(s[i+1])+1)
print("".join(s))        
