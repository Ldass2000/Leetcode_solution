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
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList list= new ArrayList();
        
        rightdikhnahai(root,0,list);
        
        return list;
    }
    
    public void   rightdikhnahai (TreeNode root, int level,ArrayList list)
    {
        if(root==null) return;
        
        if(list.size()==level)
        {
            list.add(root.val);
        }
        
          rightdikhnahai(root.right,level+1,list);
          rightdikhnahai(root.left,level+1,list);
    }
}