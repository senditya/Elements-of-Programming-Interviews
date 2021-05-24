import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class TreeExterior {
    public static List<BinaryTreeNode<Integer>> exteriorBinaryTree(BinaryTreeNode<Integer> tree) {
        if (tree == null) return Collections.emptyList();
        if (tree.left == null && tree.right == null) return Collections.singletonList(tree);

        List<BinaryTreeNode<Integer>> leftExterior = new ArrayList<>();
        List<BinaryTreeNode<Integer>> leaves = new ArrayList<>();
        List<BinaryTreeNode<Integer>> rightExterior = new ArrayList<>();

        getLeft(tree.left, leftExterior);

        getRight(tree.right, rightExterior);
        Collections.reverse(rightExterior);

        getLeaves(tree, leaves);
        if (leftExterior.size() > 0) leaves.remove(0);
        if (rightExterior.size() > 0) leaves.remove(leaves.size() - 1);

        leftExterior.add(0, tree);
        leftExterior.addAll(leaves);
        leftExterior.addAll(rightExterior);

        return leftExterior;
    }

    private static void getLeft(BinaryTreeNode<Integer> tree, List<BinaryTreeNode<Integer>> leftExterior) {
        if (tree != null) {
            leftExterior.add(tree);
            if (tree.left != null) {
                getLeft(tree.left, leftExterior);
            } else {
                getLeft(tree.right, leftExterior);
            }
        }
    }

    private static void getRight(BinaryTreeNode<Integer> tree, List<BinaryTreeNode<Integer>> rightExterior) {
        if (tree != null) {
            rightExterior.add(tree);
            if (tree.right != null) {
                getRight(tree.right, rightExterior);
            } else {
                getRight(tree.left, rightExterior);
            }
        }
    }

    private static void getLeaves(BinaryTreeNode<Integer> tree, List<BinaryTreeNode<Integer>> leaves) {
        if (tree != null) {
            if (tree.left == null && tree.right == null) {
                leaves.add(tree);
            } else {
                getLeaves(tree.left, leaves);
                getLeaves(tree.right, leaves);
            }
        }
    }
}
