cumsum_2d = [[0]*(N+1) for _ in range(N+1)]
    
    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] = d

    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] += cumsum_2d[i+1][j] + cumsum_2d[i][j+1] - cumsum_2d[i][j]
    
    for p,q in PQ:
        print(cumsum_2d[q][q]-cumsum_2d[p-1][q]-cumsum_2d[q][p-1]+cumsum_2d[p-1][p-1])