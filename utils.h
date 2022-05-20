#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include "singly_linked_list.h"

void print_out (int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

#endif