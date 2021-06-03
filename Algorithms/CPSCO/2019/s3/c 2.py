#いもす法
from itertools import accumulate
N = int(input())
t_max = 10**6
time = [0]*(t_max+1)
for _ in range(N):
    s,t=map(int,input().split())
    time[s]+=1
    time[t]-=1
a = list(accumulate(time))

ans=0
prev=0
for i in range(t_max):
    if prev==0 and a[i]>0:
        ans+=1    
    prev = a[i]
print(ans)

"""N = int(input())
st=[]
for _ in range(N):
    st.append(list(map(int,input().split())))
st.sort(key=lambda x: x[0])

ans=1
end=st[0][1]
for i in range(1,N):
    if end<st[i][0]:
        ans+=1
        end=st[i][1]
    elif end < st[i][1]:
        end=st[i][1]
        
print(ans)
"""