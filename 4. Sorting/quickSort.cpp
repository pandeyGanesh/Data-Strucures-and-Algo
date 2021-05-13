#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int start, int end){
    if (end-start > 1){
        int pivot = a[end];
        // small and large act as pointers
        int small = start;
        for(int large=start; large<end; ++large){
            if(a[large]<pivot){
                swap(a[large],a[small]);
                ++small;
            }
        }
        swap(a[end],a[small]);
        quickSort(a,start,small-1);
        quickSort(a,small+1,end);
    }
}

int main(){
    vector<int> arr = {9,12,19,88,92,2,3,16,45};
    quickSort(arr,0,arr.size()-1);
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<"\t";
    }
    return 0;
}