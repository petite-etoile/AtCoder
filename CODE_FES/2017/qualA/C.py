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
from math import floor,ceil,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
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
    H,W = MI()
    cnt = [0]*26
    for _ in range(H):
        for s in ST():
            cnt[ord(s)-ord("a")] += 1
    
    cnt_cnt = defaultdict(int)
    for c in cnt:
        cnt_cnt[c%4] += 1


    #2個セットのは,2ペア集めると4の倍数個ある文字を採用することが出来るのでそれを考慮する

    if H%2==0 and W%2==0: #even even
        if cnt_cnt[0]==26:
            print("Yes")
        else:
            print("No")
    elif H&1 and W&1: #odd odd
        flag1 = (cnt_cnt[1]+cnt_cnt[3]==1)
        cnt_cnt[2]+=cnt_cnt[3] ## 3のやつは真ん中に一つと2個ペアに2つ使う
        flag2 = (cnt_cnt[2]%2==((H//2)+(W//2))%2 and cnt_cnt[2]<=(H//2)+(W//2))
        if flag2 and flag1:
            print("Yes")
        else:
            print("No")
    else: #others
        if cnt_cnt[1] or cnt_cnt[3]:
            print("No")
            return
        if H&1:
            if cnt_cnt[2]%2==(W//2)%2 and cnt_cnt[2]<=(W//2):
                print("Yes")
            else:
                print("No")
        else:
            if (cnt_cnt[2])%2==(H//2)%2 and (cnt_cnt[2])<=(H//2):
                print("Yes")
            else:

                print("No")


if __name__ == '__main__':
    main()