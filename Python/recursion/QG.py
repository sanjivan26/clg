
def hanoi(n, A, B, C):
    if n == 1:
        print("Move disc 1 from",A,"to",B)
    else:
        hanoi(n-1, A, C, B)
        print("Move disc",n,"from",A,"to",B)
        hanoi(n-1, C, B, A)
n = int(input("Enter the number of discs "))
hanoi(n, "A", "C", "B")