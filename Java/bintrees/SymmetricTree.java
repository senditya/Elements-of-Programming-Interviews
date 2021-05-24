public class SymmetricTree {
    public static boolean isSymmetric(BinaryTreeNode<Integer> tree) {
        if (tree == null) return true;
        else return areMirrorImages(tree.left, tree.right);
    }

    private static boolean areMirrorImages(BinaryTreeNode<Integer> leftTree,
                                           BinaryTreeNode<Integer> rightTree) {
        if (leftTree == null && rightTree == null) return true;
        if (leftTree == null || rightTree == null) return false;
        return (leftTree.data.equals(rightTree.data)) &&
               areMirrorImages(leftTree.left, rightTree.right) &&
               areMirrorImages(leftTree.right, rightTree.left);
    }
}
