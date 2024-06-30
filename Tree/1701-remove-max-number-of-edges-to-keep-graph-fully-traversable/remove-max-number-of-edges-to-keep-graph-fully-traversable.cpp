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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n-1),bob(n-1);
        sort(edges.rbegin(),edges.rend());
        int extra =0;
        for(auto i:edges){
            if(i[0]==1){
                extra+=alice.unionBySize(i[1]-1,i[2]-1);
            }else if(i[0]==2){
                extra+=bob.unionBySize(i[1]-1,i[2]-1);
            }else{
                extra+=(alice.unionBySize(i[1]-1,i[2]-1) || bob.unionBySize(i[1]-1,i[2]-1));
            }
        }
        for(int i=0;i<n;i++){
            int tp = alice.findUP(i);
            tp = bob.findUP(i);
        }
        set<int> st;
        bool flag = 1;
        for(auto i:alice.parent) st.insert(i);
        if(st.size()!=1) flag=0;
        st.clear();
        for(auto i:bob.parent) st.insert(i);
        if(st.size()!=1) flag=0;
        return (flag)?extra:-1;
    }
};