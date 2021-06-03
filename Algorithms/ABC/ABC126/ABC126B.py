S = input()
a = int(S[:2])
b = int(S[2:])
left = 1 <= a <= 12
right = 1 <= b <= 12
if left and right:
    print("AMBIGUOUS")
elif left:
    print("MMYY")
elif right:
    print("YYMM")
else:
    print("NA")
