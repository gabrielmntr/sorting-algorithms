//works by dividing an array into smaller subarrays, sorting each subarray, and then 
//merging the sorted subarrays back together to form the final sorted array.
#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2]; //temp arrays

  //copy data to temp arrays
  for (i = 0; i < n1; i++)
    L[i] = v[l + i];
  for (j = 0; j < n2; j++)
    R[j] = v[m + 1 + j];

/* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      v[k] = L[i];
      i++;
    }
    else {
      v[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
  are any */
  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
  are any */
  while (j < n2) {
    v[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int* v, int n, int l, int r)
{
  int m;
  if(l < r){
    m= l + (r - l)/2;
    merge_sort(v, n, l, m);
    merge_sort(v, n, m+1, r);

    merge(v, l, m, r);
  }
}

void print(int *v, int n){
  for (int i=0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int main()
{
  int v[] = {46, 12, 5, 23, 30};
  int z[] = {6, 2, 7, 4, 8, 9, 1};
  int x[] = {40, 20, 50, 10, 100, 30, 70, 90, 60, 80};
  int n1 = sizeof(v)/sizeof(int);
  int n2 = sizeof(z)/sizeof(int);
  int n3 = sizeof(x)/sizeof(int);

  merge_sort(v, n1, 0, n1-1);
  print(v, n1);

  merge_sort(z, n2, 0, n2-1);
  print(z, n2);

  merge_sort(x, n3, 0, n3-1);
  print(x, n3);

  return 0;
}