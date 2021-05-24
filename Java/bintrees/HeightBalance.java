public class HeightBalance {
    public static boolean isBalanced(BinaryTreeNode<Integer> tree) {
        return heightBalanced(tree) >= 0;
    }

    private static int heightBalanced(BinaryTreeNode<Integer> tree) {
        if (tree == null){
            return 0;
        }

        int leftHeight = heightBalanced(tree.left);
        if (leftHeight < 0) {
            return -1;
        }

        int rightHeight = heightBalanced(tree.right);
        if (rightHeight < 0) {
            return -1;
        }

        if (Math.abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        else {
            return 1 + Math.max(leftHeight, rightHeight);
        }
    }
}
