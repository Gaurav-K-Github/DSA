class Solution {
public:
    vector<int> bucket[64];//64**3=262144>1e5+1>max(sum)
    inline void radix_sort(vector<int>& nums) {
        // 1st round
        for (int x : nums){
            bucket[x&63].push_back(x);
        }
        int i = 0;
        for (auto &B : bucket) {
            copy(B.begin(), B.end(), nums.begin()+i);
            i+=B.size();
            B.clear();
        }
        // 2nd round
        for (int x : nums)
            bucket[(x>>6)&63].push_back(x);
        i=0;
        for (auto &B : bucket) {
            copy(B.begin(), B.end(), nums.begin()+i);
            i+=B.size();
            B.clear();
        }
        // 3rd round
        for (int x : nums)
            bucket[x>>12].push_back(x);
        i=0;
        for (auto &B : bucket) {
            copy(B.begin(), B.end(), nums.begin()+i);
            i+=B.size();
        //    B.clear();
        }
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod=1e9+7;
        vector<int> sum(n*(n+1)/2, 0);
        int idx=0;
        for(int i=0; i<n; i++){
            int x=0;
            for(int j=i; j<n; j++){
                x+=nums[j];
                sum[idx++]=x;
            }
        }
        radix_sort(sum);
        return accumulate(sum.begin()+left-1, sum.begin()+right, 0LL)%mod;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
  