public class KthInOrderBinNode {
    public static BinaryTreeNode<Integer> findKthNodeBinaryTree(
                                            BinaryTreeNode<Integer> tree, int k
    ) {
        if (tree.left == null) {
            if (k == 1) return tree;
            else return findKthNodeBinaryTree(tree.right, k - 1);
        } else if (tree.left.size >= k) {
            return findKthNodeBinaryTree(tree.left, k);
        } else {
            k -= tree.left.size;
            if (k == 1) return tree;
            else return findKthNodeBinaryTree(tree.right, k-1);
        }
    }

    private static class BinaryTreeNode<T> {
        T data;
        BinaryTreeNode<T> left, right;
        int size;

        public BinaryTreeNode(T data, BinaryTreeNode<T> left,
                              BinaryTreeNode<T> right, int size) {
            this.data = data;
            this.left = left;
            this.right = right;
            this.size = size;
        }
    }
}
