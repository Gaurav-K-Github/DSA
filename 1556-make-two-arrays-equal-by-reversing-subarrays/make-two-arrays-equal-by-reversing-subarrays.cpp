class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;
        
        // Count frequencies of elements in both arrays
        unordered_map<int, int> count;
        
        // Count frequencies in target array
        for (int num : target) {
            count[num]++;
        }
        
        // Adjust frequencies based on arr
        for (int num : arr) {
            if (count.find(num) == count.end() || count[num] == 0) {
                return false;
            }
            count[num]--;
        }
        
        return true;
    }
};