class DisjointSet {
	
public:
    vector<int> size,parent;
	DisjointSet(int n){
		size.resize(n+1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){parent[i]=i;size[i]=1;}
	}
	int findUP(int u){
		if(parent[u]==u) return u;
		return parent[u]=findUP(parent[u]);
	}
	void unionBySize(int u,int v){
		int UP_u = findUP(u);
		int UP_v = findUP(v);
		if(UP_v==UP_u) return;
		if(size[UP_u]>=size[UP_v]){
			parent[UP_v]=UP_u;
			size[UP_u]+=size[UP_v];
		}else{
			parent[UP_u]=UP_v;
			size[UP_v]+=size[UP_u];
		}
	}
	void print_(){
		for(auto i:parent) cout<<i<<" ";
		cout<<endl;
	}
};
class Solution {
public:
    bool valid(vector<int> &pos1,vector<int> &pos2){
        if(pos1[0]==pos2[0]||pos1[1]==pos2[1]) return 1;
        return 0;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n-1);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(valid(stones[i],stones[j])){
                    ds.unionBySize(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            int tp = ds.findUP(i);
        }
        set<int> st;
        for(auto i:ds.parent){
            st.insert(i);
        }
        ds.print_();
        return n-st.size();
    }
};