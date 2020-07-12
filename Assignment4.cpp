// Assingment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int comparisons, exchanges, space_used;


vector<int> get_sorted_vec() {
    vector <int> vec(10000);
    for (int x = 0; x < 10000; x++) {
        vec.at(x)= x;
    }
    return vec;
    
}
vector<int> get_random_vec() {
    vector <int> vec(10000);
    for (int x = 0; x < 10000; x++) {
        vec.at(x) = rand() % 10000 + 1;
        
    }
    return vec;

}
vector<int> get_reversed_vec() {
    vector <int> vec(10000);
    for (int x = 0; x < 10000; x++) {
        vec.at(x) = 10000-x-1;
    }
    return vec;

}
void ShellSort(vector <int>& num) {
    int i, temp, flag = 1, numLength = num.size(); 
    int gap = numLength; 
    bool insertionNeeded = false; 
    int swapPos = 0; 
    int key; 
    while (true) {    // boolean flag (true when not equal to 0) 
        gap = (gap - 1) / 2;
        if (gap == 0)
            break;
        
        for (int k = 0; k < gap; k++) {
            for (int j = gap + k; j < numLength; j += gap) {
                key = num[j];
                insertionNeeded = false;
                for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
                    comparisons++;
                    if (key < num[i]) {
                        swapPos = i;
                        exchanges++;
                        num[i + gap] = num[i];
                        insertionNeeded = true;
                    }
                    else
                        break;
                }
                if (insertionNeeded) {
                    num[swapPos] = key;    //Put key into its proper location
                }
            }
        }
    }
    return;
}

