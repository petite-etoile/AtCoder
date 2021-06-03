N, A, B = map(int, input().split())


def sumDigit(x):
    sum = 0
    while x >= 1:
        # print(x)
        sum += x % 10
        x = int(x/10)
    # print(sum)
    return sum


counter = 0
for n in range(1, N+1):
    if A <= sumDigit(n) <= B:
        counter += n
        # print(n)
print(counter)

"""
N,A,B = input().replace('\n','').split()
total = 0
for i in range(1,int(N)+1):
  sum = 0
  for j in range(len(str(i))):
    sum += int(str(i)[j])
  if int(A) <= sum <= int(B):
    total += i
print(total)
"""

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
    N,A,B = MI()
    ans = 0
    def digit_sum(n):
        l = list(str(n))
        s=0
        for i in l:
            a = int(i)
            s+=a
        return s

        
    for i in range(1, N + 1):
        if A <= digit_sum(i) <= B:
            ans += i
    print(ans)
if __name__ == '__main__':
    main()