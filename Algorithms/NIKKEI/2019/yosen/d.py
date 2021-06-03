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

#Binary Indexed Tree (1-indexなので注意！！！！！！！！)
#Binary Indexed Tree (1-index！！！！！！！！)
class BinaryIndexedTree():
    def __init__(self, size):
        self.__node=[0]*(size+1)
        self.size = size


    def update_min(self, index, value):
        print("index",index)
        while index <= self.size:
            self.__node[index] = min(self.__node[index], value)
            print(index)
            index += index & -index


    #indexまでの最大値を返す
    def query_min(self, index):
        ret = inf
        while index > 0:
            ret = min(ret, self.__node[index])
            index -= index & -index
        return ret
        
        

    #0-indexでの添字を受け取って、1-indexでの添字での値を返す
    def get_node(self, index):
        return self.__node[index]

def main():
    N,M=MI()
    LRC = []
    for _ in range(M):
        l,r,c = MI_()
        c+=1
        LRC.append((l,r,c))

    #####単位元######
    ide_ele = inf

    #num:n以上の最小の2のべき乗
    num =2**(N-1).bit_length()
    seg=[ide_ele]*2*num
    init(inf)


    def init(init_val):
        #set_val
        for i in range(N):
            seg[i+num-1]=init_val[i]    
        #built
        for i in range(num-2,-1,-1) :
            seg[i]=min(seg[2*i+1],seg[2*i+2]) 
        
    def update(k,x):
        k += num-1
        seg[k] = x
        while k:
            k = (k-1)//2
            seg[k] = min(seg[k*2+1],seg[k*2+2])
        
    def query(p,q):
        if q<=p:
            return ide_ele
        p += num-1
        q += num-2
        res=ide_ele
        while q-p>1:
            if p&1 == 0:
                res = min(res,seg[p])
            if q&1 == 1:
                res = min(res,seg[q])
                q -= 1
            p = p//2
            q = (q-1)//2
        if p == q:
            res = min(res,seg[p])
        else:
            res = min(min(res,seg[p]),seg[q])
        return res






    now = 0
    # dp = [inf]*N
    # dp[0]=0
    LRC.sort()
    BIT = BinaryIndexedTree(N)
    BIT.update(0,0)
    for i,(l,r,c) in enumerate(LRC):
        mini = query(N-l)
        BIT.update(r, mini+c)
    
    print(BIT.query_min(1))

if __name__ == '__main__':
    main()