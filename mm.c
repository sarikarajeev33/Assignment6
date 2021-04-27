// HEADER HERE :)

#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include "mm.h"
#include "fcycmmt.h"
#include "clock.h"


/* whether or not fcyc should clear the cache */
static const int CLEARCACHE=1;  

/* global arrays [ ok for this kind of hacking, but not in production ] */
array ga, gb, gc;

/* purpose: check the result array for correctness 
 * input: the product array, c, and its size, n
 * returns: nothing (complains in an error message if result is wrong)
 */
void checkresult(array c, int n)
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (c[i][j] != (double)n) 
      {
        printf("Error: bad number (%f) in result matrix (%d,%d)\n", 
            c[i][j], i, j);
        fflush(stdout);
        exit(0);
      }
}


/* purpose: Run function f and return clocks per inner loop iteration 
 * input: a function, f, and the matrix size, n
 * returns: the number of cycles taken per inner loop iteration
 */
double run(test_funct f, int n, int t)
{
  double cpi;

  cpi = fcyc(f, n, t, CLEARCACHE) / (n*n*n);
  checkresult(gc, n);
  return cpi;
}


/* purpose: reset result array to zero 
 * input: the array, c, and its size, n
 * returns: the array updated to all zeros.
 */
void reset(array c, int n)
{
  int i,j;
  
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++) 
      c[i][j] = 0.0;
}


/* purpose: initialize input arrays to 1 
 * input: the input arrays, a and b, and their size, n
 * returns: the arrays updated to all ones.
 */
void init(array a, array b, int n) 
{
  int i,j;
  
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++) 
    {
      a[i][j] = 1.0;
      b[i][j] = 1.0;
    }
  }
}


/* purpose: print an array 
 * input:   an array, a, and its size, n
 * returns: nothing (printing is a side effect)
 */
void printarray(array a, int n)
{
  int i, j;

  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++) 
      printf("%5.1f ", a[i][j]);
    
    printf("\n");
  }
}


/* purpose: Stores ga * gb into gc 
 * input: n - the size of on side of ga, gb, and gc
 *        num_threads - the number of threads to use to do the math
 * returns: nothing (gc is updated as a side effect)
 * FIXME!
 */
void multiply(int n, int num_threads) 
{


}


/* purpose: test the multiplication of two 2x2 matricies 
 * input: nothing (the test is hard coded)
 * returns: nothing (prints result to standard out)
 */
void test()
{   


  ga[0][0] = 1;
  ga[0][1] = 2;
  ga[1][0] = 3;
  ga[1][1] = 4; 
  gb[0][0] = 5;
  gb[0][1] = 6;
  gb[1][0] = 7;
  gb[1][1] = 8;
  printf("product of \n");
  printarray(ga, 2); 
  printf("and\n"); 
  printarray(gb, 2);
  multiply(2,1);
  printf("=\n");
  printarray(gc, 2);
  
  if (gc[0][0] == 19 && gc[0][1] == 22 && gc[1][0] == 43 && gc[1][1] == 50)
    printf("Passed!!\n");
  else
    printf("Fail!!\n");
}   
      
      

/* 
 * Run matrix multiply and display performance
 * as clock cycles per inner loop iteration.
 */ 
int main(int argc, char *argv[])
{
  int n;
  long threads; 

  long squares=0x1;
  while(squares < INT_MAX){
    squares |= squares << 2;
  }

  if( argc < 2 ){
    printf("Usage: %s threads\n",argv[0]);
    printf("\tthreads must be a square power of two\n");
    exit(-1);
  }

  if (sscanf(argv[1],"%ld",&threads) < 1){
    printf("Number of threads must be a square power of two\n");
    exit(-2);
  }

  if ( (threads & (threads - 1)) != 0 ){
    printf("Number of threads must be a square power of two\n");
    exit(-3);
  }

  if ( (threads & squares) != threads ){
    printf("Number of threads must be a square power of two\n");
    exit(-4);
  }




  init(ga, gb, MAXN);

//  test();
//  exit(0);

  printf("matmult cycles/loop iteration\n");
  fflush(stdout);
  for (n = MINN; n <= MAXN; n *= INCN) 
  {  
    printf("%3d ", n);
    
    printf("%9.2f ", run(multiply, n, threads));
    printf("\n");
    fflush(stdout);
  }

  exit(0);
}
 
