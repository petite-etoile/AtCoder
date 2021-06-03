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
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf=float('inf')
mod = 10**9+7
def main():
    N=int(input())
    S=input()[:-1]
    
    can = set([""]) ## 2文字以下で現在構築可能な文字列(最大10+10*10 = 1010)
    ans = set() ## 3文字で現在構築可能な文字列(最大10*10*10 = 1,000)
    for s in S: 
        for c in can.copy(): #途中でcanという集合に追加されるのでcopyする
            res = c+s #2文字以下 + 1文字 で結合する
            if len(res) == 3: #3文字なので暗証番号の候補
                ans.add(res)
            elif len(res) < 3: #2文字以下なのでcanに挿入
                can.add(res)
    print(len(ans))

    """
    copyする回数 = N * len(can) <= 10^3 * N
    for文の走査回数 = N * len(can) <= 10^3 * N
    
    全体で  2 * (10^3 * N)
    N<=3*10^4なので
    2*3* 10^3 * 10^4 = 6 * 10^7 -> 間に合わない？んですか・・・？
    """

if __name__ == '__main__':
    main()
