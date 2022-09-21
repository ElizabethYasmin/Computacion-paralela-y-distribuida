#include <iostream>
#include <chrono>

#define MAX 4

double A[MAX][MAX], x[MAX], y[MAX];

int main()
{
  auto start = std::chrono::high_resolution_clock::now();
  int i, j;
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[i];
  auto end = std::chrono::high_resolution_clock::now();
  auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  std::cout << int_s << " microseconds\n";
  return 0;
}