
S = input()[::-1]


def DayDream(S):
    i = 0
    # print(S)
    while i < len(S):
        # print(S[i:i+7:1])

        if S[i:i+6] == "eraser"[::-1]:
            i += 6
        elif S[i:i + 5] == "erase"[::-1]:
            i += 5
        elif S[i:i+7] == "dreamer"[::-1]:
            i += 7
        elif S[i:i+5] == "dream"[::-1]:
            i += 5
        else:
            print("NO")
            return
    print("Yes")


DayDream(S)

"""
s = input()

n = s.replace('eraser', '').replace('erase', '').replace(
    'dreamer', '').replace('dream', '')

if not n:
    print('YES')
else:
    print('NO')
"""
