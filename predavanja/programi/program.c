#include <stdio.h>

int f(int n) {
  printf("[%d] ", n);
  return n;
}
int main() {
  printf("[%d %d]\n", f(5), f(11));
  return 0;
}
