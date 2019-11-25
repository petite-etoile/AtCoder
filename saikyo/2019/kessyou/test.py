v=0
for k in range(10):
    i=k+1
    print(str(v) + "+" + str(i) + "=" + str(v + 1))
    v = v + i
print("---")
print("合計="+str(v))