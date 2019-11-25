N, M = map(int, input().split())
# 隣接するマスの数が偶数→裏
# 隣接するマスの数が奇数→表
# 隣接するマスの数が偶数のマスの数が答え

# 2*2以上なら辺上にないマスが全てそう
if N == 1 and M == 1:
    print(1)
elif N == 1:
    print(M - 2)
elif M == 1:
    print(N - 2)
else:
    print(N*M - 2*N - 2*M + 4)
