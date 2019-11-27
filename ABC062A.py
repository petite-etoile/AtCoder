x,y = map(int,input().split())
dic = {
    1:1,3:1,5:1,7:1,8:1,10:1,12:1,
    4:2,6:2,9:2,11:2,
    2:3
}
if dic[x]==dic[y]:
    print("Yes")
else:
    print("No")