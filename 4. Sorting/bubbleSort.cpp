#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &a, int n){
    for(int i=1; i<n; ++i){
        for(int j=0; j<n-i; ++j){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {9,12,19,88,92,2,3,16,45};
    bubbleSort(arr,arr.size());
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<"\t";
    }
    return 0;
}