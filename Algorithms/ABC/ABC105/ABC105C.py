N = int(input())
i = 1
ans = [0 for i in range(1) if N == 0]
while N != 0:
    if N % (-2 ** i) == 0:
        ans.append(0)
    else:
        ans.append(1)
        N -= ((-2)**(i-1))
    i += 1
print("".join(map(str, ans))[::-1])

"""
N = bin(int(input()))
N_str = str(N)[:1:-1]+"0"  # 逆順
N_list = list(N_str)
print(N_list)
for i in range(len(N_list)+1):
    if i % 2 == 1:


        # 繰り上がり
        for j in range(i+1, len(N_list)):
            # N[j] += 1
            # print(type(N[j]))
            N_list[j] = str(int(N_list[j])+1)
            # N_str[j] = str(int(N[j])+1)
            if N_list[j] == "2":
                N_list[j] = "0"
                continue
            else:
                break

ans = "".join(N_list[::-1])
print(ans)
        """
