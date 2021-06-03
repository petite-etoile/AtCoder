#bit全探索


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
def Inversion_number(A):
    N=len(A)
    B=sorted(set(A))
    BIT = BinaryIndexedTree(N)
    res = 0
    for i in range(N):
        idx = bisect_left(B,A[i])
        inverse = i - BIT.sum(idx+1)
        res += inverse
        BIT.add(idx+1,1)
    return res

def main():
    N=I()
    A=LI()
    B=LI()
    max_bit = 1<<N


        
    def check(mask): 
        """
        ビットが立ってるところは裏
        裏になるものは元いる位置から奇数移動
        表になるものは元いる位置から偶数移動
        """
        C=[0]*N
        for i in range(N):
            if (mask>>i&1):
                C[i] = B[i]
            else:
                C[i] = A[i]

        C.sort()
        dic = defaultdict(lambda : deque())
        for j,c in enumerate(C):
            dic[c,j&1].append(j)
        
        indexes = [0]*N
        for i in range(N):
            if (mask>>i&1):
                num,is_odd_idx = (B[i],i&1)
                if dic[num,is_odd_idx^1]:
                    idx = dic[num,is_odd_idx^1].popleft()
                else:
                    return inf
            else:
                num,is_odd_idx = A[i],i&1
                if dic[num,is_odd_idx]:
                    idx = dic[num,is_odd_idx].popleft()
                else:
                    return inf
            indexes[i] = idx

        return Inversion_number(indexes)


    ans = inf
    for mask in range(max_bit):
        res = check(mask)
        if res < ans:
            ans = res
    if ans == inf:
        print(-1)
    else:
        print(ans)

if __name__ == '__main__':
    main()