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
inf=float('inf')
mod = 10**9+7
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [input() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    from collections import deque
    K = I()
    edge = [[]for _ in range(K)]
    for i in range(K):
        edge[i].append((i * 10) % K)
        edge[i].append((i + 1)%K)
        
    zero_one_deque = deque([(1, 1)])
    node = [inf] * K
    #1から始めて、Kの倍数を見つける 01BFS
    node[1] = 1
    searched = set()
    while zero_one_deque:
        from_ , digit_sum = zero_one_deque.popleft()
        if from_ in searched:
            continue
        else:
            searched.add(from_)
            node[from_] = digit_sum
            
        for i, to in enumerate(edge[from_]):
            if i == 0:
                zero_one_deque.appendleft((to,node[from_]))
            else:   
                zero_one_deque.append((to, node[from_] + 1))
    print(node[0])
                    

if __name__ == '__main__':
    main()