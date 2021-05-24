public class LeafAtDistance {
    public static boolean hasPathSum(BinaryTreeNode<Integer> tree,
                                     int targetSum) {
        return leafHasSum(tree, targetSum, 0);
    }

    private static boolean leafHasSum(BinaryTreeNode<Integer> tree, int targetSum, int subSum) {
        if (tree == null) {
            return false;
        }

        subSum += tree.data;

        if (tree.left == null && tree.right == null && subSum == targetSum) {
            return true;
        }

        return leafHasSum(tree.left, targetSum, subSum) ||
               leafHasSum(tree.right, targetSum, subSum);
    }
}
