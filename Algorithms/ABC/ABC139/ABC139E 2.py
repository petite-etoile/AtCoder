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
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep="\n") if type(a)!=type("a") else print(a)
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    
    #この試合はこの試合のあとでないといけない、という条件がいくつもあるので
    #クリティカルパスを求めるイメージ(トポロジカルソート)
    #もしDAGでなければ無理なので-1

    N = I()
    A = LLIN_(N)
    matches = set()
    id = [[-inf]*N for _ in range(N)]
    cnt = 0
    for i,a in enumerate(A):
        for j,rival in enumerate(a):
            if i < rival:
                id[i][rival] = cnt
                cnt += 1

    edge = defaultdict(list)

    def to_ID(i,j):
        if i>j:
            i,j = j,i
        return id[i][j]

    for i,a in enumerate(A):
        for j,rival in enumerate(a[:-1]):
            match_id = to_ID(i,rival)
            next_rival = a[j+1]
            next_match_id = to_ID(i,next_rival)
            edge[match_id].append(next_match_id)


    dp = {}
    visited = set()
    caluculated = set()
    def dfs(match):
        #print("dfs",match,visited,sep="\n")
        if match in visited:
            #print(match,dp)
            if match in caluculated:
                return dp[match]
            else:
                print(-1)
                exit()
        visited.add(match)
        dp[match] = 1
        for next_match in edge[match]:
            #print("match,next",match,next_match)
            dp[match] = max(dfs(next_match)+1, dp[match])

        #print(match,dp[match])
        caluculated.add(match)
        return dp[match]

    ans = 0
    for match in range(cnt):
        res = dfs(match)
        #print(res)
        ans = max(ans,res)
    print(ans)




    """#O(試合数)
    N = I()
    A = []
    #消化した試合は削除していく
    for _ in range(N):
        *a, = reversed(LI_())
        A.append(a)
    #pprint("A",A)
    
    match = set()
    for i,a in enumerate(A):
        rival = a[-1]
        rival_of_rival = A[rival][-1]
        if rival_of_rival == i:
            match.add(i)
            match.add(rival)

    
    day = 0
    while match:
        day += 1
        last_match = set()
        last_match,match = match,last_match

        for i in last_match:
            A[i].pop()
        
        for i in last_match:
            if A[i]:
                rival = A[i][-1]
                rival_of_rival = A[rival][-1]
                if rival_of_rival == i:
                    match.add(i)
                    match.add(rival)
    for a in A:
        if a:
            print(-1)
            exit()

    print(day)"""

    """ O(N^3)
    N = I()
    A = LLIN_(N)
    indexes = [0] * N
    cnt = 0
    match = set()
    for i in range(N*N):
        update = False
        today_players = set()
        for k in range(N):
            index = indexes[k]
            if index >= N-1: #全試合done
                continue
            rival = A[k][index]
            if (k,rival) in match: #前回の希望相手との試合がまだ
                continue
            if (rival,k) in match :
                if not {k,rival} & today_players:
                    cnt += 1
                    update = True
                    match.remove((rival,k))
                    today_players.add(k)
                    today_players.add(rival)
                    indexes[k] += 1
                    indexes[rival] += 1
            else:
                match.add((k,rival))


            
        if not update:
            if cnt != (N*(N-1))//2:
                print(-1)
                exit()
            else:
                print(i)
                exit()"""

if __name__ == '__main__':
    main()



    
