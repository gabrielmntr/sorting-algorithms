/*
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct 
position in the sorted part.
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* v, int x, int y){
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

int insertion_sort(int* v, int n){
  for(int i=1; i<n; i++){
    int j = i;
    while(j>0 && v[j-1] > v[j]){
      swap(v, j, j-1);
      j-=1;
    }
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
  int n = sizeof(v)/sizeof(int);
  insertion_sort(v, n);
  print(v, n);

  return 0;
}