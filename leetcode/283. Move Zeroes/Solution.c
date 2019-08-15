#include <stdio.h>

void moveZeroes(int *nums, int numsSize);

int main() {
  int nums[5] = {0,1,0,3,12};
  int numsSize = 5;
  moveZeroes(nums, 5);
  for (int i=0; i < numsSize; i++)
    printf("%d\n", nums[i]);
}

void moveZeroes(int *nums, int numsSize) {
  int index = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      nums[index] = nums[i];
      index++;
    }
  }
  for (int i = index; i < numsSize; i++)
    nums[i] = 0;
}
