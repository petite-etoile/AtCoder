# 中央値が最適値(数直線で考える)
N = int(input())
A = [int(i) for i in input().split()]
for i in range(len(A)):
    A[i] -= i+1
A.sort()
b = A[N // 2]
print(sum([abs(a-b) for a in A]))

"""
嘘解法
# def decrement(a):
#    return a-1


N = int(input())
A = [int(i) for i in input().split()]
for i in range(len(A)):
    A[i] -= i+1
# print(A)
average_A = sum(A) / N
int_average = round(average_A)
#print(average_A, int_average)
"""
"""
print([a for a in A])  # if a > 0])
while len([a for a in A if a > 0]) > N // 2:
    A = list(map(decrement, A))
    print(A)
# print(A)
print(sum([abs(a) for a in A]))
"""
"""
ans = [sum(list(map(lambda x: abs(x-int_average+1), A)))
       for i in range(-100, 100)]
print(min(ans))
"""
