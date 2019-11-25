S=input()
cnt=[0]*26
for s in S:
    cnt[ord(s)-ord("a")]+=1
maxx=None
minn=None
for c in cnt:
    if c==0:
        continue
    else:
        if maxx is None:
            maxx=c
        else:
            maxx=max(c,maxx)
        if minn is None:
            minn=c
        else:
            minn=min(c,minn)
if minn==maxx:
    print("Yes")
else:
    print("No")