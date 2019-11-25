l = [123,271,327,371,346,256,302,389,381,359,284,213,360,399,171,350,130,251,388,250,223,324,339,190]
N=len(l)
bit_max = 1<<N
for bit in range(bit_max):  
    res=0
    for i in range(N):
        if (1<<i)&bit:
            res+=l[i]
    if res==1000:
        for i in range(N):
            if (1<<i)&bit:
                print(l[i])
        print()