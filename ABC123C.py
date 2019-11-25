from math import ceil
N, *a = map(int, open(0).read().split())
cnt = []
for i in range(5):
    cnt.append(ceil(N / a[i]))
print(max(cnt)+4)


"""
from math import ceil
N = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
li = [a, b, c, d, e]
#exist = [N, 0, 0, 0, 0, 0]
cnt = []
for i in range(5):
    cnt.append(ceil(N / li[i]))
ans = cnt[0]
an = [cnt[0]]
for i in range(1, 5):
    mini = min([cnt[i]-(cnt[i-j]-j) for j in range(1, i+1)])
    ans += max(1, mini)
    an.append(max(1, mini))
    #ans += max(1, cnt[i] - (cnt[i - 1] - 1))
print(cnt)
print(an)
print(ans)
"""
