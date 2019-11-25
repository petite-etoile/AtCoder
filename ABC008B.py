N = int(input())
S = [input() for i in range(N)]
vote = []
count = []
for s in S:
    if s not in vote:
        vote.append(s)
        count.append(1)
    else:
        count[vote.index(s)] += 1
print(vote[count.index(max(count))])
