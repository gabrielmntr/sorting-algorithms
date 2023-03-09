//Selection sort: works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list
// and moving it to the sorted portion of the list.
#include <stdio.h>
#include <stdlib.h>

int seleciona(int* v, int n, int ini){
  for (int j = ini+1; j < n; j++)
    if(v[j] < v[ini]) ini = j;
  return ini;  
}

void swap(int* v, int x, int y){
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

void selection_sort(int* v, int n){
  for (int i = 0; i < n-1; i++){
    int pos = seleciona(v, n, i);
    if(pos != i) 
      swap(v, i, pos);
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
  selection_sort(v, n);
  print(v, n);

  return 0;
}