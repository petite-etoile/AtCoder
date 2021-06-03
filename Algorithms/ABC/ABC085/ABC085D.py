def main():
    import sys
    from math import ceil
    input = sys.stdin.readline

    N, H = map(int, input().split())
    A = []
    B = []
    for i in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    a_max = max(A)
    B.sort(reverse=True)
    ans = 0
    for i in range(N):
        if a_max >= B[i]:
            break
        elif H > 0:
            ans += 1
            H -= B[i]
            continue
    if H > 0:
        ans += ceil(H / a_max)
    print(ans)


if __name__ == '__main__':
    main()
