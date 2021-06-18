#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BUBBLE SORT

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}


//SELECTION SORT

void selectSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_ind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
}

//INSERTION SORT

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//MERGE SORT 

void merge(int arr[], int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;
    int left[n1], right[n2];
    for(int i=0;i<n1;i++){
        left[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = arr[m+1+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 and j<n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }
        while(i<n1){
            arr[k++] = left[i++];
        }
        while(j<n2){
            arr[k++] = right[j++];
        }
}

void mergeSort(int arr[], int l, int r){
    if(r>l){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

//QUICK SORT

//Lomuto Partition

int lpartition(int arr[], int l, int h){
    int p = (rand() % (h-l+1) + l);
    swap(arr[h], arr[p]);
    int pivot = arr[h];
    int i = l-1;
    for(int j=l;j<h;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}

//Hoare's Partition

int hpartition(int arr[], int l, int h){
    int p = (rand() % (h-l+1) + l);
    swap(arr[l], arr[p]);
    int pivot = arr[l];
    int i = l-1;
    int j = h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[i], arr[j]);
    }
}

void qlsort(int arr[], int l, int h){
    if(l<h){
        int p = lpartition(arr, l, h);
        qlsort(arr, l, p-1);
        qlsort(arr, p+1, h);
    }
}

void qhsort(int arr[], int l, int h){
    if(l<h){
        int p = hpartition(arr, l, h);
        qhsort(arr, l, p);
        qhsort(arr, p+1, h);
    }
}

//HEAP SORT 

//Step 1 : Build a max heap

void maxHeapify(int arr[], int n, int i){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left<n and arr[left]>arr[largest]) largest = left;
    if(right<n and arr[right]>arr[largest]) largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i = (n-2)/2;i>=0;i--){
        maxHeapify(arr, n, i);
    }
}

//Step 2: Repeatedly swap root with last node, reduce heap size by 1 and heapify.

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i=n-1;i>=1;i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

//COUNT SORT

void countSort(int arr[], int n, int k){
    int count[k] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        count[i] += count[i];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

//RADIX SORT

void countingSort(int arr[], int n, int exp){
    int count[10] = {0};
    int output[n];
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx){
            mx = arr[i];
        }
    }
    for(int exp=1;(mx/exp)>0;exp*=10){
        countingSort(arr, n, exp);
    }
}

//BUCKET SORT

void bucketSort(int arr[], int n, int k){
    int max_val = arr[0];
    for(int i=1;i<n;i++){
        max_val = max(max_val, arr[i]);
    }
    max_val++; //To get a valid bucket index.
    vector <int> bkt[k];
    for(int i=0;i<n;i++){
        int bi = (k * arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        sort(bkt[i].begin(), bkt[i].end());
    }
    int index = 0;

    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++){
            arr[index++] = bkt[i][j];
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //bubbleSort(arr, n);
    //selectSort(arr, n);
    //insertionSort(arr, n);
    //mergeSort(arr, 0, n-1);
    //qlsort(arr, 0, n);
    //qhsort(arr, 0, n);
    //heapSort(arr, n);
    //countSort(arr, n, 11);
    //radixSort(arr, n);
    //bucketSort(arr, 5, 5);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}