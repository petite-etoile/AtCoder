#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
import sys
from collections import defaultdict
input=sys.stdin.readline
def MI(): return map(int,input().split())
def ST(): return input().replace('\n', '')
def main():
    N,K=MI()
    S=ST()

    alphabet = [chr(i+ord("a")) for i in range(26)]
    remain_t = defaultdict(int) #Sの今見てる場所以降に現れる回数
    S_str_count = defaultdict(int) #Sに出てくる文字数
    for s in S:
        remain_t[s]+=1
        S_str_count[s]+=1

    def check(i,ans):
        dif_cnt = N #Sとansで違う文字数
        s_appear_cnt = defaultdict(int) #Sのi番目までで出てきた文字カウント
        ans_appear_cnt = defaultdict(int) #ansに出てきた文字カウント
        for a,s in zip(ans[:i+1],S):
            if a==s:
                dif_cnt -= 1
            s_appear_cnt[s] += 1
            ans_appear_cnt[a] += 1
        for c,cnt in S_str_count.items():
            dif_cnt -= min(cnt-ans_appear_cnt[c], cnt-s_appear_cnt[c]) #min(sでこれから出てくる回数, ansでこれから出てくる回数)だけ一致させることができる
        return dif_cnt<=K 


    ans = [""]*N
    for i,s in enumerate(S):
        for char in alphabet:
            if remain_t[char]:
                ans[i]=char 
                if check(i,ans): #i文字目をcharにできるならそれが最善
                    remain_t[char] -= 1
                    break

    print(*ans,sep="")



if __name__ == '__main__':
    main()