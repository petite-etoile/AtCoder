A , B , X = map(int , input().split())

N = [0]

for i in range(1 , 11):
    n = (X - (B*i)) // A
    if n > 0 and len(str(n)) == i :
        N.append(n)
    if i == 10 and n >= 10**9:
        N.append(10**9)
print(min(10**9,max(N)))
