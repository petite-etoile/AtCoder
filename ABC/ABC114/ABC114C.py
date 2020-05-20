N = int(input())
digit = len(str(N))
list753 = ["3", "5", "7"]  # string

for i in range(digit):
    for n in list753:
        if len(n) == i:
            list753.append(n + "7")
            list753.append(n + "5")
            list753.append(n + "3")

# print(list753)
counter = 0
for num in list753:
    if int(num) <= N and 0 not in [num.count("3"), num.count("5"), num.count("7")]:
        counter += 1
print(counter)
"""
TLE
N = int(input())
counter = 0
for i in range(357, N + 1):
    string = str(i)
    count3 = string.count("3")
    count5 = string.count("5")
    count7 = string.count("7")
    #print(i, count3, count5, count7)
    if count3 + count5 + count7 == len(string) and 0 not in [count3, count5, count7]:
        counter += 1

print(counter)

"""

# 357未満なら753数なし。
# 3桁の753数:3つの数の順列 3!
# 4桁の753数:4箇所から3箇所選ぶ　→　3!*(残りの場所の数を決める)
# ( 4C3 * (3! * (4-3)*7))
# 5桁の753数:5箇所から3箇所選ぶ → 3!*
# (5C3 * ( 3! * (7**(5-3) ) / (5-3)!)

"""
勘違いうんコード

def combination(n, m):
    return math.factorial(n)//(math.factorial(n-m)*math.factorial(m))


# Nの桁-1桁
m = int(math.log10(N))
# print(m)
# m-1桁までに存在する七五三数
sum_1 = 0
for i in range(3, m + 1):
    sum_1 += combination(i, 3) * 6 * (3 ** (i - 3)) // math.factorial(5 - 3)
print(sum_1)

# m桁でN以下の数の七五三数を足していくぅ

for i in range(10 ** (m), N + 1):
    s = str(i)
    if s.count("3") == 1 and s.count("5") == 1 and s.count("7") == 1:
        print(s)
        sum_1 += 1
print(sum_1)
"""
