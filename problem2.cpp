//by saidjonakr

#include<bits/stdc++.h>
using namespace std;

void heapify(long long arr[], int n, int i){
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(long long arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
  int n;
  long long sum = 0; 
  cin >> n;
  //n *= 2;
  long long arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = n/2-1; i >= 0; i--){
      heapify(arr, n, i);
  }
  heapSort(arr, n);
  for(int i = 0; i < n; i += 2){
    sum += arr[i];
  }
  cout << sum;
  return 0;
}
