#include<iostream>
#include<vector>
using namespace std;
void merge(long long start, long long middle, long long end, vector<long long>& arr){
    long long n1 = middle - start + 1;
    long long n2 = end - middle;
    vector<long long> left(n1);
    vector<long long> right(n2);
    for (long long i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (long long i = 0; i < n2; i++)
        right[i] = arr[middle + 1 + i];
    long long i = 0, j = 0, k = start;
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(long long start, long long end, vector<long long>& arr){
    if (start >= end)
        return;
    long long middle = start + (end - start)/2;
    mergesort(start, middle, arr);               
    mergesort(middle + 1, end, arr);             
    merge(start, middle, end, arr);              
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> desired_apartment(n);
    for (long long i = 0; i < n; i++) {
        cin >> desired_apartment[i];
    }
    vector<long long> size_apartment(m);
    for (long long i = 0; i < m; i++) {
        cin >> size_apartment[i];
    }
    mergesort(0, n - 1, desired_apartment);
    mergesort(0, m - 1, size_apartment);
    long long i = 0, j = 0, peoplecount = 0;
    while (i < n && j < m) {
        if(size_apartment[j] >= desired_apartment[i] - k && size_apartment[j] <= desired_apartment[i] + k){
            peoplecount++;
            i++;
            j++;
        }
        else if (size_apartment[j]<desired_apartment[i]-k){
            
            j++;}
        else{
            i++;
        }
    }
    cout << peoplecount << endl;
    
}
