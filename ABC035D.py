import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def mi(): return map(int, input().split())


def li(): return list(mi())


def li_(): return [int(x) - 1 for x in input().split()]


def lin(n: int): return [input() for _ in range(n)]


def llin(n: int): return [li() for _ in range(n)]


def llin_(n: int): return [li_() for _ in range(n)]


def lli(): return [list(map(int, l.split())) for l in input()]


def i(): return int(input())


def f(): return float(input())


def s(): return input().replace('\n', '')


def main():
    import heapq
    N, M, T = mi()
    A = li()
    edge1 = [[] for _ in range(N)]
    edge2 = [[] for _ in range(N)]
    for i in range(M):
        a, b, c = mi()
        a -= 1
        b -= 1
        edge1[a].append((b, c))
        edge2[b].append((a, c))

    def dijkstra(start, edge):
        costs = [inf]*N
        costs[start] = 0
        hash = {}
        queue = [(0, start)]  # 第一要素が優先的に評価されるので
        while queue:
            c, v = heapq.heappop(queue)
            if v in hash:
                continue
            hash[v] = 1
            costs[v] = c
            for node, cost in edge[v]:
                if node in hash:
                    continue
                heapq.heappush(queue, (c + cost, node))

        return costs
    length_go = dijkstra(0, edge1)
    length_back = dijkstra(0, edge2)
    ans = 0
    for i, (go, back) in enumerate(zip(length_go, length_back)):
        ans = max(ans, A[i] * (T - go - back))
    print(ans)


if __name__ == '__main__':
    main()
