import java.util.List;

public class TreeReconstruction {
    private static int preorderIndex;

    public static BinaryTreeNode<Integer> binaryTreeFromPreorderInorder(
                                                List<Integer> preorder,
                                                List<Integer> inorder) {
        preorderIndex = 0;
        return getTree(preorder, inorder, 0, inorder.size() - 1);
    }

    private static BinaryTreeNode<Integer> getTree(List<Integer> preorder,
                                                   List<Integer> inorder,
                                                   int inorderStart,
                                                   int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return null;
        } else {
            int data = preorder.get(preorderIndex++);
            int inorderRootIndex = findIndex(inorder, inorderStart, inorderEnd, data);
            return new BinaryTreeNode<>(
                data,
                getTree(preorder, inorder, inorderStart, inorderRootIndex - 1),
                getTree(preorder, inorder, inorderRootIndex + 1, inorderEnd)
            );
        }
    }

    private static int findIndex(List<Integer> inorder, int inorderStart, int inorderEnd, int target) {
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder.get(i) == target) return i;
        }
        return -1;
    }
}
