#include<bits/stdc++.h>
class node{
   public:
       int data;
       int row;
       int col;
       node(int data,int row,int col){
           this->data=data;
           this->row=row;
           this->col=col;
       }
};
class compare{
   public:
   bool operator()(node* a, node* b){
       return a->data > b->data;
   }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
   priority_queue<node*, vector<node*>,compare> mini;
  // step 1 : sare array ke first elemnt ko heap me dal do

    for(int i=0;i<k;i++){
       node* temp= new node(kArrays[i][0],i,0);
       mini.push(temp);
   }
   vector<int> ans;
// step 2: jab tak heap khali na ho jaye heap ke top ko ans me dalte raho and heap ke top ki array me jo next value hai usse heap me push kar do

   while(mini.size()>0){
       node* temp=mini.top();
       ans.push_back(temp->data);
       mini.pop();
       
       int i=temp->row;
       int j=temp->col;
       if(j+1 < kArrays[i].size()){
           node* next=new node(kArrays[i][j+1],i,j+1);
           mini.push(next);
       }
   }
   return ans;
}
