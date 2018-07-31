#include <stdio.h>
#include <omp.h>
#define NUM 500000

int main(int argc, char** argv){
  int n;
  //n = omp_get_max_threads();

  //printf("threads: %d", n);

  
  long sum[NUM] = {};
  //int x[NUM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  int x[NUM];
  long adds;
  for (int a=0; a<NUM; a++){
    x[a] = a+1;
    //printf("num:%d\n",a);
  }

  
   #pragma omp parallel reduction(+:adds)
    {
  
  for(int i = 0; i < NUM; i++){
    sum[i] = 0;
    adds = 0;
    #pragma omp firstprivate(adds),for
    //#pragma omp parallel for firstprivate(i)
    for(int j = 0; j <= i; j++ ){
      adds += x[j];
      //sum[i] = sum[i] + x[j];
      //sum[i] = sum[i] + x[j];
    }
    sum[i] = adds;
  }
    }
    
    for (int k= 0; k< NUM; k++){
     printf("%lf\n", sum[k]);
    }
    
    
}
