xa, ya, xb, yb, xc, yc = map(int, input().split())
ans = 1 / 2 * abs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc))
print(ans)
