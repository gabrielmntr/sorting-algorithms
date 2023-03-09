#include <stdio.h>
#include <stdlib.h>

void swap(int* v, int x, int y){
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

void bubble_sort(int* v, int n){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++)
      if(v[j] > v[j+1]) swap(v, j, j+1);
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

  bubble_sort(v, n1);
  print(v, n1);

  bubble_sort(z, n2);
  print(z, n2);

  bubble_sort(x, n3);
  print(x, n3);
  return 0;
}