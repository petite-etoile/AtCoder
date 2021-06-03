class BinaryIndexedTree{
public:
    size_t size;
    std::vector<int64> node;
    BinaryIndexedTree(size_t s){ 
        this->node.assign(s+1, 0); //1-index
        this->size = s;
    }

    void add(int index, int value){
        while(index <= this->size ){
            this->node[index] += value;
            index += index & -index;
        }
    }

    int sum(int index){
        int res = 0; //零元・単位元
        while(index > 0){
            res += this->node[index];
            index -= index & -index;
        }
        return res;
    }

    int64 get(int index){
        return this->node[index];
    }
};
template <typename T>
int64 Inversion_number(vector<T>& A){
    size_t N = A.size();
    
    vector<int> B = A;
    sort(ALL(B)); 
    B.erase(unique(ALL(B)), B.end());

    BinaryIndexedTree BIT(N);
    int64 ans=0; /////　オーバーフローには気をつけましょう！！！！！！！！！！！！！

    REP(i,N){
        int idx = lower_bound(ALL(B),A[i]) - B.begin();
        ans += i - BIT.sum(idx+1);
        BIT.add(idx+1,1);
    }
    return ans;
}