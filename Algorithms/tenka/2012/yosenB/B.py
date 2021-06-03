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
def is_camel(S):
    if(S[0].isupper()):
        return False
    S=list(S)
    last = 0
    for i,s in enumerate(S):
        s=S[i]
        if(s.isupper()):
            S[i]=s.lower()
            if(S[last:i+1]):
                if(not is_word(S[last:i+1])):
                    return False
    if(not is_word(S[last:])):
        return False
    return True

def is_snake(S):
    T=S.split("_")
    for t in T:
        if(not t):
            return False
        if(t[0].isupper()):
            return False
        if(not is_word(t)):
            return False
    return True
def is_word(S):
    #_がない, 数字で始まらない, 小文字
    if(S.count("_")):
        return False
    if(not S):
        return False
    try:
        int(S[0])
        return False
    except:
        for s in S[1:]:
            if(s.isupper()):
                return False
        return True

def main():
    S=ST()
    N=len(S)
    if(not S.replace("_","")):
        print(S)
        return 
    l = 0
    r = N-1
    while(l<N and S[l]=="_"):
        l+=1
    while(l<r and S[r]=="_"):
        r-=1
    head = "_"*l
    tail = "_"*(N-r-1)
    S=S[l:r+1]
    N=len(S)
    ans = ""
    if(is_snake(S)):
        S = list(S)
        for i in range(N):
            if(S[i]=="_"):
                S[i+1]=S[i+1].upper()
            else:
                ans += S[i]
    else:
        if(is_camel(S)):
            for s in S:
                if(s.isupper()):
                    ans += "_"
                ans += s.lower()
        else:
            ans = S
    print(head+ans+tail)


    
    
if __name__ == '__main__':
    main()