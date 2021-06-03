from math import ceil
A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z = map(
    int, input().split())

print(A - B)
print(C+D)
print(max(F - E, 0))
print(ceil((G+H+I)/3 + 1))
a = ["", "a", "aa", "aaa", "aaai", "aaaji", "aabaji", "agabaji", "dagabaji"]
print(a[J])
for i in range(1, 10000):
    if i % 59 == K and i % 61 == L:
        n = i
        break
n += 59*61 * (M - 1)
perfect_num = [6, 28, 496, 8128, 33550336, 8589869056, 137438691328]
n_ = -1
for num in perfect_num:
    if abs(M - num) < N:
        n_ = num
        break
if n_ == -1:
    while 1:
        n += 1

a = [n_, n]
a.sort()
print(a[0])
print(a[1])
print((O+P+Q)*(R+S+T)*(U+V+W)*(X+Y+Z) % 9973)
