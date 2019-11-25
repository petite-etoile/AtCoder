def main():
    def is_ok(x:int):
        k=0
        for c in contintin:
            k+=c//(x+1)
            if k>K:
                return False
        return True

    def meguru_bisect(ok,ng):
        while abs(ok-ng)>1:
            mid = (ok+ng)//2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
    import sys
    input=sys.stdin.readline
    N, K, *A = map(int, open(0).read().split())
    contintin = []
    now = A[0]
    cnt = 0
    for a in A:
        if a == now:
            cnt+=1
        else:
            contintin.append(cnt)
            cnt=1
            now = a
    contintin.append(cnt)

    print(meguru_bisect(N,0))

if __name__ == '__main__':
    main()
    

"""def main():

    from bisect import bisect_left
    N, K, *A = map(int, open(0).read().split())
    contintin = []
    now = A[0]
    cnt = 0
    for i in range(N):
        if now != A[i]:
            contintin.append(cnt)
            cnt = 1
            now = A[i]
        else:
            cnt += 1
    contintin.append(cnt)

    # print(contintin)

    contintin.sort()
    pop = contintin.pop
    for i in range(K):
        mega_max = pop()
        if mega_max != 1:
            if mega_max % 2 == 0:
                mega_max //= 2
                contintin.insert(bisect_left(contintin, mega_max), mega_max)
                contintin.insert(bisect_left(
                    contintin, mega_max - 1), mega_max - 1)
            else:
                mega_max //= 2
                contintin.insert(bisect_left(contintin, mega_max), mega_max)
                contintin.insert(bisect_left(contintin, mega_max), mega_max)
        else:
            print(1)
            exit()
    print(contintin)
    print(pop())


if __name__ == '__main__':
    main()
"""