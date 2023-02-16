class Solution {
  public int pivotIndex(int[] nums) {
    int noofnums = nums.length, leftSum = 0, totalSum = 0;
    if(noofnums == 0) return -1;
    if(noofnums == 1) return 0;

    for(int num: nums) { totalSum += num; }
    for(int i = 0; i < noofnums; i++) {
      if(leftSum == totalSum - leftSum - nums[i])
        return i;
      leftSum += nums[i];
    }    
    return -1;
  }
}