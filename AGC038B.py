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
def main():
    #新メンバーが最大でないorいなくなったやつが最小でないなら、更新があった
    N,K = MI()
    P = LI()

    max_heap=[]
    min_heap=[]
    includes = set()
    for i in range(K):
        x = P[i]
        heappush(max_heap, -x)
        heappush(min_heap, x)
        includes.add(x)
    

    wrongs=deque()
    for i in range(N-1):
        if P[i]>P[i+1]:
            wrongs.append(i+0.5)
    
    including=deque()
    for w in deepcopy(wrongs):
        if w < K-1:
            including.append(wrongs.popleft())
        else:
            break

    zero_experiense = not including

    ans = 1
    #wrongなしを考慮
    for left in range(1,N-K+1):
        right=left+K-1
        last_mem = P[left-1]

        if including and including[0]<left:
            including.popleft()
        if wrongs and wrongs[0]<right:
            including.append(wrongs.popleft())

        includes.remove(last_mem)
        includes.add(P[right])

        while -max_heap[0] not in includes:
            heappop(max_heap)
        while min_heap[0] not in includes:
            heappop(min_heap)

        if last_mem < min_heap[0] and -max_heap[0] < P[right]:
            pass
        else:
            if not including:
                if zero_experiense:
                    pass
                else:
                    ans += 1
                    zero_experiense = True
            else:
                ans += 1
        heappush(min_heap, P[right])
        heappush(max_heap, -P[right])
    print(ans)

    


if __name__ == '__main__':
    main()

"""#
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
def main():
    #間違ってるところを区間に含む/この含んでいるのが違うなら、あれですよと
    N,K = MI()
    P = LI()
    wrongs=deque()
    including = deque()
    for i in range(N-1):
        if P[i]>P[i+1]:
            wrongs.append(i+0.5)
    including=deque()
    for w in deepcopy(wrongs):
        if w < K-1:
            including.append(wrongs.popleft())
        else:
            break
    ans = 1
    zero_experiense = not including
    #区間の最大より小さいものを新たに含む場合もだめですよと。
    incs = set()
    heap = []
    for i in range(K):
        heappush(heap,-P[i])
        incs.add(P[i])

    for left in range(1,N-K+1):
        incs.remove(P[left-1])
        while -heap[0] not in incs:
            heappop(heap)
        #メンバとheap最大は正しい最大になってる


        update = False
        if including and including[0]<left:
            update = True
            including.popleft()
        if wrongs and wrongs[0]<right:
            update = True
            including.append(wrongs.popleft())


        if update:
            if not including:
                if zero_experiense:
                    incs.add(P[right])
                    heappush(heap,-P[i])
                    continue

                else:
                    zero_experiense=True
            ans += 1
        else:
            maxim = -heap[0]
            if maxim>P[right] and including:
                ans +=1
        incs.add(P[right])
        heappush(heap, -P[right])

    print(ans)
        



if __name__ == '__main__':
    main()"""