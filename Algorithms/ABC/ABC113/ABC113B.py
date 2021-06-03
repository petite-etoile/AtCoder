N = int(input())
T, A = map(int, input().split())
H = [int(i) for i in input().split()]
c = 0.006


def solve_temp(h):
    return T-h*c


minimum = abs(A - solve_temp(H[0]))
minIndex = 0
for i in range(N):
    if minimum > abs(A - solve_temp(H[i])):
        minimum = abs(A - solve_temp(H[i]))
        minIndex = i
print(minIndex+1)

"""
N = int(input())
T, A = map(int, input().split())
H = list(map(int, input().split()))
X = [abs(A - (T-h*0.006))for h in H]
print(X.index(min(X)) + 1)
"""
