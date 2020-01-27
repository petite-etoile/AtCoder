"""
# 再帰で書いてみる(再帰関数が深くなりすぎて「スタックオーバーフロー」に陥る)
H, W = map(int, input().split())
c = []
for i in range(H):
    c_i = list(input())
    c.append(c_i)
    if "s" in c_i:
        y = i
        x = c_i.index("s")
        # print("a")
searched = [[False for i in range(W)]for j in range(H)]


def search(x, y):
    if x < 0 or x >= W or y < 0 or y >= H:
        return
    if c[y][x] == "g":
        print("Yes")
        exit()
    if searched[y][x]:
        return
    else:
        searched[y][x] = True
    if c[y][x] == "#":
        return
    else:
        search(x - 1, y)
        search(x + 1, y)
        search(x, y + 1)
        search(x, y - 1)


search(x, y)
print("No")
"""


def main():
    H, W = map(int, input().split())
    grid = [input() for _ in range(H)]
    start = ""
    for i in range(H):
        if "s" in grid[i]:
            w = grid[i].index("s")
            h = i
            start = (h,w)



    def is_inside(hw):
        h,w = hw
        return 0<=h<H and 0<=w<W

    visited = set()

    stack = [start]
    dxdy = [(1,0),(0,1),(-1,0),(0,-1)]
    while stack:
        h, w = stack.pop()
        if (h,w) in visited:
            continue
        visited.add((h,w))
        for dw,dh in dxdy:
            to = (h+dh, w+dw)
            if to in visited:
                continue
            if is_inside(to):
                if grid[to[0]][to[1]]=="#":
                    continue
                elif grid[to[0]][to[1]]==".":
                    stack.append(to)
                else:
                    print("Yes")
                    return


    print("No")


if __name__ == '__main__':
    main()
