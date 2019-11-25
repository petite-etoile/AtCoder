N, A, B, C = map(int, input().split())
L = [int(input()) for i in range(N)]

# N<=8より4**8=65536通りしかないので全探索できる
INF = 10**9


def dfs(n_bamboo, a, b, c):
    if n_bamboo == N:
        if a != 0 and b != 0 and c != 0:
            # n個合成するとき、n-1回しか魔法は使わないのに"+10"をn回したから
            return abs(A - a) + abs(B - b) + abs(C - c) - 30
        else:
            return INF
    else:
        return1 = dfs(n_bamboo+1, a, b, c)
        return2 = dfs(n_bamboo+1, a + L[n_bamboo], b, c)+10
        return3 = dfs(n_bamboo+1, a, b+L[n_bamboo], c)+10
        return4 = dfs(n_bamboo+1, a, b, c+L[n_bamboo])+10
        return min([return1, return2, return3, return4])


print(dfs(0, 0, 0, 0))
