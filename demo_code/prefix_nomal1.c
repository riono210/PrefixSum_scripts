#include <stdio.h>

#define NUM 100000

int main(int argc, char** argv){
  int n;
 
  
  long sum[NUM];
  //int x[NUM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  int x[NUM];
  long adds;
  for (int a=0; a<NUM; a++){
    x[a] = a;
  }
  
  // 総和
  for(int i = 0; i < NUM; i++){
    sum[i] = 0;
    adds = 0;
    for(int j = 0; j <= i; j++ ){
      //sum[i] = sum[i] + x[j];
      adds += x[j]; 
    }
    sum[i] = adds;
  }

  for (int k= 0; k< NUM; k++){
    printf("%ld\n", sum[k]);
    }
}
