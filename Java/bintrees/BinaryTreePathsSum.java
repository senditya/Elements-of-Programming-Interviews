import java.util.Deque;
import java.util.ArrayDeque;

public class BinarTreesPathSum {
    public static int sumRootToLeaf(BinaryTreeNode<Integer> tree) {
        return sumSubtree(tree, 0);
    }

    private static int sumSubtree(BinaryTreeNode<Integer> tree, int seed) {
        if (tree == null) {
            return 0;
        }

        seed = 2 * seed + tree.data;

        if (tree.left == null && tree.right == null) {
            return seed;
        }

        return sumSubtree(tree.left, seed) + sumSubtree(tree.right, seed);
    }

    public static int sumRootToLeafIterative(BinaryTreeNode<Integer> tree) {
        int sum = 0;
        int accumulator = 0;

        Deque<PathNode> stack = new ArrayDeque<>();
        if (tree != null) {
            stack.push(new PathNode(tree));
            accumulator = tree.data;
        }

        while (!stack.isEmpty()) {
            PathNode top = stack.peek();

            if (!top.leftDone && top.node.left != null) {
                stack.push(new PathNode(top.node.left));
                top.leftDone = true;
                accumulator = 2*accumulator + top.node.left.data;
            } else if (!top.rightDone && top.node.right != null) {
                stack.push(new PathNode(top.node.right));
                top.rightDone = true;
                accumulator = 2*accumulator + top.node.right.data;
            } else {
                if (top.node.left == null && top.node.right == null) {
                    sum += accumulator;
                }
                stack.pop();
                accumulator /= 2;
            }
        }

        return sum;
    }

    private static class PathNode {
        BinaryTreeNode<Integer> node;
        boolean leftDone = false;
        boolean rightDone = false;

        PathNode(BinaryTreeNode<Integer> node) {
            this.node = node;
        }
    }
}
