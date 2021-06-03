# 改善点 searchedを作らず、判定したやつはcostで上書きするといい
def search(y, x, cost):
    global gx
    global gy
    global searched
    global Queue
    if searched[y][x]:
        return
    else:
        if y == gy and x == gx:
            print(cost+1)
            exit()
        elif c[y][x] == ".":
            searched[y][x] = True
            Queue.append([y, x, cost + 1])


R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
sy -= 1
sx -= 1
gy -= 1
gx -= 1
c = []
for i in range(R):
    c.append(list(input()))


searched = [[False] * C for i in range(R)]
searched[sy][sx] == True
Queue = [[sy, sx, 0]]
cost = 0
while 1:
    for i in range(len(Queue)):
        q = Queue.pop(0)
        search(q[0] + 1, q[1], cost)
        search(q[0] - 1, q[1], cost)
        search(q[0], q[1]+1, cost)
        search(q[0], q[1]-1, cost)
    cost += 1
