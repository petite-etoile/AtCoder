N = int(input())
money=0
plus=[]
dot=[]
for i in range(N):
    ci,ai=input().split()
    ai=int(ai)
    app=0
    if ci=="+":
        plus.append(ai)
    elif ci=="-":
        continue
    else:
        if ai!=0:
            dot.append(ai)

for a in plus:
    money+=a
for a in dot:
    money*=a
print(money)