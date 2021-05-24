import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

public class IterativeInOrderTraversal {
    public static List<Integer> inorderTraversal(BinaryTreeNode<Integer> tree) {
        List<Integer> traversal = new ArrayList<>();
        Deque<TraversalNode> stack = new ArrayDeque<>();

        stack.push(new TraversalNode(tree));

        while (!stack.isEmpty()) {
            TraversalNode top = stack.peek();
            if (top.node == null) {
                stack.pop();
            } else if (!top.leftTraveled) {
                stack.push(new TraversalNode(top.node.left));
                top.leftTraveled = true;
            } else {
                traversal.add(stack.pop().node.data);
                stack.push(new TraversalNode(top.node.right));
            }
        }

        return traversal;
    }

    private static class TraversalNode {
        BinaryTreeNode<Integer> node;
        boolean leftTraveled = false;

        TraversalNode(BinaryTreeNode<Integer> node) {
            this.node = node;
        }
    }
}
