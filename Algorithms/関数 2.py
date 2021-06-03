# Command+Shift+L 変数全選択
# Command+D 変数１こずつ選択
 # VSCode command+Jでターミナルと行き来

# TLEしたら累積和！二分探索！
# わからなくなったら後ろ(完成図)から逆に考えてみる(最後の1手は？など)
# EOFの入力は control+d
# joinより print(*list,sep="\n")
# すべての数との差とか、数に対してどう値を取ると最小になるか→数直線とかで書いてみるとわかるかも
# 数え上げで詰まったら、余事象考えてみる
# シミュレーションをして最終的にどうなるかって言う問題では、単調増加になってるものがあれば二分探索できるし、後ろから考えてDPできそうだったりもする
# XOR  0~NのXORは周期4で下２桁がア
# GCD系 一つの約数について全探索
# 答え決め打ち二分探索

l = [i for i in range(10) if i % 2 == 0]
l = = [i if i % 2 == 0 else "odd" for i in range(10)]
print("even" if True else "odd")
for i, v in enumerate(list):
    pass

math:
    ceil: 天井
    # 切り上げ
    (分子+分母-1)//分母+分母

    floor: 床
        ex) xの四捨五入(小数第一位に丸める)
        math.floor(x * 10 + 0.5) / 10
    factorial(n, r): n個からr個選ぶときの組み合わせ
fractions:
    gcd: 最大公約数(最小公倍数はlcmと名付ける)
fanctools:
    reduce(function, sequence): 順番に適用して
        ex) reduce(gcd, list)でlistの最大公約数
collections:
    Counter: 要素の出現回数カウント
    from collections import Counter
    c = Counter(a)
    for i, j in c.items():
        pass
    
    deque: 両端でappend,popがO(1)でできる
    append, appendleft, pop, popleft
    
    defaultdict:
    d=defaultdict(int)


bisect:
    bisect_left(list,): 二分探索(その値がリストに入るとしたら)
decimal:
    Decimal: Decimal型にcast
    ROUND_HALF_UP: 四捨五入 を指定
        ex) numを小数第一位に丸める
            Decimal(str(num)).quantize(Decimal("0.1"), rounding=ROUND_HALF_UP)

    Decimal(str(Dis)).quantize(Decimal("0.1"), rounding=ROUND_HALF_UP)

    d={"L": (-1, 0), "R": (1, 0), "U": (0, 1), "D": (0, -1)}



組み込み関数
    int.bit_length(): "2進数で表すとき何bit必要か"
    ord: 文字のUnicodeコードポイントを表す整数を返す
    chr: ordの逆
    # 大文字→小文字
    "sadasdaa".lower()
    "ASDsfasdaD".upper()
    # 大文字と小文字を入れ替える
    chr(ord(s) ^ 32)


ライブラリ
# めぐる式二分探索
def meguru_bisect(ok, ng):
    while abs(ok - ng) > 1:
        mid=(ok + ng) // 2
        if is_ok(mid):
            ok=mid
        else:
            ng=mid
    return ok


def is_right(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]) < 0

# ヒープ木(priority queue)
import heapq

# max version
def heappush_max(heap, item):
    heap.append(item)
    heapq._siftdown_max(heap, 0, len(heap) - 1)


def heappop_max(heap):
    lastelt=heap.pop()
    if heap:
        return_item=heap[0]
        heap[0]=lastelt
        heapq._siftup_max(heap, 0)
        return return_item
    return lastelt
heapq.heappop(heap)
heapq.heappush(heap, item)



# 法が 3 以上の素数のとき、2 で割るのは以下のように実装できる
if a % 2 == 1:
    a += MOD
a /= 2
"""
○○した結果のmod 10**9+7を計算するとき

加法・減法・乗法：途中でmodとりながらで大丈夫
a%b=a*(b_inverse)
"""
def inverse_mod(a, m):  # mod mでのaの逆元
    b=m
    u=1
    v=0
    while b:
        t=a // b
        a -= t * b
        a, b=b, a
        u -= t * v
        u, v=v, u
    u %= m
    return u

# 2進数表記でリストに
list(str(bin(N))[2:])

# 条件を満たす要素の数
n=sum(a < N for a in A)

