bool isPossible(vector<int> &boards,int k,int mid,int n){
   int pc=1;
   int boardsum=0;
   for(int i=0;i<n;i++){    
       if(boardsum+boards[i]<=mid){
       boardsum+=boards[i];
       }
       else{
           pc++;
           if(pc>k || boards[i]>mid){
           return false;
           }
           //boardsum=0;
           boardsum = boards[i];
       }
   }
       return true;
}
int findLargestMinDistance(vector<int> &boards, int k){
   int s=0;
   int sum=0;
   int ans=-1;
   int n=boards.size();
   for(int i=0;i<n;i++){
       sum+=boards[i];
   }
   int e=sum;
   int mid=s+(e-s)/2;
   while(s<=e){
       if(isPossible(boards,k,mid,n)){
           ans=mid;
           e=mid-1;
       }
       else {
           s=mid+1;
       }
       mid=s+(e-s)/2;
   }
   return mid;
}
