#include <stdio.h>

int main() {
   int n = 10; // number of Fibonacci numbers to generate
   int prev = 0, curr = 1, next;
   
   for (int i = 0; i < n; i++) {
      printf("%d ", curr);
      next = prev + curr;
      prev = curr;
      curr = next;
   }
   
   return 0;
}
