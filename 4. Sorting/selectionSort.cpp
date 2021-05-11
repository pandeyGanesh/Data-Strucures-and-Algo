#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &a, int n){
    int minElement, pos;
    for(int i=0; i<n-1; ++i){
        minElement = a[i];
        pos = i;
        for(int j=i+1; j<n; ++j){
            if (a[j]<minElement){
                minElement = a[j];
                pos = j;
            }
        }

        swap(a[i],a[pos]);
    }
}

int main(){
    vector<int> arr = {9,12,19,88,92,2,3,16,45};
    selectionSort(arr,arr.size());
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<"\t";
    }
    return 0;
}