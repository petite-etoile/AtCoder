def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())

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

    uf = UnionFind(N)
    get_root, unite, nodes = uf.get_root, uf.unite, uf.nodes

    ABC = []
    for i in range(M):
        ABC.append(list(map(int, input().split()))+[i+1])
    ABC.sort(key=lambda x: x[2], reverse=True)

    ans = []
    for i in range(M):
        A = ABC[i][0]-1
        B = ABC[i][1]-1
        C = ABC[i][2]
        if get_root(A) != get_root(B):
            unite(A, B)
            ans.append(ABC[i][3])
            if -nodes[A] == N:
                break
    ans.sort()
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()
