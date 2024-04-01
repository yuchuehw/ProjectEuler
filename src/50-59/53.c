#include <stdio.h>
#include <stdlib.h>
#define K 101
#define M 1000000

void pascal_new_row(double *prev, double *new_, int items){
  new_[0] = 1.0;
  for (int i = 1; i <= items; i++){
    new_[i] = prev[i-1] + prev[i];
  }
  new_[items] = 1.0;
}

void printrow(double *row, int len){
  for (int i=0;i<len;i++){
    printf("%lf ",row[i]);
  }
  printf("\n");
}

int count_greater_k(double *row, int len, int k){
  int counter = 0;
  for (int i=0;i<len;i++){
    if (row[i]>k){
      counter++;
    }
  }
  return counter;
}

int main(){
  double * row1 = calloc(sizeof(double)*(K+1),sizeof(double));
  double * row2 = calloc(sizeof(double)*(K+1),sizeof(double));
  row1[0] = 1.0;
  int counter = 0;
  for (int i=1;i<K;i++){
    counter += count_greater_k(row1,K,M);
    pascal_new_row(row1,row2,i);
    double *temp = row1;
    row1 = row2;
    row2 = temp;
  }
  counter += count_greater_k(row1,K,M);
  
  printf("%d", counter);
}
