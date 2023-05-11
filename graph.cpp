#include <iostream>
#include <map>
#include <vector>

using namespace std;

class graph{
   public:

   map<int , vector<int>> adj;

   void addEdge( int u , int v , bool dir){

     adj[u].push_back(v);

     if(dir == false){
        adj[v].push_back(u);
     }

   }

   void printList(){
   
      for(auto k : adj){
          cout<<k.first<<"-> ";
          for(int i =0 ;i<k.second.size() ;i++){
              cout<<adj[k.first][i]<<" ";
          }
          cout<<endl;
      }
     
   }



};


int main(){
    
    graph g;

    bool direction = false;
    int nodes , edges;

    cout<<"Enter the number of nodes : ";
    cin>>nodes;

    cout<<"Enter the number of Edges : ";
    cin>>edges;

    for(int i =0 ;i< edges ; i++){
       int u , v;
       cin>>u >> v;
       g.addEdge( u , v , direction);
    }


    g.printList();


    return 0;
}