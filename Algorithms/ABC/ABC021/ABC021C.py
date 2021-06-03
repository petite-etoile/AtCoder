mod = (10**9) + 7


#mint
class ModInt:
    def __init__(self, x):
        self.x = x % mod
    
    def __str__(self):
        return str(self.x)
    
    __repr__ = __str__

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x)
        else:
            return ModInt(self.x + other)

    __radd__ = __add__
        
    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x)
        else:
            return ModInt(self.x - other)

    def __rsub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(other.x - self.x)
        else:
            return ModInt(other - self.x)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x)
        else:
            return ModInt(self.x * other)

    __rmul__ = __mul__

    def __truediv__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * pow(other.x, mod-2,mod))
        else:
            return ModInt(self.x * pow(other, mod - 2, mod))
            
    def __rtruediv(self, other):
        if isinstance(other, self):
            return ModInt(other * pow(self.x, mod - 2, mod))
        else:
            return ModInt(other.x * pow(self.x, mod - 2, mod))
            

    def __pow__(self, other):
        if isinstance(other, ModInt):
            return ModInt(pow(self.x, other.x, mod))
        else:
            return ModInt(pow(self.x, other, mod))
            

    def __rpow__(self, other):
        if isinstance(other, ModInt):
            return ModInt(pow(other.x, self.x, mod))
        else:
            return ModInt(pow(other, self.x, mod))

def main():
    N = int(input())
    a, b = (int(i)-1 for i in input().split())
    M = int(input())
    G = [[] for _ in range(N)]
    for i in range(M):
        x, y = (int(i)-1 for i in input().split())
        G[x].append(y)
        G[y].append(x)
    dist = [-1 for _ in range(N)]
    num = [ModInt(0) for _ in range(N)]

    from collections import deque

    def bfs(s):
        que = deque()
        dist[s] = 0
        num[s] = ModInt(1)
        que.append(s)
        while que:
            u = que.popleft()
            for v in G[u]:
                if dist[v] != -1:
                    if dist[v] == dist[u] + 1:
                        num[v] += num[u]
                    continue
                dist[v] = dist[u] + 1
                num[v] = num[u]
                que.append(v)
    bfs(a)
    print(num[b])


if __name__ == '__main__':
    main()
