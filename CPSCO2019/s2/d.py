A,B=map(int,input().split())
A_even = A%2==0
B_even = B%2==0

if A_even and B_even:
    print("Yes")
elif not A_even and not B_even:
    print("No")
else:
    print("Yes")
