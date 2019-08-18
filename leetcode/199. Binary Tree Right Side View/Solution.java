import java.util.ArrayList;
import java.util.List;

//Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public List<Integer> rightSideView(TreeNode root) {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root==null) return res;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode head = q.remove();
                if (i==size-1) res.add(head.val);
                if (head.left != null) q.add(head.left);
                if (head.right != null) q.add(head.right);
            }
        }
        return res;
    }
}
