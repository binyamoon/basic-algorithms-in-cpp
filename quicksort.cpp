#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b){
    int c = *a;
    *a = *b; 
    *b = c;
}

void quick_sort(int* start, int* end, int length){

    /** Base cases **/
    if(length <= 1){
        return;
    } else if(length == 2){
        if(*start < *end){
            return;
        } else {
            swap(start, end);
            return;
        }
    }

    int pivot = *start; // Pivot element
    vector<int> positions; // Positions of elements <= pivot
    int partition = 1; // This variable will mark the position from where elements are > pivot

    // List all elements <= pivot
    for(int i = 1; i < length; i++){
        if(*(start + i) <= pivot){
            positions.push_back(i);
        }
    }

    // move them all to the left
    for(int x: positions){
        swap(start + partition, start + x);
        partition++;
    }

    // Swap pivot and first element
    // So that all elements to left of pivot are <= pivot
    // and all to the right are greater
    swap(start, start + partition - 1);

    // Call quicksort on subarrays excluding pivot element
    quick_sort(start, start + partition - 2, partition);
    quick_sort(start + partition, end, length - partition);
}

int main(){
    // Declare your array here
    int arr[] = {56, 89, 46, 18, 69, 37, 92, 86};

    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(&arr[0], &arr[size - 1], size);
    cout << "Sorted: ";
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

