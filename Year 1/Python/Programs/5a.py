s=input()
for i in range(len(s)):
    for j in range(i+1,len(s)+1):
        print((s[j-1:i+1:-1]))
        if (s[i:j]==s[j-1:i+1:-1]):
            print(s[i:j]," ",end="")
          