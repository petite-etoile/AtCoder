"""N, K = map(int, input().split())
S = list(input())
K -= 1
if S[K] == "A":
    S[K] = "a"
elif S[K] == "B":
    S[K] = "b"
elif S[K] == "C":
    S[K] = "c"


print("".join(S))
"""

N, K = map(int, input().split())
S = list(input())
K -= 1
S[K] = chr(ord(S[K]) ^ 32)
print(*S, sep="")
