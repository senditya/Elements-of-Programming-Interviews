public class TreeRightSibling {
    public static void constructRightSibling(BinaryTreeNode<Integer> tree) {
        if (tree != null && tree.left != null) {
            tree.left.next = tree.right;
            if (tree.next != null) {
                tree.right.next = tree.next.left;
            }
            constructRightSibling(tree.left);
            constructRightSibling(tree.right);
        }
    }

    private static class BinaryTreeNode<T> {
        T data;
        BinaryTreeNode<T> left, right;
        BinaryTreeNode<T> next;
    }
}
