import java.util.LinkedList;
import java.util.List;

public class Solution2 {

    public static void main(String[] args) {
        Solution s = new Solution();
        String res = s.getPermutation(3, 3);
        System.out.println(res);
    }

}

class Solution {
    public String getPermutation(int n, int k) {
        k--;

        int[] factorial = new int[n];
        factorial[0] = 1;
        for (int i = 1; i < n; i++)
            factorial[i] = factorial[i - 1] * i;

        List<Integer> nums = new LinkedList<>();
        for (int i = 1; i <= n; i++)
            nums.add(i);

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = n - 1; i >= 0; i--) {
            int idx = k / factorial[i];
            stringBuilder.append(nums.remove(idx));
            k -= idx * factorial[i];
        }

        return stringBuilder.toString();
    }
}
