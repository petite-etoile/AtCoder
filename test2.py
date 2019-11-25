def main():
    S = input()
    N = len(S)
    from collections import deque

    def solve(S):
        cur = deque([S[0]])
        ans1 = 1
        i = 1
        plus = 1
        while i < N:
            if i+plus > N:
                ans1 = -1
                break
            if S[i:i+plus] in cur:
                plus += 1
            else:
                cur.pop()
                cur.append(S[i:i+plus])
                i = i+plus
                plus = 1
                ans1 += 1

        cur = deque([S[:2]])
        ans2 = 1
        i = 2
        plus = 1
        while i < N:
            if i+plus > N:
                ans2 = -1
                break
            if S[i:i+plus] in cur:
                plus += 1
            else:
                cur.pop()
                cur.append(S[i:i+plus])
                i = i+plus
                plus = 1
                ans2 += 1
        return ans1, ans2
    ans1, ans2 = solve(S)
    ans3, ans4 = solve(S[::-1])
    print(max(ans1, ans2, ans3, ans4))


if __name__ == '__main__':
    main()
