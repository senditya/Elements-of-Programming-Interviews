import java.util.List;

public class PreorderMarkerReconstruction {
    private static int preorderIndex = 0;

    public static BinaryTreeNode<Integer> reconstructPreorder(List<Integer> preorder) {
        if (preorder.size() == 0) {
            return null;
        } else {
            preorderIndex = 0;
            return getTree(preorder);
        }
    }

    private static BinaryTreeNode<Integer> getTree(List<Integer> preorder) {
        Integer data = preorder.get(preorderIndex++);
        if (data == null) {
            return null;
        } else {
            return new BinaryTreeNode<>(
                data,
                getTree(preorder),
                getTree(preorder)
            );
        }
    }
}
