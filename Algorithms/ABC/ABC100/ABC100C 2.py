def solve(a):
    sum = 0
    while a % 2 == 0:
        a //= 2
        sum += 1
    return sum


N = int(input())
A = [int(i) for i in input().split()]
ans = [solve(a) for a in A]
print(sum(ans))
