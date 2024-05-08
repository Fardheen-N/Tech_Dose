class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        } int pos = 1;
        while(!pq.empty()){
            auto i = pq.top(); pq.pop();
            switch (pos){
                case 1:
                    res[i.second]="Gold Medal";
                    break;
                case 2:
                    res[i.second]="Silver Medal";
                    break;
                case 3:
                    res[i.second]="Bronze Medal";
                    break;
                default:
                    res[i.second]=to_string(pos);
            }
            pos++;
        }
        return res;
    }
};