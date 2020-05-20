N, K = map(int, input().split())
h = []
for i in range(N):
    h.append(int(input()))
h.sort()
tail = N - 1
minimumAnswer = h[tail]-h[0]
for i in range(N - K+1):
    if minimumAnswer > h[i+K-1]-h[i]:
        minimumAnswer = h[i+K-1]-h[i]
print(minimumAnswer)
