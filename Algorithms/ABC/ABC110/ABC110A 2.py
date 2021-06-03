A, B, C = map(int, input().split())
list = sorted([A, B, C], reverse=True)
s1 = list[0]
s2 = list[1]
s3 = list[2]
print(s1*10+s2+s3)
