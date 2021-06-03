from collections import Counter
N = int(input())
v = [int(i) for i in input().split()]
v_even = [v[i] for i in range(len(v)) if i % 2 == 0]
v_odd = [v[i] for i in range(len(v)) if i % 2 == 1]

even_c = Counter(v_even)
odd_c = Counter(v_odd)
#print(odd_c.most_common(), even_c.most_common())

# most_commonも変数に格納するべき
if odd_c.most_common()[0][0] != even_c.most_common()[0][0]:  # 最頻値の値が違うなら
    output = N-(odd_c.most_common()[0][1] + even_c.most_common()[0][1])
elif N - (odd_c.most_common()[0][1] + even_c.most_common()[0][1]) == 0:  # すべてのvが同じ
    output = N // 2
else:
    if len(even_c) != even_c.most_common()[0][1]:
        frag1 = True
        output1 = N - (odd_c.most_common()[0][1] + even_c.most_common()[1][1])
    else:
        frag1 = False
    if len(odd_c) != odd_c.most_common()[0][1]:
        frag2 = True
        output2 = N - (odd_c.most_common()[1][1] + even_c.most_common()[0][1])
    else:
        frag2 = False
    if frag1 and frag2:
        output = min(output1, output2)
    elif frag1:
        output = output1
    elif frag2:
        output = output2
print(output)
