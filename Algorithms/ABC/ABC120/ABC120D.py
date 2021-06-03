from math import factorial


def combination(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return factorial(n)//(factorial(r) * factorial(n-r))


class UnionFind():
    def __init__(self, n):
        self.nodes = [-1] * n  # nodes[x]: 負なら、絶対値が木の要素数

    def get_root(self, x):
        # nodes[x]が負ならxが根
        if self.nodes[x] < 0:
            return x
        # 根に直接つなぎ直しつつ、親を再帰的に探す
        else:
            self.nodes[x] = self.get_root(self.nodes[x])
            return self.nodes[x]

    def unite(self, x, y):
        root_x = self.get_root(x)
        root_y = self.get_root(y)
        # 根が同じなら変わらない
        # if root_x == root_y:
        # pass
        if root_x != root_y:
            # 大きい木の方につないだほうが計算量が減る
            if self.nodes[root_x] < self.nodes[root_y]:
                big_root = root_x
                small_root = root_y
            else:
                small_root = root_x
                big_root = root_y
            self.nodes[big_root] += self.nodes[small_root]
            self.nodes[small_root] = big_root


def main():
    N, M = map(int, input().split())
    A, B = [], []
    for i in range(M):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    uf = UnionFind(N+1)
    get_root, unite, nodes = uf.get_root, uf.unite, uf.nodes
    uncomfort = (combination(N, 2))
    ans = [uncomfort]
    for i in reversed(range(M)):
        if get_root(A[i]) != get_root(B[i]):
            uncomfort -= abs(nodes[get_root(A[i])] * nodes[get_root(B[i])])
        ans.append(uncomfort)
        unite(A[i], B[i])
    # print(ans)
    print('\n'.join(map(str, ans[-2::-1])))


if __name__ == '__main__':
    main()

"""
AC
N, M = map(int, input().split())
A = []
B = []
parent = [-1 for i in range(N)]
size = [1 for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    A.append(a-1)
    B.append(b-1)


def root(i):
    if parent[i] < 0:
        return i
    parent[i] = root(parent[i])
    return parent[i]


uncomfort = N * (N - 1) // 2
ans = [uncomfort]
for i in reversed(range(1, M)):
    # print(size)
    # print(parent, A[i], B[i])
    if root(A[i]) != root(B[i]):
        comfort = size[root(A[i])] * size[root(B[i])]
        uncomfort -= comfort
        # print(size[root(A[i])], size[root(B[i])])
        if size[root(A[i])] > size[root(B[i])]:
            size[root(A[i])] += size[root(B[i])]
            parent[root(B[i])] = root(A[i])
        else:
            size[root(B[i])] += size[root(A[i])]
            parent[root(A[i])] = root(B[i])
    # print(uncomfort)
    ans.append(uncomfort)
# print(ans[::-1])
for answer in reversed(ans):
    print(answer)
"""

"""
import networkx as nx
N, M = map(int, input().split())
A = []
B = []

G = nx.Graph()
G.add_nodes_from(range(1, N+1))

for i in range(M):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
    G.add_edge(a, b)
for i in range(M):
    G.remove_edge(A[i], B[i])
    print(nx.shortest_path(G, source=1, target=2))
"""
