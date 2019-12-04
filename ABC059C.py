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
#Binary Indexed Tree (1-index！！！！！！！！)
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
def main():
    N=I()
    A=LI()
    def solve(is_minus):
        B=BinaryIndexedTree(N)
        for i,a in enumerate(A,start=1):
            B.add(i,a)
        res = 0
        for i in range(1,N+1):
            s = B.sum(i)
            if is_minus:#累積和が負でないといけない
                if s>=0:#負じゃない
                    res += abs(s-(-1))
                    B.add(i,(-1-s))
            else:#累積和が負でないといけない
                if s<=0:#負じゃない
                    res += abs(s-1)
                    B.add(i,abs(s-1))
            is_minus ^= 1 #true/falseを反転
        return res

    ans = min(solve(True), solve(False)) ##ポケットモンスター 奇数から始める/偶数から始める
    print(ans)
if __name__ == '__main__':
    main()