def countdown(num):
    print(num)
    if(num==1):
        return 0
    else:
        countdown(num-1)

countdown(int(input("Enter number")))
        
