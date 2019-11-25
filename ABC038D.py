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
from math import floor,ceil,sqrt,factorial,log #log2ないよ！
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

    N = I()
    MaxValue = 2**int(log((10**5), 2) + 1)
    WH = LLIN(N) 
    WH.sort(key=lambda x: x[0] * (10 ** 6) - x[1])
    
    BIT = BinaryIndexedTree(MaxValue)
    for i, (w, h) in enumerate(WH):
        #dp_i:=i番目の箱を用いてできる最大重の入れ子
        dp_i = BIT.query_max(h-1) + 1 #hより小さいもののdp[]の要素の最大値を拾ってくる
        BIT.update_max(h, dp_i)
    print(BIT.get_node(-1))

    

if __name__ == '__main__':
    main()