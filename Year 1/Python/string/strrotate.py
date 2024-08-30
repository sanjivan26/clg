s=input("string")
r=input("rotated string")
for i in range(len(s)):
    if (s[-i]+s[0:-i])==r:
        print("The string has to be rotated %d times to the right and %d times to the left" %(i,len(s)-i))