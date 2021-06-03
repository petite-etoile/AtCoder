N = int(input())
yen = []
for i in range(N):
    xi, ui = input().split()
    xi = float(xi)
    if ui == "BTC":
        ui = 380000
    else:
        ui = 1
    yen.append(xi*ui)
print(sum(yen))
