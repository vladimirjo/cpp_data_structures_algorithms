#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#include <cstdio>

void insertSort (int arr[], int length) {
  for (int j = 1; j < length; j++) {
    int key = arr[j];
    int i = j - 1;
    while (i >= 0 && key <= arr[i] ) {
      arr[i + 1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
}

void insertSortReverse (int arr[], int length) {
  for (int j = 1; j < length; j++) {
    int key = arr[j];
    int i = j - 1;
    while (i >= 0 && key >= arr[i] ) {
      arr[i + 1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
}

#endif