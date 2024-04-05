x=int(input())
for i in range(x):
    n=int(input())
    s=input()
    if ord(s[0])>ord(s[-1]):
        print(s[::-1]+s)
    else:
        print(s)