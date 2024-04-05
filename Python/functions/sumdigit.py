x=0
def digisum(num):
    global x
    print(x,num)
    if num==0:
        return x
    else:
        x+=num%10
        digisum(int(num/10))
        return x

print(digisum(int(input("Enter number"))))