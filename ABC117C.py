N, M = map(int, input().split())
X = [int(i) for i in input().split()]

X.sort()
difX = []
for i in range(len(X) - 1):
    difX.append(X[i + 1] - X[i])
difX.sort()
# print(difX[::-1])
if N > M:
    print("0")
else:
    print(sum(difX[:M - N]))
