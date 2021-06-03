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
    N = I()
    edge = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = MI_()
        edge[a].append(b)
        edge[b].append(a)

    set_A = set()
    set_B = set()
    a_stack = [0]
    b_stack = [N - 1]
    for _ in range(N - 1):
        tmp_a = []
        tmp_b = []
        while a_stack:
            from_ = a_stack.pop()
            for to in edge[from_]:
                if to not in set_A and to not in set_B:
                    tmp_a.append(to)
                    set_A.add(to)
        while b_stack:
            from_ = b_stack.pop()
            for to in edge[from_]:
                if to not in set_A and to not in set_B:
                    tmp_b.append(to)
                    set_B.add(to)
        a_stack = tmp_a
        b_stack = tmp_b
    if len(set_A) > len(set_B):
        print("Fennec")
    else:
        print("Snuke")


if __name__ == '__main__':
    main()