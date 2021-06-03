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
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep='\n')
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
    N,Q=MI()
    AB=LLIN(N)
    CD=LLIN(Q)

    removed_all = defaultdict(int)
    removed_school = [defaultdict(int)]*N

    pri_queue_all = []
    pri_queue_school = [[] for _ in range(N)]

    for i,(a,b) in enumerate(AB):
        AB[i][1]=b-1
        heappush(pri_queue_school[b-1], -a)
    
    for i in range(N):
        if(pri_queue_school[i]):
            heappush(pri_queue_all,-pri_queue_school[i][0])

    for c,to in CD:
        rate, from_ = AB[c-1]
        to-=1
        removed_school[from_][rate] += 1 #除籍メモ
        heappush(pri_queue_school[to],-rate) #移籍
        AB[c-1][0] = to
        best_changed = False
        print("{}の園児(rate:{})が{}へ".format(from_,rate,to))
        while(pri_queue_school[from_]):
            best = -pri_queue_school[from_][0] #優等生
            if(removed_school[from_][best]): #除籍済みなら
                heappop(pri_queue_school[from_]) #消す
                removed_school[from_][best]-=1 #消したよ

                if(not best_changed):
                    removed_all[best] += 1
                    if(pri_queue_school[from_]):
                        heappush(pri_queue_all, -pri_queue_school[from_][0])

                best_changed = True
            else:
                break
        
        while(removed_all[pri_queue_all[0]]):
            removed_all[pri_queue_all[0]] -= 1
            heappop(pri_queue_all)
        print(pri_queue_all)
        print("remove all",removed_all)
        print("ans",pri_queue_all[0])

if __name__ == '__main__':
    main()