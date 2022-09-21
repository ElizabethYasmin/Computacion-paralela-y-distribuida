#include <iostream>
#include <chrono>

int main()
{
  for (unsigned int n = 10; n < (1 << 10); n += 10) {
    double A[n][n], x[n], y[n];
    int i, j;

    auto start = std::chrono::high_resolution_clock::now();

    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        y[i] += A[i][j] * x[i];

    auto end = std::chrono::high_resolution_clock::now();

    auto int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << n << " " << int_s << " ";

    start = std::chrono::high_resolution_clock::now();

    for (j = 0; j < n; j++)
      for (i = 0; i < n; i++)
        y[i] += A[i][j] * x[i];

    end = std::chrono::high_resolution_clock::now();

    int_s = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << int_s << "\n";
  }

  return 0;
}