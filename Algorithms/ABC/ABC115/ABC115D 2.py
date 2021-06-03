N, X = map(int, input().split())
x = X
nums = [1]
p_count = [1]
for i in range(N):
    nums.append(2 * nums[-1] + 3)
    p_count.append(2 * p_count[-1] + 1)


def solve_p(N, X):
    if X <= 0:
        return 0
    elif N == 0:
        return 1
    else:
        if X == (nums[N]+1) // 2:
            return (p_count[N]+1) // 2
        elif X < (nums[N]+1) // 2:
            return solve_p(N - 1, X - 1)
        else:
            #print("num", nums[N])
            return p_count[N-1]+1+solve_p(N-1, X-(nums[N]+1)//2)


print(solve_p(N, X))
"""
burger = ["P"]
for i in range(N):
    burger.append(("B"+burger[i]+"P"+burger[i]+"B"))
# print(burger)  # [N + 1])

# print(burger[N])

print(burger[N][:x].count("P"))
"""
