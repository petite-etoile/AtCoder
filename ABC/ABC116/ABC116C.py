
N = int(input())
h = [int(i) for i in input().split()]

counter = min(h)
h = list(map(lambda x, y=min(h): x-y, h))
# print(min(h[1:3]))
while sum(h) > 0:
    start = False
    # print(h)
    for i in range(len(h)):
        if not start and h[i] > 0:
            start = True
            start_index = i
            continue
        elif start and h[i] == 0:
            start = False
            water = min(h[start_index:i])
            counter += water
            h = h[:start_index] + \
                list(map(lambda x, y=water: x - y, h[start_index:i])) + h[i:]
    if start:
        water = min(h[start_index:])
        counter += water
        h = h[:start_index] + \
            list(map(lambda x, y=water: x - y, h[start_index:]))
print(counter)

"""
N = int(input())
H = [0] + [int(a) for a in input().split()]
 
a = 0
for i in range(1, N+1):
    a += max(H[i]-H[i-1], 0)
 
print(a)  

"""
