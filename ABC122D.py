def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return 0


def ng(char1, char2, char3, new_char):
    if char2 == 0 and char3 == 1 and new_char == 2:
        return True
    if char2 == 0 and char3 == 2 and new_char == 1:
        return True
    if char2 == 1 and char3 == 0 and new_char == 2:
        return True
    if char1 == 0 and char2 == 1 and new_char == 2:
        return True
    if char1 == 0 and char3 == 1 and new_char == 2:
        return True
    return False


AGCT = ["A", "G", "C", "T"]
# ng=[[0,1,2],[0,2,1],[1,0,2],[0,1,?,2],[0,?,1,2]]


def main():
    modulo = 10**9+7
    N = int(input())
    dp = dp_table(N+1, 4, 4, 4)
    dp[0][3][3][3] = 1
    for i in range(N):
        for char_1 in range(4):
            for char_2 in range(4):
                for char_3 in range(4):
                    if dp[i][char_1][char_2][char_3] == 0:
                        continue
                    # (...char1,char2,char3)のあとにnewをつけた文字列が追加できるなら、
                    # (...char1,char2,char3)のバリエーション分だけ(バリエーションがある
                    for new in range(4):
                        if ng(char_1, char_2, char_3, new):
                            continue
                        else:
                            dp[i + 1][char_2][char_3][new] += dp[i][char_1][char_2][char_3]
                    dp[i + 1][char_2][char_3][new] %= modulo
    ans = 0
    for char_1 in range(4):
        for char_2 in range(4):
            for char_3 in range(4):
                ans += dp[N][char_1][char_2][char_3]
    # print(dp)
    print(ans % modulo)


if __name__ == '__main__':
    main()

"""AGCT = ["A", "G", "C", "T"]


def solve(dp, N: int, index: int = 0, AGC: bool = False, S: str = ""):
    if N == index:
        if AGC:
            print(S)
            return 1
        else:
            return 0
    elif dp[index][AGC] is not None and AGC:
        return dp[index][AGC]
    if AGC:
        print(index, S, pow(4, N-index))
        return pow(4, N-index)
    else:
        for_max = 4
        res = 0
        for i in range(for_max):

            if index == 1:
                AGC_ = False
            else:
                AGC_ = ((S[index-2:] + AGCT[i]) in ["AGC", "ACG", "GAC"])
                if index >= 3 and not AGC_:
                    AGC_ = ((S[index-3] + S[index-1] + AGCT[i] == "AGC")
                            or ((S[index - 3] + S[index - 2] == "AG") and AGCT[i] == "C"))
            #print(S, AGC, S+AGCT[i])
            res += solve(dp, N, index + 1, AGC_, S + AGCT[i])
        #print(res, S)
        dp[index][AGC] = res
        return res


def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return None


N = int(input())
four_pow_N = pow(4, N, 10 ** 9 + 7)
dp = dp_table(102, 2)
print(dp)
ans = solve(dp, N)
print(four_pow_N - ans)
"""
