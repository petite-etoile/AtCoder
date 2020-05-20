import math
from decimal import Decimal, ROUND_HALF_UP
NEWS = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
        "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]
INF = 10**18
Wings = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8,
         17.1, 20.7, 24.4, 28.4, 32.6, INF]
Deg, Dis = map(int, input().split())
Deg /= 10
#Dis /= 60
#Dis = Decimal(str(Dis)).quantize(Decimal("0.1"), rounding=ROUND_HALF_UP)
Dis = math.floor((Dis/60)*10+0.5)/10
frag = False
for i in range(len(NEWS)):
    if Deg-(11.25+22.5 * i) < 0:
        Dir = NEWS[i]
        frag = True
        break
if not frag:
    Dir = NEWS[0]
for i in range(len(Wings)):
    if Dis <= Wings[i]:
        W = i
        break
if W == 0:
    Dir = "C"
print(Dir, W)
