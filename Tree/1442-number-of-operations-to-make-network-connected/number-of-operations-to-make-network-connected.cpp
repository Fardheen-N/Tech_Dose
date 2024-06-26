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
	int unionBySize(int u,int v){
		int UP_u = findUP(u);
		int UP_v = findUP(v);
		if(UP_v==UP_u) return 1;
		if(size[UP_u]>=size[UP_v]){
			parent[UP_v]=UP_u;
			size[UP_u]+=size[UP_v];
		}else{
			parent[UP_u]=UP_v;
			size[UP_v]+=size[UP_u];
		}
        return 0;
	}
	void print_(){
		for(auto i:parent) cout<<i<<" ";
		cout<<endl;
	}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n-1);
        set<int> st;
        int extra=0;
        if(connections.size()<n-1) return -1;
        for(auto i:connections){
            if(ds.unionBySize(i[0],i[1])) extra++;
        }
        for(int i=0;i<n;i++){
            int tp=ds.findUP(i);
        }
        int needs = 0;
        ds.print_();
        for(auto i:ds.parent){
            st.insert(i);
        }
        needs = st.size()-1;
        return needs;
    }
};