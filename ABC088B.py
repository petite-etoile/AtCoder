N = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
print(sum(a[0::2])-sum(a[1::2]))


"""N = int(input())
a = [int(i) for i in input().split()]

AliceScore = 0
BobScore = 0

AliceTerm = True
while len(a) > 0:
    if AliceTerm:
        AliceScore += max(a)
    else:
        BobScore += max(a)
    AliceTerm = not AliceTerm
    a.remove(max(a))
print(AliceScore-BobScore)
"""
