#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &a, int n){
    int element, j;
    for(int i=1; i<a.size(); ++i){
        element = a[i];
        j = i-1;
        while(j>=0 && a[j]>element){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = element;
    }
}

int main(){
    vector<int> arr = {9,12,19,88,92,2,3,16,45};
    insertionSort(arr,arr.size());
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<"\t";
    }
    return 0;
}