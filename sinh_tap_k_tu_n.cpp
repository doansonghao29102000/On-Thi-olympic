#include <conio.h>

#include <stdio.h>

#include <stdlib.h>

#define MAX  100

int B[MAX], n, k, count = 0;

void Init(void){

 printf("\n Nhap n="); scanf("%d", &n);

 printf("\n Nhap k="); scanf("%d", &k);

 B[0] = 0;

}

void Result(void){

 int i; count++;

 printf("\n Tap thu %d:", count);

 for (i = 1; i <= k; i++){

  printf("%3d", B[i]);

 }

 getch();

}

void Try(int i){

 int j;

 for (j = B[i - 1] + 1; j <= (n - k + i); j++){

  B[i] = j;

  if (i == k) Result();

  else Try(i + 1);

 }

}

int main(){

 Init();

 Try(1);

}