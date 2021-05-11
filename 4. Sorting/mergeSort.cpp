#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> mergeSort(vector<int> a, int n){
    // If only single element is in the vector, return the vector
    if (n==1)
        return a;
    
    // Parititon the vector into left and right vectors
    vector<int> left, right;
    for(int i=0; i<n/2; ++i){
        left.push_back(a[i]);
    }

    for(int i=(n/2); i<n; ++i){
        right.push_back(a[i]);
    }

    // Adding MAX element in each vector to simplify merge operation
    left = mergeSort(left, left.size());
    left.push_back(INT_MAX);
    right = mergeSort(right, right.size());
    right.push_back(INT_MAX);

    vector<int> result;
    int indexL=0, indexR=0;
    for(int i=0; i<n; ++i){
        if(left[indexL]<right[indexR]){
            result.push_back(left[indexL++]);
        }
        else{
            result.push_back(right[indexR++]);
        }
    }
    return result;
}

int main(){
    vector<int> arr = {9,12,19,88,92,2,3,16,45};
    arr = mergeSort(arr,arr.size());
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<"\t";
    }
    return 0;
}