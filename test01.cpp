#include <cstdlib.h>
#include <cstdio.h>

void init(double *vector, long n, double value){
  for (int i=0; i < n; ++i) vector[i] = value;
}

void dotproduct(double *A, double *B, double *C, long n){
  #pragma clang loop vectorize(enable)
  for (int i=0; i < n; ++i) {
     C[i] = A[i] * B[i] + 3.0 * B[i];
     B[i] += A[i] * C[i];
  }
}

void printvector(double *vector, long n){
  for(int i=0; i < n; ++i) printf("Item %d: %f\n", i, vector[i]);
}




int main(int argc, char* argv[])
{
  long n = 1024;

  double *A = (double*)malloc(n*sizeof(double));
  double *B = (double*)malloc(n*sizeof(double));
  double *C = (double*)malloc(n*sizeof(double));

  init(A, n, 5.0);
  init(B, n, 2.0);
  dotproduct(A, B, C, n);
//  printvector(C, n);
  free(A); free(B); free(C);
  return 0;
}
