s=input("string")
words=s.strip().split()

for i in words:
    i=i[::-1]

print(str(words).join(" "))
