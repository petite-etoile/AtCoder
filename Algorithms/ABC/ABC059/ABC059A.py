*S, = input().split()
trans = ord("A")-ord("a")
ans = chr(ord(S[0][0])+trans) + chr(ord(S[1][0])+trans) + chr(ord(S[2][0])+trans)
print(ans)