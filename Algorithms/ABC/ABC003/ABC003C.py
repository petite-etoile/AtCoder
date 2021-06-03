N, K = map(int, input().split())
R = [int(i) for i in input().split()]
R.sort()
# 見れないのはN-K人
watch = R[N - K:]
# print(watch)
ans = 0
for w in watch:
    ans = (ans + w) / 2
print(ans)
