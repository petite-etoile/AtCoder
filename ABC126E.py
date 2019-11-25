# UnionFind
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


N, M = map(int, input().split())
uf = UnionFind(N)
get_root, unite, nodes = uf.get_root, uf.unite, uf.nodes

for _ in range(M):
    x, y, _ = map(int, input().split())
    x -= 1
    y -= 1
    unite(x, y)
ans = 0
for i in range(N):
    if nodes[i] < 0:
        ans += 1
print(ans)
