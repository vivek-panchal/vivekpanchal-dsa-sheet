bool isPossible(int n, int m, vector<int> time,long long int mid){
  long long int reqtime=0;
   int day=1;
   for(int i=0;i<m;i++){
     if(reqtime+time[i]<=mid){
         reqtime=reqtime+time[i];
     }
      else{
          day++;
          if((day>n)||(time[i]>mid)){
              return false;
          }
//            reqtime=0;
          reqtime=time[i];
      }
   }
   return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time){  
   long long int ans=-1;
   long long int start=0;  
   long long int totalPages=0;
   for(int i=0;i<time.size();i++){
       totalPages+=time[i];
   }
   long long int mid=0;
   long long int end=totalPages;
   while(start<=end){
       mid=end-((end-start)/2);
       if(isPossible(n,m,time,mid)){
           ans=mid;
           end=mid-1;
       }
       else{
           start=mid+1;
       }
   }
   return ans;
}
