import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def MI(): return map(int, input().split())


def LI_(): return [int(x) - 1 for x in input().split()]


def main():
    import sys
    sys.setrecursionlimit(5*(10**5))
    N, M = MI()
    edge = [[] for _ in range(N)]
    for _ in range(M):
        x, y = LI_()
        edge[x].append(y)

    def go_to_leaf(n):
        if dp[n] >= 0:
            return dp[n]
        ret = 0
        for y in edge[n]:
            ret = max(go_to_leaf(y) + 1, ret)
        dp[n] = ret
        return ret

    dp = [-1] * N
    ans = 0
    for i in range(N):
        ans = max(ans, go_to_leaf(i))
    print(ans)

    """start = 0
    while rev_edge[start]:
        start = rev_edge[start][0]
    stack = set([start])
    ans = 0
    for _ in range(N + 1):
        tmp = []
        print(stack)
        while stack:
            now = stack.pop()
            tmp.extend(edge[now])
        if not tmp:
            print(tmp)
            break
        stack = set(tmp)
        ans += 1
    print(ans)"""


if __name__ == '__main__':
    main()
