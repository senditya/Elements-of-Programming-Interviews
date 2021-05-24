import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class IterativeInOrderParentPointer {
    public static List<Integer> inorderTraversal(BinaryTree<Integer> tree) {
        BinaryTree<Integer> cursor = tree;
        List<Integer> traversal = new ArrayList<>();

        while (cursor != null) {
            if (cursor.left != null) {
                cursor = cursor.left;
            } else {
                while (cursor != null && cursor.right == null) {
                    traversal.add(cursor.data);
                    cursor = findClosestRightParent(cursor);
                }

                if (cursor != null) {
                    traversal.add(cursor.data);
                    cursor = cursor.right;
                }
            }
        }

        return traversal;
    }

    private static BinaryTree<Integer> findClosestRightParent(BinaryTree<Integer> node) {
        if (node == null) return null;

        while (node.parent != null) {
            if (node == node.parent.left) {
                return node.parent;
            } else {
                node = node.parent;
            }
        }

        return null;
    }

    private static class BinaryTree<T> {
        T data;
        BinaryTree<T> left, right;
        BinaryTree<T> parent;

        BinaryTree(T data, BinaryTree<T> left, BinaryTree<T> right, BinaryTree<T> parent) {
            this.data = data;
            this.left = left;
            this.right = right;
            this.parent = parent;
        }
    }

    public static void main(String[] args) {
        BinaryTree<Integer> tree = new BinaryTree<>(1, null, null, null);
        List<Integer> traversal = inorderTraversal(tree);
        System.out.println(Arrays.toString(traversal.toArray()));
    }
}
