
import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def INT_(n): return int(n)-1


def MI(): return map(int, input().split())


def MF(): return map(float, input().split())


def MI_(): return map(INT_, input().split())


def LI(): return list(MI())


def LI_(): return [int(x) - 1 for x in input().split()]


def LF(): return list(MF())


def LIN(n: int): return [input() for _ in range(n)]


def LLIN(n: int): return [LI() for _ in range(n)]


def LLIN_(n: int): return [LI_() for _ in range(n)]


def LLI(): return [list(map(int, l.split())) for l in input()]


def I(): return int(input())


def F(): return float(input())


def ST(): return input().replace('\n', '')


def main():
    from itertools import accumulate
    import heapq
    N, K = MI()
    V = LI()
    left_cum = [0]+list(accumulate(V))
    right_cum = [0] + list(accumulate(V[::-1]))

    minus_left = [[0]*N]
    minus_right = [[0]*N]
    now_minuses = [0]*N

    for i, v in enumerate(V):
        heapq.heappush(now_minuses, v)
        minus_left.append(list(now_minuses))

    now_minuses = [0]*N
    for i in range(N)[::-1]:
        heapq.heappush(now_minuses, V[i])
        minus_right.append(list(now_minuses))

    ans = 0
    for left in range(N+1):
        for right in range(N+1):
            if left + right > N or left + right > K:
                break
            ans_ = left_cum[left] + right_cum[right]
            l, r = list(minus_left[left]), list(minus_right[right])
            for i in range(K - right - left):
                if l[0] > r[0]:
                    pop_item = heapq.heappop(r)
                else:
                    pop_item = heapq.heappop(l)
                if pop_item >= 0:
                    break
                else:
                    ans_ -= pop_item

            ans = max(ans, ans_)
    print(ans)


if __name__ == '__main__':
    main()
