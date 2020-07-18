import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        int[] nums = { 1, 0, -1, 0, -2, 2 };
        int target = 0;
        List<List<Integer>> res = new Solution().fourSum(nums, target);
        System.out.println(res);
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 4)
            return res;
        for (int i = 0; i <= nums.length - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j <= nums.length - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int lp = j + 1;
                if (nums[i] + nums[j] + nums[lp] + nums[lp + 1] > target)
                    continue;
                int rp = nums.length - 1;
                if (nums[i] + nums[j] + nums[rp] + nums[rp - 1] < target)
                    continue;
                while (lp < rp) {
                    int sum = nums[i] + nums[j] + nums[lp] + nums[rp];
                    if (sum < target)
                        lp++;
                    else if (sum > target)
                        rp--;
                    else {
                        res.add(Arrays.asList(nums[i], nums[j], nums[lp], nums[rp]));
                        while (lp < rp && nums[lp] == nums[lp + 1])
                            lp++;
                        while (lp < rp && nums[rp] == nums[rp - 1])
                            rp--;
                        lp++;
                        rp--;
                    }
                }
            }
        }
        return res;
    }
}
