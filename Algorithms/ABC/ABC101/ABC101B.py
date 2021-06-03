def digit_sum(a):
    sum = 0
    while a > 0:
        sum += a % 10
        a //= 10
    return sum


if __name__ == '__main__':
    N = int(input())
    if N % digit_sum(N) == 0:
        print("Yes")
    else:
        print("No")
