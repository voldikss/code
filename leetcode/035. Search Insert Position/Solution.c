#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target);

int main() {
  int nums[2] = {1, 3};
  int numsSize = 2;
  int target = 3;
  int position = searchInsert(nums, numsSize, target);
  printf("%d\n", position);
}

int searchInsert(int *nums, int numsSize, int target) {
  if (target < nums[0])
    return 0;
  if (target > nums[numsSize - 1])
    return numsSize;
  for (int i = 0; i < numsSize - 1; i++) {
    if (nums[i] == target)
      return i;
    if (nums[i] < target && nums[i + 1] >= target)
      return i + 1;
  }
  return 0;
}
