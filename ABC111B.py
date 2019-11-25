# Nが3桁なのを理解してなかった
N = int(input())
zoro = []
for i in range(1, 4):
    for j in range(1, 10):
        string = str(j) * i
        zoro.append(string)
zoro.append("1111")
#   print(zoro)
candidate = [i for i in zoro if int(i) >= N]
print(candidate[0])

"""
#n以上の111の倍数
n = int(input())
i = int(n / 111)
if n % 111 != 0:
    i += 1
print(i * 111)
"""

"""
print((int(input())+110)//111*111)
"""
