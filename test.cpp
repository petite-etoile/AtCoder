//写像12相 n個のボールk個の箱
//区別できるボール/区別できる箱/制限なし r^n
mint ball_1(int n,int r){
    return pow(n,r,MOD);
}
//区別できるボール/区別できる箱/1個以下 rPn 
mint ball_2(int n,int r){
    BigCombination B;
    mint res = B.permutation(r,n);
    return res;
}
//区別できるボール/区別できる箱/1個以上 包除原理
mint ball_3(int n,int r){
    BigCombination B;
    mint res = 0;
    for(int i=0;i<r;i++){
        mint x = B.combination(r,i) * pow((r-i), n, MOD);
        if (i&1) x *= -1;
        res += x;
    }
    return res;
}
//区別できないボール/区別できる箱/制限なし 仕切りをどこに入れるか選ぶ (n+r-1)C(n)
mint ball_4(int n,int r){
    BigCombination B;
    return B.combination(n+r-1,n);
}
//区別できないボール/区別できる箱/1個以下 rCn
mint ball_5(int n,int r){
    BigCombination B;
    return B.combination(r,n);
}
//区別できないボール/区別できる箱/1個以上 n-1Cr-1(しきりを玉の間に)
mint ball_6(int n,int r){
    BigCombination B;
    return B.combination(n-1,r-1);
}
//区別できるボール/区別できない箱/制限なし ベル数 = S(N,i)の和(0<=i<=r)
mint ball_7(int n,int r){
    vector<vector<mint>> S(n+1,vector<mint>(r+1,0)); //S[i][j]:=i人を区別されないj個のグループに分ける場合の数
    for(int i=0;i<=min(n,r);i++) S[i][i]=1;
    for(int i=0;i<=n;i++) S[i][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=r;j++){
            S[i][j] = S[i-1][j-1] + S[i-1][j] * j;
        }
    }
    mint res = 0;
    for(int j=0;j<=r;j++) res+=S[n][j];
    return res;
}
//区別できるボール/区別できない箱/1個以下
mint ball_8(int n,int r){
    return n<=r;
}
//区別できるボール/区別できない箱/1個以上 スターリング数 
mint ball_9(int n,int r){
    BigCombination B;
    mint res = 0;
    for(int i=0;i<r;i++){
        mint x = B.combination(r,i) * pow((r-i), n, MOD);
        if (i&1) x *= -1;
        res += x;
    }
    return res * B.inv[r]; //ball_3の 1/r!倍
}
//区別できないボール/区別できない箱/制限なし 分割数
mint ball_10(int n,int r){
    vector<vector<mint>> P(n+1,vector<mint>(r+1,0));
    REP(j,r+1) P[0][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            P[i][j] = P[i][j-1]; //0を含む
            if (i-j>=0) P[i][j] += P[i-j][j]; //0を含まない
        }
    }
    return P[n][r];
}
//区別できないボール/区別できない箱/1個以下
mint ball_11(int n,int r){
    return n<=r;
}
//区別できないボール/区別できない箱/1個以上 分割数
mint ball_12(int n,int r){
    if (n-r<0) return 0;
    return ball_10(n-r,r);
}