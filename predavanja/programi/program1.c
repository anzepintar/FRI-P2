#include <stdio.h>

int f(int n) {
  printf("[%d] ", n);
  return n;
}
int main() {
  int a = f(5);
  int b = f(11);
  printf("[%d %d]\n", a, b);
  return 0;
}
