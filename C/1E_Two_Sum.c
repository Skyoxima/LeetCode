#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
  int* ans = (int*)malloc(2 * sizeof(int));
  int i, j;
  for(i = 0; i < numsSize - 1; i++) {
    for(j = i + 1; j < numsSize; j++) {
      if(nums[i] + nums[j] == target) {
        ans[0] = i;
        ans[1] = j;
      }
    }
  }
  
  return ans;
}

void main() {
  int nums[] = {3, 3};

  int* final = twoSum(nums, 2, 6);
  printf("%d %d", final[0], final[1]);
}