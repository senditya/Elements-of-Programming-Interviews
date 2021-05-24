public class InOrderSuccessor {
    public static BinaryTree<Integer> findSuccessor(BinaryTree<Integer> node) {
        if (node.right != null) {
            return findLeftMostChild(node.right);
        } else {
            return closestRightAncestor(node);
        }
    }

    private static BinaryTree<Integer> findLeftMostChild(BinaryTree<Integer> node) {
        if (node.left == null) {
            return node;
        } else {
            return findLeftMostChild(node.left);
        }
    }

    private static BinaryTree<Integer> closestRightAncestor(BinaryTree<Integer> node) {
        if (node.parent == null) {
            return null;
        } else if (node.parent.left == node) {
            return node.parent;
        } else {
            return closestRightAncestor(node.parent);
        }
    }

    private static class BinaryTree<T> {
        T data;
        BinaryTree<T> left, right;
        BinaryTree<T> parent;

        BinaryTree(T data, BinaryTree<T> left, BinaryTree<right>, BinaryTree<T> parent) {
            this.data;
            this.left = left;
            this.right = right;
            this.parent = parent;
        }
    }
}
