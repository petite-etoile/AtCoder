import sys
input = sys.stdin.readline
def main():
    N=int(input())
    edge = [[]for _ in range(N)]
    for _ in range(N-1):
        u,v,w = map(int,input().split())
        u,v = u-1,v-1
        edge[u].append((v,w))
        edge[v].append((u,w))
    color = [-1]*N
    color[0]=0
    stack = [(0,0)]
    while stack:
        v,col = stack.pop()
        for to,dist in edge[v]:
            if color[to]!=-1:
                continue
            c = (col+dist)%2  # 色
            color[to] = c
            stack.append((to,c))
    print(*color,sep="\n")
            

if __name__ == '__main__':
    main()



"""def main():
    import sys
    from collections import deque
    input = sys.stdin.readline
    N = int(input())
    color = [-1] * N
    color[0] = 0
    uvw = []
    edge = [[]for _ in range(N)]
    # append=uvw.append
    for i in range(N-1):
        ui, vi, wi = map(int, input().split())
        ui -= 1
        vi -= 1
        edge[ui].append((vi, wi))
        edge[vi].append((ui, wi))
    stack = [0]
    for i in range(N):
        tmp = deque()
        while stack:
            i = stack.pop()
            for e, w in edge[i]:
                if color[e] == -1:
                    stack.append(e)
                    if color[i] == 0:
                        if w % 2 == 0:
                            color[e] = 0
                        else:
                            color[e] = 1
                    else:
                        if w % 2 == 0:
                            color[e] = 1
                        else:
                            color[e] = 0
                # ここを追加--------------------------------------
                # 矛盾判定
                else:
                    if (color[i] == color[e]) != (w % 2 == 0):
                        print(-1)
                        exit()
                # ^^^^^^^^--------------------------------------
        # print(color)
        stack = tmp
    print(*color, sep="\n")


if __name__ == '__main__':
    main()
"""