void selection_sort(vector<int>& vec) {
    for (int fill = 0; fill != vec.size(); ++fill) {
        int pos_min = fill; 
        for (int next = fill + 1; next != vec.size(); ++next) { 
            comparisons++;
            if (vec[next] < vec[pos_min])
               
                pos_min = next;
        }
        if (fill != pos_min) {
            exchanges++;
            swap(vec[pos_min], vec[fill]);
        }
    }
}
void bubble_sort(vector <int>& vec) {
    bool exchanges_made = false; 
    for (int i = 1; i <= vec.size(); i++) {
        exchanges_made = false; 
        for (int j = 0; j < vec.size() - i; j++) {
            comparisons++;
            if (vec[j + 1] < vec[j]) {
                exchanges++;
                swap(vec[j], vec[j + 1]); // swap elements
                exchanges_made = true;
            }
        }
        if (!exchanges_made)
            break;
    }
}
void insertion_sort(std::vector <int>& num) {
    int i, j, key; 
    bool insertionNeeded = false; 
    for (j = 1; j < num.size(); j++) {
        key = num[j]; 
        insertionNeeded = false; 
        for (i = j - 1; i >= 0; i--) { // larger values move right
            comparisons++;
            if (key < num[i]) {
                num[i + 1] = num[i];
                exchanges++;
                insertionNeeded = true;
            }
            else
                break;
    }
        if (insertionNeeded)
            num[i + 1] = key;    //Put key into its proper location
    }
}
void insertion_sort_list(int arr[], int size ) {
   
    
    int temp,i;
    
    for (int j = 1; j < size; j++) {
        
        
        temp = arr[j];
        i = j - 1;
        comparisons++;
        cout << "i: " << i << " arr[i]: " << arr[i] << " temp: " << temp << endl;
        while (i >= 0 && arr[i] > temp) {
            exchanges++;
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = temp;

    }
    
    
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {
    int j = 0; 
    int lowerBound = lowPointer; 
    int mid = highPointer - 1; 
    int n = upperBound - lowerBound + 1; //number of items
    while (lowPointer <= mid && highPointer <= upperBound){
        comparisons++;
        exchanges++;
        if (array[lowPointer] < array[highPointer])
            result[j++] = array[lowPointer++];
        else
            result[j++] = array[highPointer++];
    }
    while (lowPointer <= mid) {
        result[j++] = array[lowPointer++];
        exchanges++;
    }
    while (highPointer <= upperBound) {
        result[j++] = array[highPointer++];
        exchanges++;
    }
    for (j = 0; j < n; j++) { //copy the items from the temporary array to the original array
        space_used++;
        array[lowerBound + j] = result[j];
    }
}
void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
    int midpoint;
    if (lowerBand < upperBand) {
        midpoint = (lowerBand + upperBand) / 2;
        mergesort(array, result, lowerBand, midpoint); //merge sort the left half
        mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
        merge(array, result, lowerBand, midpoint + 1, upperBand);
    }
}
void mergeSort(std::vector<int>& array){
    std::vector<int> result = array;
    mergesort(array, result, 0, array.size() - 1);
}

int partition(int first, int last, std::vector<int>& arr) {
    // Start up and down at either end of the sequence.
   // The first table element is the pivot value.
    int up = first+1;
    int down = last-1;
    do {
        while ((up != last) && !(arr[first] < arr[up])) {
            comparisons++;
            ++up;
        }
        while (arr[first] < arr[down]) {
            comparisons++;
            --down;
        }
        if (up < down) {
            // if up is to the left of down,
            exchanges++;
            swap(arr[up], arr[down]);
        }
    } while (up < down); // Repeat while up is left of down.
    
    exchanges++;
    swap(arr[down], arr[first]);
    return down;
}
void sort_median(std::vector<int>& arr, int first, int last){
    bool exchanges_made = true;
    int middle = (first + last) / 2;
    comparisons++;
    if (arr[first] > arr[middle]) {
        exchanges++;
        swap(arr[first], arr[middle]);
    }
    comparisons++;
    if (arr[middle] > arr[last]) {
        exchanges++;
        swap(arr[middle], arr[last]);
    }
    comparisons++;
    if (arr[first] > arr[middle]) {
        exchanges++;
        swap(arr[first], arr[middle]);//swap the middle with the left 
    }
    swap(arr[middle], arr[first]);
    exchanges++;
}

int partitionB(int first, int last, std::vector<int>& arr) {// Start up and down at either end of the sequence.
      // The first table element is the pivot value.
    int up = first+1;
    int down = last-1;
    sort_median(arr, first, last-1);
    int mid = first;
    do 
    {
        while ((up != last - 1) && !(arr[mid] < arr[up])) {
            comparisons++;
            ++up;
        }
        while (arr[mid] < arr[down]) {
            comparisons++;
            --down;
        }
        if (up < down) {// if up is to the left of down,
            exchanges++;
            swap(arr[up], arr[down]);
        }
} while (up < down); // Repeat while up is left of down.
    
    swap(arr[mid], arr[down]);
    exchanges++;
    return down;

}void middle_quick_sort(int first, int last, std::vector<int>& arr) {
   
    if (last - first > 1) {
    // There is data to be sorted.
    // Partition the table.
        int pivot = partitionB(first, last, arr);// Sort the left half.
        middle_quick_sort(first, pivot, arr);// Sort the right half.
        middle_quick_sort(pivot + 1, last, arr);
    }
}
void quick_sort(int first, int last, std::vector<int>& arr) {
    if (last - first > 1) {
        // There is data to be sorted.
        // Partition the table.
        int pivot = partition(first, last, arr);
        
        // Sort the left subarray.
        quick_sort(first, pivot, arr);
        
        // Sort the right subarray.
        quick_sort(pivot + 1, last, arr);
    }
}
void quick_sort_wrapper(vector<int>& arr){

    quick_sort(0, arr.size(), arr);
}
void middle_quick_sort_wrapper(vector<int>& arr){

    middle_quick_sort(0, arr.size(), arr);
}

int main()
{
    vector<int> sorted_vec= get_sorted_vec();
    vector<int> random_vec = get_random_vec();
    vector<int> reversed_vec = get_reversed_vec();

    
    //---------------------------------------------------------------------------------------------------------------------
    // Selection Sort
    comparisons = exchanges = space_used = 0;
    selection_sort(random_vec);
    cout << " Selection Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;
    
    comparisons = exchanges = space_used = 0;
    selection_sort(sorted_vec);
    cout << " Selection Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;
    
    comparisons = exchanges = space_used = 0;
    selection_sort(reversed_vec);
    cout << " Selection Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;
   // --------------------------------------------------------------------------------------------------------------------------
    
    
    
    //--------------------------------------------------------------------- ----------------------------------------------------
    //Bubble Sort
    comparisons = exchanges = space_used = 0;
    bubble_sort(random_vec);
    cout << " Bubble Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    bubble_sort(sorted_vec);
    cout << " Bubble Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    bubble_sort(reversed_vec);
    cout << " Bubble Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;
  // ---------------------------------------------------------------------------------------------------------------------
    
//---------------------------------------------------------------------------------------------------------------------
    //Insertion Sort
    comparisons = exchanges = space_used = 0;
    insertion_sort(random_vec);
    cout << " Insertion Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    insertion_sort(sorted_vec);
    cout << " Insertion Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    insertion_sort(reversed_vec);
    cout << " Insertion Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------
    //Shell Sort
    comparisons = exchanges = space_used = 0;
    ShellSort(random_vec);
    cout << " shell Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    ShellSort(sorted_vec);
    cout << " shell Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    ShellSort(reversed_vec);
    cout << " shell Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------
    //merge Sort
    comparisons = exchanges = space_used = 0;
    
    mergeSort(random_vec);
    cout << " merge Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    mergeSort(sorted_vec);
    cout << " merge Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    mergeSort(reversed_vec);
    cout << " merge Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------

    //quick Sort (original)
    comparisons = exchanges = space_used = 0;

    quick_sort_wrapper(random_vec);
    cout << " quick Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    quick_sort_wrapper(sorted_vec);
    cout << " quick Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    quick_sort_wrapper(reversed_vec);
    cout << " quick Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------
    
    //quick Sort (improved)
    comparisons = exchanges = space_used = 0;

    middle_quick_sort_wrapper(random_vec);
    cout << " quick Sort: Random Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    middle_quick_sort_wrapper(sorted_vec);
    cout << " quick Sort: Sorted Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    comparisons = exchanges = space_used = 0;
    middle_quick_sort_wrapper(reversed_vec);
    cout << " quick Sort: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------
    
    //Insertion Sort (WITH LISTS!!!)
int random_list[10000];


for (int x = 0; x < 10000; x++) {
    random_list[x] = (rand() % 10000 + 1);
}
    comparisons = exchanges = space_used = 0;
    insertion_sort_list(random_list,10000);
    cout << " insertion sort list: random array " << endl;
    cout << "comparisons: " << comparisons << " exchanges: " << exchanges << " space: " << space_used << endl;
    

    int sorted_list[10000];

    for (int x = 0; x < 10000; x++) {
        sorted_list[x] = x;
    }
    comparisons = exchanges = space_used = 0;
    insertion_sort_list(sorted_list,10000);
    cout << " insertion sort list: sorted array " << endl;
    cout << "comparisons: " << comparisons << " exchanges: " << exchanges << " space: " << space_used << endl;

    int reversed_list[10000];

    for (int x = 9999; x >= 0; x--) {
        reversed_list[9999-x] = x;
    }


    comparisons = exchanges = space_used = 0;
    insertion_sort_list(reversed_list,10000);
    cout << " Insertion Sort List: Reversed Array " << endl;
    cout << "Comparisons: " << comparisons << " Exchanges: " << exchanges << " Space: " << space_used << endl;

    //---------------------------------------------------------------------------------------------------------------------
}



