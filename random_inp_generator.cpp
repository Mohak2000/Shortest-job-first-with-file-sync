#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  for (int i = 1; i <= 250; i++) {
    cout<< 1 + (rand() % 5);
  }
  return 0;
}
