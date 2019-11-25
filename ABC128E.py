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
    import heapq
    N, Q = MI()
    event = []
    for _ in range(N):
        s, t, x = MI()
        event.append((s - x-0.5, 1, x))
        event.append((t - x-0.5, -1, x))

    for _ in range(Q):
        d = I()
        event.append((d, 0))

    # クエリも含めてソート
    event.sort(key=lambda x: x[0])

    # 工事現場が一番近いところを探すのにO(N)かけると死ぬのでlogNで調べることができるように優先度付きキューも使う
    occur = set()
    occur_priority = []

    for e in event:
        # 工事開始
        if e[1] == 1:
            occur.add(e[2])
            heapq.heappush(occur_priority, e[2])

        # 工事終了 occurはsetなので2回先に追加されたあとに2回削除ということを考慮
        elif e[1] == -1:
            if e[2] in occur:
                occur.remove(e[2])
            # heap木の要素の削除は遅いので、クエリのときに消す

        # クエリ
        elif e[1] == 0:
            if occur:
                while 1:
                    if occur_priority[0] in occur:
                        min_occur = occur_priority[0]
                        break
                    else:
                        heapq.heappop(occur_priority)
                print(min_occur)
            else:
                print(-1)


if __name__ == '__main__':
    main()
