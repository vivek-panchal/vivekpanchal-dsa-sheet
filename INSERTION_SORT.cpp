// while loop

void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for ( int i = 1; i<n; i++ ){
        int current = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>current){
            arr[prev + 1]=arr[prev];
            prev = prev-1;   
        }
        arr[prev+1]=current; 
    }  
}

//for loop

#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}
