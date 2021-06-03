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
    H, W = MI()
    N = I()
    A = [(int(a),i) for i,a in enumerate(input().split(), start=1)]
    A.sort()

    stack = []
    for a,i in A:
        stack.extend([i] * a)

    ans = [[0] * W for _ in range(H)]
    for i in range(H):
        for j in range(W):
            c = stack.pop()
            if i % 2 == 0:
                ans[i][j] = c
            else:
                ans[i][W - 1 - j] = c
    for a in ans:
        print(*a)


    
if __name__ == '__main__':
    main()