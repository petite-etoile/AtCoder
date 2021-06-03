n = int(input())
i=0
while (1<<i) <= n:
  ans = 1<<i
  i+=1
  
print(ans)