A, B, C, X, Y = map(int, input().split())
if A + B <= C * 2:
    ans = A * X + B * Y
else:
    ans = min(X, Y)*C*2
    if X < Y:
        if C * 2 < B:
            ans += (Y-X)*2*C
        else:
            ans += (Y - X) * B
    elif X > Y:
        if C * 2 < A:
            ans += (X-Y)*2*C
        else:
            ans += (X-Y)*A
    else:
        pass

print(ans)
