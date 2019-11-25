N = int(input())
t = [int(i) for i in input().split()]
v = [int(i) for i in input().split()]
t.insert(0, 0)
v.insert(0, 0)
v.append(0)
ans = 0
for i in range(1, N+1):
    if v[i] > v[i + 1]:  # 次が遅いときは気をつける
        # 加速中
        time_limit = t[i] - abs(v[i] - v[i - 1])
        # 時間があってゆっくりできるならゆっくりしてから
        if time_limit >= v[i] - v[i + 1]:
            ans += pow(v[i] - v[i - 1], 2) / 2
            print(pow(v[i] - v[i - 1], 2) / 2, "$")
            time_limit -= (v[i] - v[i + 1])
            print(pow(v[i] - v[i + 1], 2) / 2 +
                  v[i+1]*abs(v[i] - v[i + 1]), "a")
            ans += pow(v[i] - v[i + 1], 2) / 2 + v[i+1]*abs(v[i] - v[i + 1])
            print(time_limit*v[i], "b")
            ans += time_limit*v[i]
        elif time_limit >= abs(v[i - 1] - v[i + 1]):
            time_limit -= abs(v[i - 1] - v[i + 1])
            print(pow(v[i - 1] - v[i + 1], 2), "c")
            ans += pow(v[i - 1] - v[i + 1], 2)
            print(time_limit*time_limit, "d")
            ans += time_limit * time_limit
        else:
            # 途中
            ans += (pow(v[i - 1] - v[i + 1]))
        v[i] = v[i+1]
    else:
        time_limit = t[i] - abs(v[i] - v[i - 1])
        if time_limit >= 0:
            print(pow(v[i] - v[i - 1], 2) / 2 +
                  v[i - 1] * abs(v[i] - v[i - 1]), "e", i)
            ans += pow(v[i] - v[i - 1], 2) / 2 + \
                v[i - 1] * abs(v[i] - v[i - 1])
        else:
            print(pow(t[i], 2) / 2 + v[i-1]*t[i], "f")
            ans += pow(t[i], 2) / 2 + v[i-1]*t[i]
            v[i] = v[i - 1] + t[i]
            time_limit = 0
        # print(pow(v[i] - v[i - 1], 2) / 2 + v[i - 1] * abs(v[i] - v[i - 1]))
        print(time_limit * v[i], "g")
        ans += time_limit * v[i]
        # print(time_limit, v[i], time_limit * v[i])

# print(v[i] * v[i] / 2+time_limit * v[i])

print(ans)
