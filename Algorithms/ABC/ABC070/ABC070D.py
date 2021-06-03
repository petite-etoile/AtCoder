#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
import sys
import heapq
input=sys.stdin.readline
inf=float('inf')
mod = 10**9+7
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [input() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')


def main():
    # ダイクストラ
    def dijkstra(start, edge):
        costs=[inf]*N
        costs[start]=0
        hash={}
        queue=[(0, start)]  # 第一要素が優先的に評価されるので
        while queue:
            c, v=heapq.heappop(queue)
            if v in hash:
                continue
            hash[v]=1
            costs[v]=c
            for node, cost in edge[v]:
                if node in hash:
                    continue
                heapq.heappush(queue, (c + cost, node))

        return costs
    N = I()
    #Kからdijkstra
    edge = [[] for _ in range(N)]
    for _ in range(N-1):
        a, b, c = MI_()
        c+=1
        edge[a].append((b, c))
        edge[b].append((a,c))
    
    Q, K = MI()
    
    cost = dijkstra(K-1, edge)
    for _ in range(Q):
        x, y = MI_()
        print(cost[x]+cost[y])

    
    
    
    
if __name__ == '__main__':
    main()