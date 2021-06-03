import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def INT_(n): return int(n)-1


def MI(): return map(int, input().split())


def MF(): return map(float, input().split())


def MI_(): return map(INT_, input().split())


def LI(): return list(MI())


def LI_(): return [int(x) - 1 for x in input().split()]


def LF(): return list(MF())


def LIN(n: int): return [input() for _ in range(n)]


def LLIN(n: int): return [LI() for _ in range(n)]


def LLIN_(n: int): return [LI_() for _ in range(n)]


def LLI(): return [list(map(int, l.split())) for l in input()]


def I(): return int(input())


def F(): return float(input())


def ST(): return input().replace('\n', '')


def main():

    class WeightedUnionFind():
        def __init__(self, n):
            self.nodes = [-1 for _ in range(n)]
            self.weight = [0] * n

        def get_root(self, x):
            if self.nodes[x] < 0:
                return x
            else:
                y = self.get_root(self.nodes[x])
                self.weight[x] += self.weight[self.nodes[x]]
                self.nodes[x] = y
                return y

        def unite(self, x, y, w):
            w += self.weight[x]-self.weight[y]
            root_x = self.get_root(x)
            root_y = self.get_root(y)
            if root_x != root_y:
                # 大きい木の方につないだほうが計算量が減る
                if self.nodes[root_x] > self.nodes[root_y]:
                    root_x, root_y = root_y, root_x
                    w *= -1
                self.nodes[root_x] += self.nodes[root_y]
                self.nodes[root_y] = root_x
                self.weight[root_y] = w

        def diff(self, x, y):
            return self.weight[y] - self.weight[x]

        def same(self, x, y):
            return get_root(x) == get_root(y)
    N, M = MI()
    uf = WeightedUnionFind(N)
    get_root, unite, nodes, diff, same = uf.get_root, uf.unite, uf.nodes, uf.diff, uf.same
    for _ in range(M):
        l, r, d = MI_()
        d += 1
        if same(l, r) and diff(l, r) != d:
            print("No")
            exit()
        else:
            unite(l, r, d)
    print("Yes")


if __name__ == '__main__':
    main()
