class Solution { //Please upvote if it helps :)
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>>row, col;
        for(auto &v : obstacles){
            int i = v[0], j = v[1];
            row[i].insert(j);
            col[j].insert(i); 
        }
        int ans = 0;
        int i = 0, j = 0, dir = 0;
        for(auto &k : commands){
            if(k > 0){//need to move
                ans = max(ans, i*i + j*j);
                if(dir == 0){//facing north -> +y
                    if(row.find(i) != row.end()){
                        auto it = row[i].upper_bound(j);
                        if(it != row[i].end() && (*it) <= (j+k)){
                            j = (*it)-1;
                            continue;
                        }
                    }
                    j += k;
                }else if(dir == 1){//facing east -> +x
                    if(col.find(j) != col.end()){
                        auto it = col[j].upper_bound(i);
                        if(it != col[j].end() && (*it) <= (i+k)){
                            i = (*it)-1;
                            continue;
                        }
                    }
                    i += k;
                }else if(dir == 2){//facing south -> -y
                    if(row.find(i) != row.end()){
                        auto it = row[i].lower_bound(j);
                        if(it != row[i].begin()){
                            it--;
                            if((*it) >= (j-k)){
                                j = (*it) + 1;
                                continue;
                            }
                        }
                    }
                    j -= k;
                }else{//facing west -> -x
                    if(col.find(j) != col.end()){
                        auto it = col[j].lower_bound(i);
                        if(it != col[j].begin()){
                            it--;
                            if((*it) >= (i-k)){
                                i = (*it) + 1;
                                continue;
                            }
                        }
                    }
                    i -= k;
                }
            }else{//need to change dir
                if(k == -1){
                    dir = (dir+1)%4;
                }else{
                    dir = (dir+3)%4;
                }
            }
        }
        ans = max(ans, i*i + j*j);
        return ans;
    }
};
/*
dir: 0 = north, 1 = east, 2 = south, 3 = west
-1 = turns right = (dir + 1) % 4;
-2 = turns left = (dir + 3) % 4; 
blockage:
in row 0-..., 1-..
in col 0-..., 1-..
*/