# 約数列挙
def find_divisor(n):
    divisors=[]
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)
                divisors.append(n // i)
    return divisors


# 素因数分解
def prime_factorization(n):
    fact=[]
    for i in range(2, int(sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            fact.append(i)
    return fact


# bitDP ABC041D
N=int(input())
bit_max=1 << N
dp=[0] * bit_max
dp[0]=1  # 空集合の数(もちろん{}のみなので1)
for bit_set in range(bit_max):
    for rabbit_num in range(N):
        rabbit_bit=1 << rabbit_num
        if bit_set & rabbit_bit:
            # dp[bitset-rabbitbit]:bitsetの組み合わせからrabbit_num匹目のうさぎを除いたやつらの並び方の数
            dp[bit_set] += dp[bit_set - rabbit_bit]
print(dp)


# 桁DP  ABC007D
def solve(dp, N: str, index: int=0, tight: bool=True):
    if len(N) == index:
        return something
    elif dp[index][tight] is not None:
        return dp[index][tight]
    else:
        if tight:
            for_max=int(N[index])+1
        else:
            for_max=10
        return_=0
        for i in range(for_max):
            return_ += solve(dp, N, index + 1, tight and i ==
                             int(N[index]))
        dp[index][tight]=return_
        return return_



# combination,permutation
from math import factorial
# combination使うときは、数が大きすぎないか、何度も同じもの呼び出すか
# なんといっても、rの部分が決まっているならば、n*(n-1)//2で良いからな！！！

def combination(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return factorial(n)//(factorial(r) * factorial(n-r))


def permutation(n, r):  # n個からr個選び、それの並べ方
    if n < r:
        return 0
    else:
        return factorial(n) // factorial(n-r)

# combination permutaion 列挙
import itertools
>> > list(itertools.permutations([1, 2, 3]))  # 3! 通り
# [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

# 重複ありcombinationとおなじではない
>> > list(itertools.product([1, 2, 3], repeat   =2))  # 3**2 通り
# [(1, 1), (1, 2), (1, 3), (2, 1), (2, 2),(2, 3), (3, 1), (3, 2), (3, 3)]

# combination
>> > list(itertools.combinations([1, 2, 3, 4], 2))  # 4C2 通り
# [(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]


# 重複ありcombination つまり１を2回使ってもいい
>> > list(itertools.combinations_with_replacement([1, 2, 3], 3))  # 3H3個
[(1, 1, 1), (1, 1, 2), (1, 1, 3), (1, 2, 2), (1, 2, 3),
    (1, 3, 3), (2, 2, 2), (2, 2, 3), (2, 3, 3), (3, 3, 3)]

# anagram_list = [''.join(v) for v in itertools.permutations(s)]
# ['arc', 'acr', 'rac', 'rca', 'car', 'cra']

# 深さ優先探索 ATC001A
stack
stack.pop(): リストの最後の要素を取り出す
stack.append(): リストの最後に追加

def dfs(x, y):
    # なにか
    for i in range(-1, 2):
        for j in range(-1, 2):
            if abs(i) == abs(j):
                continue
            if 0 <= x + i < W and 0 <= y + j < H:
                if not searched[y + j][x + i] and c[y + j][x + i] == ".":
                    searched[y + j][x + i]=True
                    dfs(x + i, y + j)

# 幅優先探索 ABC007C
FIFO 先入れ先出し
list.pop(0): リストの最初の要素を取り出す
list.append(): リストの最後に追加

from collections import deque

stack=[0]
for i in range(N):
    tmp=deque()
    while stack:
        i=stack.pop()
        for e, w in edge[i]:
            pass
    stack=tmp


from collections import deque
H, W=map(int, input().split())
grid=[["#"] * (W + 2)] + [list("#" + input() + "#")
                            for i in range(H)] + [["#"]*(W+2)]

for i in range(h * w + 3):
    tmp=deque()
    while stack:
        h, w=stack.pop()
        for dh, dw in ([0, 1], [0, -1], [1, 0], [-1, 0]):
            if grid[h + dh][w + dw] == ".":
                grid[h + dh][w + dw]="#"
                tmp.append([h + dh, w + dw])
    stack=tmp
    if not stack:
        print(i)
        break

# 探索済か確認
arg_hash={}
if (x + 1, y, z) not in arg_hash and x + 1 < X:
    a.append()
    arg_hash[(x+1, y, z)]=1

# 最大増加部分列
from bisect import bisect_left
c=[int(input()) for i in range(N)]
LIS=[c[0]]  # Longest Increasing Subsequence
for i in range(1, N):
    # LISの最後の要素よりc[i]が大きいならc[i]を最後に付けて、一つ大きい部分列になる
    if c[i] > dp[-1]:
        LIS.append(c[i])
    # そうじゃないなら、c[i]より大きいのと小さいのの間のところにいれる(大きいのを上書き)
    else:
        LIS[bisect_left(LIS, c[i])]=c[i]
# LISの長さが最大増加部分列の長さ

#最大共通部分列LCS
S=ST()
T=ST()
dp=[[0]*(len(T)+1) for _ in range(len(S)+1)]
for i,s in enumerate(S):
    for j,t in enumerate(T):
        if s==t:
            dp[i+1][j+1] = dp[i][j]+1
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1], dp[i+1][j])
print(dp[-1][-1])

##################################################################
# グラフ
# 隣接リスト
edge=[[]for _ in range(N)]
    for i in range(M):
        abc=MI_()
        c+=1
        edge[a].append((b, c))
        edge[b].append((a, c))

# ワーシャルフロイド
def warshall_floyd(d, N):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j]=min(d[i][j], d[i][k] + d[k][j])


d=[[float("inf")] * N for i in range(N)]
for i in range(N):
    d[i][i] = 0
#-------辺入力------
warshall_floyd(d, N)

# ダイクストラ
def dijkstra(start, edge):
    costs=[inf]*N
    costs[start]=0
    hash={}
    queue = [(0, start, start)]  # 第一要素が優先的に評価されるので 第３要素にpre(前の頂点)が入る
    pre_node = [-1]*N
    while queue:
        c, from_ ,pre=heappop(queue)
        if from_ in hash:
            continue
        hash[from_] = 1
        print(from_,costs)
        costs[from_]=c
        pre_node[from_]=pre
        for cost,node in edge[from_]:
            if node in hash:
                continue
            heappush(queue, (c + cost, node, from_))

    return costs, pre_node


# ベルマンフォード
edge = []
for _ in range(M):
    a, b, c = MI_()
    c += 1
    edge.append((a, b, -c))

#edgeは1次元ですべて(始点,終点,重み)を格納
def bellmanford(edge):
    costs = [inf] * N
    costs[0] = 0
    exist_minus_cycle = False
    for i in range(N):
        update = False
        for from_, to, cost in edge:
            cost_to = costs[from_] + cost
            if cost_to < costs[to]:
                update = True
                costs[to] = cost_to
                
        if not update:
            break
        elif i==N-1:
            exist_minus_cycle = True

    #どこで無限に更新されるか判定
    minus_cycle = set()
    if exist_minus_cycle:
        for i in range(N+1):
            for from_, to, cost in edge:
                cost_to = costs[from_] + cost
                if from_ in minus_cycle:
                    minus_cycle.add(to)
                if cost_to < costs[to]:
                    minus_cycle.add(from_)
                    minus_cycle.add(to)
                    costs[to] = cost_to
    return costs, minus_cycle

costs,minus_cycle = bellmanford(edge)

if N-1 in minus_cycle :
    print("inf")
else:
    print(-costs[-1])


#トポロジカルソート
N,M = MI()
edge = [[]for _ in range(N)]
indegree = [0]*N #入次数
for _ in range(M):
    a,b = MI()
    edge[a].append(b)
    indegree[b] += 1
#print(indegree)
#入次数が0の点からあれしていく
queue = deque() 
for i,x in enumerate(indegree):
    if not x:
        queue.append(i)

pop = queue.popleft
topological_index = [] #トポロジカルソート順
while queue:
    v = pop()
    topological_index.append(v)

    for to in edge[v]:
        indegree[to] -= 1
        if not indegree[to]:
            queue.append(to)
if tuple(1 for i in indegree if i!=0):
    print("loop")

print(*topological_index,sep="\n")



##################################################################


##################################################################
class BigCombination(object):

    def __init__(self, mod: int=10**9+7, max_n: int=10**6):
        fac, inv=[1], []
        fac_append, inv_append=fac.append, inv.append

        for i in range(1, max_n+1):
            fac_append(fac[-1] * i % mod)

        inv_append(pow(fac[-1], mod-2, mod))

        for i in range(max_n, 0, -1):
            inv_append(inv[-1] * i % mod)

        self.mod, self.factorial, self.inverse=mod, fac, inv[::-1]

    def get_combination(self, n, r):
        if n < r:
            return 0
        return self.factorial[n] * self.inverse[r] * self.inverse[n-r] % self.mod

    def get_permutation(self, n, r):
        if n < r:
            return 0
        return self.factorial[n] * self.inverse[n-r] % self.mod

##################################################################


# UnionFind
class UnionFind():
    def __init__(self, n):
        self.nodes=[-1] * n  # nodes[x]: 負なら、絶対値が木の要素数

    def get_root(self, x):
        # nodes[x]が負ならxが根
        if self.nodes[x] < 0:
            return x
        # 根に直接つなぎ直しつつ、親を再帰的に探す
        else:
            self.nodes[x]=self.get_root(self.nodes[x])
            return self.nodes[x]

    def unite(self, x, y):
        root_x=self.get_root(x)
        root_y=self.get_root(y)
        # 根が同じなら変わらない
        # if root_x == root_y:
        # pass
        if root_x != root_y:
            # 大きい木の方につないだほうが計算量が減る
            if self.nodes[root_x] < self.nodes[root_y]:
                big_root=root_x
                small_root=root_y
            else:
                small_root=root_x
                big_root=root_y
            self.nodes[big_root] += self.nodes[small_root]
            self.nodes[small_root]=big_root
uf=UnionFind(N)
get_root, unite, nodes=uf.get_root, uf.unite, uf.nodes

# 重み付きUnionFind
class WeightedUnionFind():
    def __init__(self, n):
        self.nodes=[-1 for _ in range(n)]
        self.weight=[0] * n

    def get_root(self, x):
        if self.nodes[x] < 0:
            return x
        else:
            y=self.get_root(self.nodes[x])
            self.weight[x] += self.weight[self.nodes[x]]
            self.nodes[x]=y
            return y

    def unite(self, x, y, w):
        w += self.weight[x]-self.weight[y]
        root_x=self.get_root(x)
        root_y=self.get_root(y)
        if root_x != root_y:
            # 大きい木の方につないだほうが計算量が減る
            if self.nodes[root_x] > self.nodes[root_y]:
                root_x, root_y=root_y, root_x
                w *= -1
            self.nodes[root_x] += self.nodes[root_y]
            self.nodes[root_y]=root_x
            self.weight[root_y]=w

    def diff(self, x, y):
        return self.weight[y] - self.weight[x]

    def same(self, x, y):
        return get_root(x) == get_root(y)

uf=WeightedUnionFind(N)
get_root, unite, nodes, diff, same=uf.get_root, uf.unite, uf.nodes, uf.diff, uf.same

########################################################################################

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

###########################################################################

#Binary Indexed Tree (1-indexなので注意！！！！！！！！)
class BinaryIndexedTree():
    def __init__(self, size):
        self.__node=[0]*(size+1)
        self.size = size

    #node[index]にvalueを足して、BITを更新
    def add(self, index, value):
        while index <= self.size:
            self.__node[index] += value
            index += index&-index    
    
    #indexまでの和を返す
    def sum(self, index):
        ret = 0 #零元・単位元
        while index > 0:
            ret += self.__node[index]
            index -= index&-index    
        return ret

    def update_max(self, index, value):
        while index <= self.size:
            self.__node[index] = max(self.__node[index], value)
            index += index & -index


    #indexまでの最大値を返す
    def query_max(self, index):
        ret = 0
        while index > 0:
            ret = max(ret, self.__node[index])
            index -= index & -index
        return ret
        
        

    #0-indexでの添字を受け取って、1-indexでの添字での値を返す
    def get_node(self, index):
        return self.__node[index]


#########################################################################
#フロー

class Dinitz:
    #edge := (to, capa, rev_index)

    def __init__(self, N):
        self.__N = N
        self.__Graph = [[] for _ in range(N)] #to, capa, rev_index
        self.__level = [0] * N
        self.__iter = [0]*N

    def add_edge(self, from_, to, capa):
        self.__Graph[from_].append([to, capa, len(self.__Graph[to])])
        self.__Graph[to].append([from_, 0, len(self.__Graph[from_])-1 ])
    
    def solve(self, source:int, target:int):
        self.__target = target
        flow = 0
        while self.leveling_bfs(source):
            self.__iter = [0] * self.__N
            while True:
                delta = self.dfs(source, inf)
                if not delta:
                    break
                flow += delta
        return flow


    def leveling_bfs(self, source: int) -> bool:
        self.__level = [-1] * self.__N
        self.__level[source] = 0
        queue = deque([source])

        pop = queue.popleft
        append = queue.append
        while queue:
            from_ = pop()
            for to, capa, _ in self.__Graph[from_]:
                if capa > 0 > self.__level[to]:
                    self.__level[to] = self.__level[from_] + 1
                    append(to)
        return self.__level[self.__target] != -1 #到達可能ならTrue

    def dfs(self, from_:int,  flow:int) ->int:
        if from_ == self.__target:
            return flow
        for i in range(self.__iter[from_], len(self.__Graph[from_])):
            self.__iter[from_] = i
            to, capa, rev = edge = self.__Graph[from_][i]
            if capa and self.__level[from_] < self.__level[to]:
                delta = self.dfs(to, min(flow,capa))
                if delta: #増加パス
                    edge[1] -= delta #capaをへらす
                    self.__Graph[to][rev][1] += delta #逆辺のcapaを増やす
                    return delta
        return 0
