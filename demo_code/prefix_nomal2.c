#include <stdio.h>
//#include <omp.h>
#define NUM 10

int main(int argc, char** argv){
  int n;
  //n = omp_get_max_threads();

  //printf("threads: %d", n);

  
  long sum[NUM];
  
  for(int b=0; b<NUM; b++){
    sum[b] = 0;
  }
  
  int x[NUM];
  long adds = 0;
  int last;
  for (int a=0; a<NUM; a++){
    x[a] = a;
  }

  //   #pragma omp parallel reduction(+:adds)
   
      
  //#pragma omp firstprivate(adds),for 
  for(int i = 1; i <= NUM+1; i++){
    
    adds = sum[i-1];   
    sum[i] = adds + x[i];
    //sum[i] = 0;
    //adds = 0;
    //#pragma omp firstprivate(adds),for
    //#pragma omp parallel for firstprivate(i)
    // for(int j = 0; j <= i; j++ ){
    //adds += x[j];
      //sum[i] = sum[i] + x[j];
      //sum[i] = sum[i] + x[j];
    //}
    //sum[i] = adds;
  }

  for (int k= 0; k< NUM; k++){
    printf("%ld\n", sum[k]);
  }
}
