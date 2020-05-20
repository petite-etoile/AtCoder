# まじでわからん
N = int(input())
xyh = []
for i in range(N):
    xyh.append(list(map(int, input().split())))
max_xyh = max(xyh, key=lambda x: x[2])  # hが一番大きいxyhの組み合わせを抽出
for Cx in range(101):
    for Cy in range(101):
        h = abs(max_xyh[0] - Cx) + abs(max_xyh[1] - Cy) + max_xyh[2]
        frag = True
        for ex_xyh in xyh:
            if max([h - abs(ex_xyh[0] - Cx) - abs(ex_xyh[1] - Cy), 0]) == ex_xyh[2]:
                continue
            else:
                frag = False
                break
        if frag:
            print(Cx, Cy, h)
            break
