import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class BinaryTreeTraversal {
    public static void preOrderTraverse(BinaryTreeNode<Integer> root, List<Integer> list) {
        if (root != null) {
            list.add(root.data);
            preOrderTraverse(root.left, list);
            preOrderTraverse(root.right, list);
        }
    }

    public static void inOrderTraverse(BinaryTreeNode<Integer> root, List<Integer> list) {
        if (root != null) {
            inOrderTraverse(root.left, list);
            list.add(root.data);
            inOrderTraverse(root.right, list);
        }
    }

    public static void postOrderTraverse(BinaryTreeNode<Integer> root, List<Integer> list) {
        if (root != null) {
            postOrderTraverse(root.left, list);
            postOrderTraverse(root.right, list);
            list.add(root.data);
        }
    }

    public static void main(String[] args) {
        BinaryTreeNode<Integer> root =
        new BinaryTreeNode<>(
            314,
            new BinaryTreeNode<>(
                6,
                new BinaryTreeNode<>(
                    271,
                    new BinaryTreeNode<>(28),
                    new BinaryTreeNode<>(0)
                ),
                new BinaryTreeNode<>(
                    561,
                    null,
                    new BinaryTreeNode<>(
                        3,
                        new BinaryTreeNode<>(17),
                        null
                    )
                )
            ),
            new BinaryTreeNode<>(
                6,
                new BinaryTreeNode<>(
                    2,
                    null,
                    new BinaryTreeNode<>(
                        1,
                        new BinaryTreeNode<>(
                            401,
                            null,
                            new BinaryTreeNode<>(641)
                        ),
                        new BinaryTreeNode<>(257)
                    )
                ),
                new BinaryTreeNode<>(
                    271,
                    null,
                    new BinaryTreeNode<>(28)
                )
            )
        );

        List<Integer> preOrder = new ArrayList<>();
        preOrderTraverse(root, preOrder);
        System.out.println("Pre-Order: " + Arrays.toString(preOrder.toArray()));

        List<Integer> inOrder = new ArrayList<>();
        inOrderTraverse(root, inOrder);
        System.out.println("In-Order: " + Arrays.toString(inOrder.toArray()));

        List<Integer> postOrder = new ArrayList<>();
        postOrderTraverse(root, postOrder);
        System.out.println("Post-Order: " + Arrays.toString(postOrder.toArray()));
    }
}
