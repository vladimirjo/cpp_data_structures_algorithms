#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

// merges to SORTED subarrays in one sorted array
void merge(int arr[], int start, int middle, int end) {
    int n1 = middle - start + 1;
    int n2 = end - middle;
    
    int left[n1 + 1];
    int right[n2 + 1];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[middle + 1 + j];
    }

    left[n1] = 1000;
    right[n2] = 1000;

    int i = 0;
    int j = 0;

    for (int k = start; k <= end; k++) {
        if (left[i] <= right [j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

#endif