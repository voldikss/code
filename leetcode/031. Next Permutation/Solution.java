import java.util.Arrays;

public class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length <= 1)
            return;

        int i = nums.length - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
            i--;

        // System.out.println(i);
        if (i > 0) {
            int j = nums.length - 1;
            while (j >= i && nums[j] <= nums[i - 1])
                j--;
            // System.out.println(j);
            int tmp = nums[j];
            nums[j] = nums[i - 1];
            nums[i - 1] = tmp;
        }

        reverse(nums, i);
        System.out.println(i);
        System.out.println(Arrays.toString(nums));
    }

    private void reverse(int[] nums, int start) {
        int m = start;
        int n = nums.length - 1;
        while (m < n) {
            int tmp = nums[n];
            nums[n] = nums[m];
            nums[m] = tmp;
            m++;
            n--;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] samples = {
                // {1},
                // {1, 3, 2},
                // {3, 2, 1},
                { 5, 1, 1 }, { 1, 2, 4, 5, 3 } };
        for (int[] sample : samples)
            s.nextPermutation(sample);
    }
}
