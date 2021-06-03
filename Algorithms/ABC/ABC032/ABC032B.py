S = input()
k = int(input())
search_n = len(S) - k + 1
substring = []
for i in range(search_n):
    string = S[i:i + k]
    if string in substring:
        continue
    else:
        substring.append(string)
print(len(substring))
