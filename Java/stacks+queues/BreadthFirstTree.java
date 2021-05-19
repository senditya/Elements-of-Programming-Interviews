import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

public class BreadthFirstTree {
    public static List<List<Integer>>
    binaryTreeDepthOrder(BinaryTreeNode<Integer> tree) {
        List<List<Integer>> levelsList = new ArrayList<>();
        if (tree == null) return levelsList;

        Deque<QueueEntry> queue = new ArrayDeque<>();
        queue.addLast(new QueueEntry(tree, 0));

        while (!queue.isEmpty()) {
            // pull from queue
            QueueEntry qe = queue.removeFirst();

            // if list corresponding to entry not in master list, create it;
            // enter entry into that list
            if (levelsList.size() <= qe.level) {
                levelsList.add(new ArrayList<>());
            }
            levelsList.get(qe.level).add(qe.node.data);

            // push children of entry into queue
            if (qe.node.left != null) {
                queue.addLast(new QueueEntry(qe.node.left, qe.level + 1));
            }
            if (qe.node.right != null) {
                queue.addLast(new QueueEntry(qe.node.right, qe.level + 1));
            }
        }

        return levelsList;
    }

    private static class QueueEntry {
        final BinaryTreeNode<Integer> node;
        final int level;

        QueueEntry(BinaryTreeNode<Integer> node, int level) {
            this.node = node;
            this.level = level;
        }
    }

    private static class BinaryTreeNode<T> {
        T data;
        BinaryTreeNode<T> left, right;

        BinaryTreeNode(T data,
                       BinaryTreeNode<T> left, BinaryTreeNode<T> right) {
            this.data = data;
            this.left = left;
            this,right = right;
        }
    }
}
