# ............ってなってる列がないとずっとどんどんしずんでいくので最後まで持たない!
def main():
    H, W = map(int, input().split())
    c = []
    exist_line = False
    for _ in range(H):
        c_i = input()
        c.append(c_i)
        if "#" not in c_i:
            exist_line = True
    searched = [[False for i in range(W)] for j in range(H)]
    if exist_line:
        def dfs(x, y):
            if (x, y) == (W - 1, H - 1):
                print("Yay!")
                exit()
            for i in range(0, 2):
                for j in range(0, 2):
                    if abs(i) == abs(j):
                        continue
                    if 0 <= x + i < W and 0 <= y + j < H:
                        if not searched[y + j][x + i] and c[y + j][x + i] == ".":
                            searched[y + j][x + i] = True
                            dfs(x + i, y + j)
        dfs(0, 0)
        print(":(")
    else:
        print(":(")


if __name__ == '__main__':
    main()
