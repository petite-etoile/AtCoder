//基本

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int n, int m)
{
    return n * (m / gcd(n, m));
}

//出力
cout << hex << 16; // 10 (16進数)
cout << dec <<  9; // 9  (10進数)
cout << oct <<  9; // 11 ( 8進数)
cout << bitset<桁数>(9); // 00001001 (2進数)

//std::vector
vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値));
vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2));  // 初期値を省略

//x以下最大の値を求める
auto it = upper_bound(vec.begin(),vec.end(),x); 
if(it!=vec.begin())  
    chmax(ans,s+*--it);

//std::queue
queue<int> q;
q.push(v);
v = q.front(); v.pop();

//std::deque
deque<int> q;
q.push_back(a); q.push_front(b);
q.pop_back(); q.pop_front();
it = q.rbegin(),begin()

//std::priority_queue
priority_queue<int,vector<int>,greater<int>> L; //昇順
priority_queue<int> R; //降順
v = L.top(); L.pop();
R.push(v);

//std::pair
pair<int,int> best(INF,-1);
best.first,best.second

//std::set
set<int> S;
S.insert(3); //add
S.find() != S.end()  //in判定  
auto it = s.find(1);
int val = *it; //値を出すときは*つける
auto left = s.lower_bound(l); auto right = s.upper_bound(r);
if(left!=right) //[l,r]の値がSetに入っている

//STL
swap(a,b);
sort(vec.begin(), vec.end(), greater<int>()a    );

reverse(vec.begin(), vec.end());


//文字列操作
stoi(s) int型に変換 //charはASCIIでしましょう
std::string(N,'a') //"a"*Nと同義
部分文字列
string sub_S = S.substr(開始位置, (長さ)) 長さはなくても可。指定なしだと最後まで
存在有無 SがTに含まれるかどうか
if (T.find(S) != string::npos){
    含まれる
}else 含まれない;
削除
S.pop_back(); //最後の文字を削除
S.erase(S.begin() + 3) // 前から4番目の文字を削除 0(N)
S.erase(S.begin()+2, S.end()-1) //範囲ごと削除もできる

//素因数分解
vector<int> prime_factorization(int n){
    int copy = n;
    vector<int> res;
    for(int i=2;i*i<=copy;i++){
        if(n%i==0){
            res.push_back(i);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}

//エラトステネスの篩
vector<int> Eratos(N+1,1);
void Eratosthenes(int n,vector<int>& Eratos){
    for(int i=2;i*i<=n;i++){
        if(Eratos[i]==0) continue;
        for(int j=2*i;j<=n;j+=i){
            Eratos[j]=0;
        }
    }
}

//combination系
int factorial(int n){
    int res=1;
    while(n>0){
        res*=n;
        n--;
    }
    return res;
}

void init_Pascal(int N,vector<vector<int>>& pascal){
    //vector<vector<int>> pascal(N+1,vector<int>(N+1));
    REP(i,N+1){
        REP(j,i+1){
            if((i==0 )|| (j==0)){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
    }
}



//bfs
vector<int> bfs(int s){ 
    vector<int> dist(N,INF),pre(N);//pre(N); pre[s]=-1; 経路復元するなら
    queue<int> q; q.push(s);
    dist[s]=0;
    pre[s]=-1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u:edge[v]){
            if(dist[u]!=INF) continue;
            q.push(u); dist[u] = dist[v]+1;
            pre[u] = v;
        }
    }

    //最短サイクル検出
    pair<int,int> best(INF,-1);
    REP(v,N){
        if(v==s) continue;
        for(auto u:edge[v]){
            if(u==s){
                chmin(best,mp(dist[v],v));
                //適当に1つ見つけるだけなら break;
            }
        }
    }
    if(best.first == INF) return vector<int>(N+1); //サイクルなし

    //経路復元
    vector<int> res; int v = best.second;
    while(v!=-1){ res.push_back(v+1); v=pre[v]; }
    return res;
}

//z-algorithm
vector<int> z_algorithm(string S){
    int N = S.size();
    vector<int> A(N,0);
    A[0] = N;
    int left=1;
    int len = 0;
    while(left < N){
        while(left+len < N && S[len]==S[left+len]){
            len++;
        } //文字列の頭からと、leftからの文字列の共通接頭辞の長さを求める
        A[left] = len;
        if(len == 0){
            left ++;
            continue;
        }
        int k=1;
        while(left + k < N && k + A[k] < len){
            A[left+k] = A[k];
            k++;
        }

        left += k;
        len-=k;
    }
    return A;
}

//mint
struct mint {
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

long long modpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}