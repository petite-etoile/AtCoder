def main():


if __name__ == '__main__':
    main()

"""def main():
    from collections import deque
    H, W = map(int, input().split())
    grid = [["#"] * (W + 2)] + [list("#" + input() + "#")
                                for i in range(H)] + [["#"]*(W+2)]
    # print(grid)
    stack = deque()
    for h in range(1, H+1):
        for w in range(1, W+1):
            # 黒ならスタックにpush
            if grid[h][w] == "#":
                stack.append([h, w])

    for i in range(h + w + 3):
        tmp = deque()
        while stack:
            h, w = stack.pop()
            for dh, dw in ([0, 1], [0, -1], [1, 0], [-1, 0]):
                if grid[h + dh][w + dw] == ".":
                    grid[h + dh][w + dw] = "#"
                    tmp.append([h + dh, w + dw])
        stack = tmp
        if not stack:
            print(i)
            break


if __name__ == '__main__':
    main()
"""
