import java.util.List;
import java.util.ArrayList;

public class TreeLeaves {
    public static List<BinaryTreeNode<Integer>> createListOfLeaves(BinaryTreeNode<Integer> tree) {
        List<BinaryTreeNode<Integer>> leaves = new ArrayList<>();
        getLeaves(tree, leaves);
        return leaves;
    }

    private static void getLeaves(BinaryTreeNode<Integer> tree,
                                  List<BinaryTreeNode<Integer>> leaves) {
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
