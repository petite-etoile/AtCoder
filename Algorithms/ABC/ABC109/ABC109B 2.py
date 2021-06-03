N = int(input())
w = []
for i in range(N):
    w.append(input())
last_char = w[0][0]
Rule = True
for word in w:
    if last_char == word[0]:
        last_char = word[-1]
        continue
    else:
        Rule = False
        break
if Rule and len(w) == len(set(w)):
    print("Yes")
else:
    print("No")
