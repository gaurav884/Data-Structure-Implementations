#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    
    public:
    vector<int>arr;
    
    MaxHeap(){
        
    }
    
    int top(){
        
        return arr[0];
    }
    
    void insert(int num){
        
        arr.push_back(num);
        
        int i = arr.size()-1;
        
        while(i>=1){
            
            int parent = i/2;
            
            if(arr[parent] < arr[i]){
                
                swap(arr[parent] , arr[i]);
                
                i = parent;
            }
            
            else{
                return;
            }
        }
    }
    
    void pop(){
        
        int last = arr[arr.size()-1];
        arr.pop_back();
        
        arr[0] = last;
        int i = 0;
        while(true){
            
            int left = 2*i+1;
            int right =2*i+2;
            
            int replaceWith ;
            
            if(left >arr.size()-1 && right > arr.size()-1 ) return;
            
            if(left < arr.size() && right < arr.size()){
                
                replaceWith = arr[left]> arr[right] ? left : right;
                
            }
            
            else replaceWith = left<arr.size() ? left : right;
            
            
             swap(arr[i] , arr[replaceWith]);
              i= replaceWith;
            
        }
        
    }
};

int main()
{
    MaxHeap a;
    
    a.insert(15);
    a.insert(130);
    a.insert(1);
    a.insert(1167);
    a.pop();
    cout<<a.top();
    
    
    
    
    return 0;
}
