#include <stdio.h>
#include <omp.h>
#include <math.h>
#define NUM 10

int main(int argc, char** argv){
  int n;
  // 最大スレッド数
  //n = omp_get_max_threads();
 
  //

  
  long sum[NUM];
  // sumの初期化
  for(int a=0; a<NUM; a++){
    sum[a] = a;
  }
  
  int x[NUM];
  long adds;
  // 配列の用意
  for (int a=0; a<NUM; a++){
    x[a] = a;
  }

  double vale = log2(NUM);
  
  //printf("test:%f\n", vale);
  
  //#pragma omp parallel for
  for(int j=0; j < vale; j++){ 
    //printf("j;%d log:%f\n", j, vale);

    int index  = (int)pow(2,j);
    //printf("index:%d\n", index);

#pragma omp parallel  for
    for(int i=0; i < NUM; i++){
  // 現在のスレッドnum

#pragma omp critical(crit_cout)
      {
	if((i-  index) >= 0 ){
	  sum[i] += x[i - index];
	  //printf("yes\n");
	  //printf("i:%d sum:%d\n", i, x[i- index]);
	}
      }
    }
#pragma omp parallel for
    for (int k= 0; k< NUM; k++){
      x[k] = sum[k];
    }      
  }
  // 結果
  for(int z =0; z< NUM; z++){
    printf("%ld\n", sum[z]);
  }
}
