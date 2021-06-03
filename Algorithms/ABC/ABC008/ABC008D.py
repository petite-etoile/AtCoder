def main():
    import sys
    input = sys.stdin.readline

    from itertools import permutations
    W, H = map(int, input().split())
    N = int(input())
    XY = [map(int, input().split()) for i in range(N)]

    for x_y_ in permutations(XY):
        cutx = []
        cuty = []
        ans = 0
        for x, y in x_y_:
            x_left = max([xx for xx in cutx if xx < x], 0)
            y_down = max(yy for yy in cuty if yy < y)
            x_right = min(xx for xx in cutx if xx > x)
            y_up = min(yy for yy in cuty if yy > y)
            ans_ = max(x_left, -W) + max(y_down, -H) + \
                min(y_up, H) + min(x_right, W)
        ans = max(ans, ans_)
    print(ans)


if __name__ == '__main__':
    main()
