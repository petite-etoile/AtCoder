A, B = map(int, input().split())

# 0~B → b
# 0~A-1 → a
# A~B → c　とすると
# a^c = b
#c = a^b (両辺^a)
# 0から並べると、4個置きにXORの累積が0になる
B_ans = 0
for i in range(B % 4+1):
    B_ans = B_ans ^ (B - i)
    # print(bin(B-i))
A_ans = 0
for i in range((A - 1) % 4 + 1):
    # print(bin(A-i))
    A_ans = A_ans ^ (A-1 - i)
#print(A_ans, B_ans)
print(A_ans ^ B_ans)
"""
A, B = map(int, input().split())
A2 = A
ans = 0

n_product = B // A
if n_product >= 2:

    digit = 0
    while n_product > 0:
        n_product = n_product // 2
        digit += 1
    digit_A = 0
    while A2 > 0:
        A2 = A2 // 2
        digit_A += 1
    last = B & 2 ** 30-1 << digit_A
    before = B-last
    #print(digit, digit_A)
    print(" ", bin(123))
    print(bin(435))
    print(bin(before))
    print("A", bin(A))
    print(bin(last))
    print(bin(before + last))
    print("  ", bin(507-456))
    for i in range(abs(before-A) + 1):
        ans = A + i ^ ans
    print(" ", bin(ans))
    ans = ans ^ last
    print(bin(ans))
else:
    for i in range(B - A + 1):
        ans = A + i ^ ans

print(int(ans))
"""
