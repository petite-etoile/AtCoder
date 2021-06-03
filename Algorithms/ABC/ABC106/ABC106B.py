N = int(input())
odd_count = (N + 1) // 2
odds = [2*i+1 for i in range(odd_count)]
#print(odds, end=" ")
count = 0
for n in odds:
    divisor_count = 0
    for i in range(1, n + 1):
        if n % i == 0:
            divisor_count += 1
    if divisor_count == 8:
        count += 1
print(count)
