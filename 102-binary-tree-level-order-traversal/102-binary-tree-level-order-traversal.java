/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        
        // BFS iterative:
        
        
        List<List<Integer>> res = new ArrayList<>();
		if (root == null)
			return res;
		Queue<TreeNode> q = new LinkedList<>();
		q.add(root);
		while(!q.isEmpty()) {
			int levelSize = q.size();
			List<Integer> currLevel = new ArrayList<>();
			for(int i = 0; i < levelSize; i++) {
				TreeNode currNode = q.poll();
				currLevel.add(currNode.val);
				if (currNode.left != null)
					q.add(currNode.left);
				if (currNode.right != null)
					q.add(currNode.right);
			}
			res.add(currLevel);
		}
		return res;
    }
}