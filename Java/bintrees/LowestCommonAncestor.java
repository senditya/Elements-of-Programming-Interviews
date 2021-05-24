import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;

public class LowestCommonAncestor {
    public static BinaryTreeNode<Integer> lca(BinaryTreeNode<Integer> tree,
                                              BinaryTreeNode<Integer> node0,
                                              BinaryTreeNode<Integer> node1) {
        List<BinaryTreeNode<Integer>> pathNode0 = getPath(tree, node0);
        List<BinaryTreeNode<Integer>> pathNode1 = getPath(tree, node1);

        int i = pathNode0.size() - 1;
        int j = pathNode1.size() - 1;

        while (i > 0 && j > 0) {
            if (pathNode0.get(--i) != pathNode1.get(--j)) {
                return pathNode0.get(i+1);
            }
        }

        return pathNode0.get(i);
    }

    private static List<BinaryTreeNode<Integer>> getPath(
                                                    BinaryTreeNode<Integer> root,
                                                    BinaryTreeNode<Integer> node
    ) {
        Deque<BinaryTreeSearchNode> stack = new ArrayDeque<>();
        stack.push(new BinaryTreeSearchNode(root));

        while (!stack.isEmpty()) {
            BinaryTreeSearchNode top = stack.peek();

            if (top.node.equals(node)) {
                break;
            } else if (!top.leftSearched && top.node.left != null) {
                stack.push(new BinaryTreeSearchNode(top.node.left));
                top.leftSearched = true;
            } else if (!top.rightSearched && top.node.right != null) {
                stack.push(new BinaryTreeSearchNode(top.node.right));
                top.rightSearched = true;
            } else {
                stack.pop();
            }
        }

        if (stack.isEmpty()) {
            throw new NoSuchElementException();
        } else {
            List<BinaryTreeNode<Integer>> path = new ArrayList<>();
            while (!stack.isEmpty()) {
                path.add(stack.pop().node);
            }
            return path;
        }
    }

    private static class BinaryTreeSearchNode {
        BinaryTreeNode<Integer> node;
        boolean leftSearched = false;
        boolean rightSearched = false;

        BinaryTreeSearchNode(BinaryTreeNode<Integer> node) {
            this.node = node;
        }
    }
}
