public class LowestCommonPointedAncestor {
    public static BinaryTree<Integer> lca(BinaryTree<Integer> node0,
                                          BinaryTree<Integer> node1) {
        int distance0 = getDistanceFromRoot(node0);
        int distance1 = getDistanceFromRoot(node1);

        if (distance0 > distance1) {
            node0 = step(node0, distance0 - distance1);
        } else {
            node1 = step(node1, distance1 - distance0);
        }

        return findCommon(node0, node1);
    }

    private static int getDistanceFromRoot(BinaryTree<Integer> node) {
        int distance = 0;
        while (node.parent != null) {
            node = node.parent;
            distance++;
        }
        return distance;
    }

    private static BinaryTree<Integer> step(BinaryTree<Integer> node, int steps) {
        while (steps-- > 0) {
            node = node.parent;
        }
        return node;
    }

    private static BinaryTree<Integer> findCommon(BinaryTree<Integer> node0,
                                                  BinaryTree<Integer> node1) {
        while (!node0.equals(node1)) {
            node0 = node0.parent;
            node1 = node1.parent;
        }
        return node0;
    }

    private static class BinaryTree<T> {
        T data;
        BinaryTree<T> left, right;
        BinaryTree<T> parent;
    }
}
