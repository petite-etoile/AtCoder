R,G,B,N=map(int,input().split())
cnt=0
for r in range(N//R+1):
    for g in range(N//G+1):
        if (N-r*R-g*G)<0:
            break
        elif (N-r*R-g*G)%B==0:
            cnt+=1

        
print(cnt)