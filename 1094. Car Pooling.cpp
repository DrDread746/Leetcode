class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int c) {
        vector<pair<int,int>> v(t.size());
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<t.size();i++){
            v[i].first = t[i][1];
            v[i].second = t[i][0];
            pq.push({ t[i][2] , t[i][0] });
        }
        sort(v.begin() , v.end());
        int r = 0;
        int curr = 0;
        int ndrop = 0;
        while(!pq.empty()){
            ndrop = pq.top().first;
            while( r < v.size() && v[r].first < ndrop){
                curr+=v[r].second;
                if(curr > c) return false;
                r++;
            }
            curr-=pq.top().second;
            pq.pop();
        }
        return true;
    }
};
