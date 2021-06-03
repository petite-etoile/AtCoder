import heapq


def heappush_max(heap, item):
    heap.append(item)
    heapq._siftdown_max(heap, 0, len(heap) - 1)


def heappop_max(heap):
    lastelt = heap.pop()
    if heap:
        return_item = heap[0]
        heap[0] = lastelt
        heapq._siftup_max(heap, 0)
        return return_item
    return lastelt


X, Y, Z, K = map(int, input().split())
A = sorted([int(i) for i in input().split()], reverse=True)
B = sorted([int(i) for i in input().split()], reverse=True)
C = sorted([int(i) for i in input().split()], reverse=True)
ans = []
heap_queue = [(A[0]+B[0]+C[0], 0, 0, 0)]
arg_hash = {}

for i in range(K):
    maxim, a, b, c = heappop_max(heap_queue)
    print(maxim)
    arg_a = (a+1, b, c)
    arg_b = (a, b + 1, c)
    arg_c = (a, b, c + 1)

    if a + 1 < X and arg_a not in arg_hash:
        heappush_max(heap_queue, (A[a + 1] + B[b] + C[c], a + 1, b, c))
        arg_hash[arg_a] = 1
    if b + 1 < Y and arg_b not in arg_hash:
        heappush_max(heap_queue, (A[a] + B[b+1] + C[c], a, b+1, c))
        arg_hash[arg_b] = 1
    if c + 1 < Z and arg_c not in arg_hash:
        heappush_max(heap_queue, (A[a] + B[b] + C[c+1], a, b, c+1))
        arg_hash[arg_c] = 1


"""
AC
def main():
    X, Y, Z, K = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    AB = []
    ABappend = AB.append
    for i in range(X):
        for j in range(Y):
            ABappend(A[i] + B[j])
    AB.sort(reverse=True)
    ABC = []
    ABCappend = ABC.append
    for i in range(min(K, X*Y)):
        for j in range(Z):
            ABCappend(AB[i] + C[j])
    ABC.sort(reverse=True)
    print(*ABC[:K], sep="\n")


if __name__ == '__main__':
    main()
"""


"""def solve_ans(As, B, C, X, K):
    ret = 0
    for b in range(len(B)):
        for c in range(len(C)):
            ret += len(As)-meguru_bisect2(len(As), 0, B[b], C[c], X)
    return ret >= K


def solve(x, B, C, X):
    return x+B+C >= X


def meguru_bisect(ok, ng, A, B, C, K):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve_ans(A, B, C, mid, K):
            ok = mid
        else:
            ng = mid
    return ok


def meguru_bisect2(ok, ng, B, C, X):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid, B, C, X):
            ok = mid
        else:
            ng = mid
    return ok


def main():

    X, Y, Z, K = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]
    maxim = max(X, Y, Z)
    if maxim == X:
        A.sort()
        n = meguru_bisect(X, 0, A, B, C, K)
    elif maxim == Y:
        B.sort()
        n = meguru_bisect(X, 0, B, A, C, K)
    else:
        C.sort()
        n = meguru_bisect(X, 0, C, B, A, K)
    print(n)

    # ans.append()
if __name__ == '__main__':
    main()
"""
