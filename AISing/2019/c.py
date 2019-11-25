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
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
inf=float('inf')
mod = 10**9+7
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
    H, W = MI()
    S =[":"*(W+2)]  + [":"+ST()+":" for _ in range(H)] + [":"*(W+2)]

    checked = set()
    d = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    ans = 0
    for h in range(1, H + 1):
        for w in range(1, W + 1):
            if (h, w) in checked:
                continue
            queue = [(h,w)]
            black = 0
            white = 0
            while queue:
                from_h, from_w = queue.pop()
                if (from_h,from_w) in checked:
                    continue
                checked.add((from_h,from_w))
                if S[from_h][from_w] == "#":
                    black += 1
                else:
                    white += 1
                for dh, dw in d:
                    if S[from_h + dh][from_w + dw] != ":" and (from_h + dh, from_w + dw) not in checked and S[from_h + dh][from_w + dw] != S[from_h][from_w]:
                        queue.append((from_h + dh, from_w + dw))
            ans += black * white
    print(ans)
if __name__ == '__main__':
    main()