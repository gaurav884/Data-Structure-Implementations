#include <bits/stdc++.h>

using namespace std;


class DisjointSet{

    public:
    vector<int>rank;
    vector<int>parent;
    vector<int>size;

    DisjointSet(int n){

        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1 , 1);

        for(int i =0 ;i<=n ;i++) parent[i] = i;
    }

    int findUParent(int node){

        if(parent[node] == node) return node;

        return parent[node] = findUParent(parent[node]);   //rank is not height it just shows one is above in rank from other thats why pathcompression does not affect it.
    }

    void unionByRank(int u , int v){

        int u_par = findUParent(u);
        int v_par = findUParent(v);

        if(u_par == v_par) return ;

        if(rank[u_par] > rank[v_par]){ // lower rank is attached to higher rank becuase there are less nodes attached whoose traversal time to parent will be increased 
                                       // but if we had connected higher to lower rank, as higher contains more nodes, and their travel time to parent will be increased.

            parent[v_par] = u_par;
        }

        else if(rank[u_par] < rank[v_par]){

            parent[u_par] = v_par;
        }

        else{                           
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }

    void unionBySize(int u , int v){

        int u_par = findUParent(u);
        int v_par = findUParent(v);

        if(u_par == v_par) return ;

        if(size[u_par] > size[v_par]){  

            parent[v_par] = u_par;
            size[u_par]++;
        }

        else if(rank[u_par] < rank[v_par]){

            parent[u_par] = v_par;
            size[v_par]++;
        }

        else{

            parent[v_par] = u_par;
            size[u_par]++;
        }
    }

};

int main(){

   
     DisjointSet A(7);

     A.unionBySize(1,3);
     A.unionBySize(2,3);
     A.unionBySize(4,5);
     A.unionBySize(6,7);
     A.unionBySize(5,6);
     
     if(A.findUParent(3) == A.findUParent(7)) cout<<"Same"<<endl;
     
     else cout<<"not same"<<endl;


     A.unionBySize(3,7);

    if(A.findUParent(3) == A.findUParent(7)) cout<<"Same"<<endl;
     
     else cout<<"not same"<<endl;

    return 0;
}