def main():
    N = 10**4
    A = []
    for i in range(1,10**6)[::2]:
        A.append(i)
        if len(A)==N:
            break
    print(N)
    print(*A)
if __name__ == '__main__':
    main()