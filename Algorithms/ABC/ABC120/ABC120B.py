A, B, K = map(int, input().split())
count = 0
for i in reversed(range(1, min([A, B])+1)):
    if (A // i) * i == A and (B // i) * i == B:
        count += 1
        # print(i)
        if count == K:
            print(i)
