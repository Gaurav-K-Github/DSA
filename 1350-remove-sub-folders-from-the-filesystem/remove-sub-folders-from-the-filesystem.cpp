class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n = folder.size();
        

        unordered_set<string>st;
        vector<string>ans;

        for(auto str:folder){
            bool flag=false;
            for(int i=1;i<str.size();i++){
                if(str[i]=='/'){
                    string par = str.substr(0,i);
                    if(st.count(par)){
                        flag=true;
                        break;
                    }
                }
            }

            if(!flag){
                st.insert(str);
                ans.push_back(str);
            }
        }
        

        return ans;
    }
};