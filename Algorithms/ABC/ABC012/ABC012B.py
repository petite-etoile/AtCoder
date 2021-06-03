ss = int(input())
mm = ss // 60
ss %= 60
hh = mm // 60
mm %= 60
print("{:0=2}:{:0=2}:{:0=2}".format(hh, mm, ss))
