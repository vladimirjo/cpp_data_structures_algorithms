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


void printArray (int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}