N = input()
ans = 0
odd = True
for n in reversed(N):
    if odd:
        ans += int(n)
    else:
        ans -= int(n)
    odd = not odd
print(ans % 11)
