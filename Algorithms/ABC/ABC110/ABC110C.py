
S = input()
T = input()
start = [-1] * 26
goal = [-1] * 26

for i in range(len(S)):
    start_index = ord(S[i]) - ord("a")
    goal_index = ord(T[i]) - ord("a")
    if start[start_index] != -1 or goal[goal_index] != -1:
        if start[start_index] != goal_index or goal[goal_index] != start_index:
            print("No")
            exit()
        else:
            continue
    start[start_index] = goal_index
    goal[goal_index] = start_index
print("Yes")
exit()
print(start, "\n", goal)


def transform_char(s):
    return chr(s+ord("a"))


print(list(map(transform_char, start)))
