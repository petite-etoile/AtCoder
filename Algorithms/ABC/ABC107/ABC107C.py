#ans = min(b - a + min(abs(a), abs(b)) for a, b in zip(x, x[K-1:]))

N, K = map(int, input().split())
x = [int(i) for i in input().split()]
key = []
for left, right in zip(x, x[K - 1:]):
    key.append(right-left+min(abs(left), abs(right)))
print(min(key))
"""
N, K = map(int, input().split())
INF = 10**9
x_first = [-INF for i in range(K)]
x_ap = [int(i) for i in input().split()]
x_last = [INF for i in range(K)]
x = x_first + x_ap + x_last + [0]
x.sort()
zero_index = x.index(0)

key = []
for i in range(K+1):
    left = abs(x[zero_index - i])
    right = abs(x[zero_index - i + K])
    # left か rightの 0に近い方に行ってからもう片方にいく
    if left > right:
        right *= 2
    else:
        left *= 2
    key.append(left + right)
print(min(key))
"""
