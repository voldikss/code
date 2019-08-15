#include <stdio.h>

int removeElement(int *nums, int numSize, int val) {
  int count = 0;
  for (int i = 0; i < numSize; i++) {
    if (nums[i] != val) {
      nums[count] = nums[i];
      count++;
    }
  }
  return count;
}

int main() {
  int nums[8] = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int len = removeElement(nums, 8, val);
  printf("%d\n", len);
}
