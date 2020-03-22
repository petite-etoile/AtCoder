"""
iの直前で空のときに、Xi=Xj(i<j)であるようなjまで進むと、空になる
よってnext[i] = j
iの直前に空のときに、次にiの直前で空が回ってくるまでのidxの変化
jump[i] = ? * N or inf
もしjump[i] != infならできるだけこれを回したあとに、愚直にやるだけでよい
もしjump[i] == infならnext[i]に移動して、これを試す
どこかで周期ができるはずなので鳩ノ巣原理よりO(N)で見つかる
"""

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
    N,K=MI()
    A=LI()
    A *= 2 #2周分
    next_ = [-1]*2*N #次同じ数字が現れるidx
    last = defaultdict(lambda : -1) #各数字の現時点での最後尾
    for i,a in enumerate(A):
        if last[a] != -1:
            next_[last[a]] = i
        last[a] = i
    
    now = 0 #今のidx(mod N)
    accumulate_step = 0 #累計
    step_size = 0 #周期サイズ
    last_step = [-1]*2*N #そのidxに来たときのaccumulate_step
    #このwhileでは空の状態で進んでいく
    while accumulate_step + next_[now] - now  < N*K: #ぎりぎりまでnextやstep_sizeでたどる
        if last_step[now]!=-1: #周期があった!
            step_size = accumulate_step - last_step[now]
            remain = N*K - accumulate_step
            accumulate_step += remain//step_size * step_size
            now = accumulate_step%N
            if remain//step_size: #無限ループ回避
                continue
        
        #普通にnext_をたどって1個進む
        last_step[now] = accumulate_step
        before = now 
        now = next_[before] + 1
        accumulate_step += now - before 
        now %= N
    
    #残りはnaiveにやる
    remain = N*K-accumulate_step
    ans = []
    cnt = defaultdict(int)
    for a in A[2*N-remain:]:
        if not cnt[a]:
            ans.append(a)
            cnt[a] += 1
            continue
        while cnt[a]:
            cnt[ans.pop()] -= 1
    print(*ans)
if __name__ == '__main__':
    main()