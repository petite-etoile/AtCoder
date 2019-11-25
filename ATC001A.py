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
    c = []
    for i in range(H):
        c_i = list(input())
        c.append(c_i)
        if "s" in c_i:
            y = i
            x = c_i.index("s")
    searched = [[False for i in range(W)] for j in range(H)]

    def push_neighbor(x, y, stack):
        if x < 0 or x >= W or y < 0 or y >= H:
            return
        elif searched[y][x]:
            return
        else:
            searched[y][x] = True
        if c[y][x] == ".":
            stack.append([x, y])
        elif c[y][x] == "g":
            print("Yes")
            exit()

    stack = [[x, y]]
    while stack:
        #print(x, y, stack)
        x, y = stack.pop()
        push_neighbor(x + 1, y, stack)
        push_neighbor(x - 1, y, stack)
        push_neighbor(x, y+1, stack)
        push_neighbor(x, y-1, stack)
    print("No")


if __name__ == '__main__':
    main()
