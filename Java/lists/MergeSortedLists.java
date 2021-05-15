public class MergeSortedLists {
    public static ListNode<Integer> mergeTwoSortedLists(ListNode<Integer> L1,
                                                      ListNode<Integer> L2) {
        if (L1 == null) {
            return L2;
        } else if (L2 == null) {
            return L1;
        }

        ListNode<Integer> mergeHead;
        ListNode<Integer> L1Cursor = L1;
        ListNode<Integer> L2Cursor = L2;
        if (L1.data < L2.data) {
            mergeHead = L1;
            L1Cursor = L1.next;
        } else {
            mergeHead = L2;
            L2Cursor = L2.next;
        }

        ListNode<Integer> mergeCursor = mergeHead;

        while (L1Cursor != null && L2Cursor != null) {
            if (L1Cursor.data < L2Cursor.data) {
                mergeCursor.next = L1Cursor;
                L1Cursor = L1Cursor.next;
            } else {
                mergeCursor.next = L2Cursor;
                L2Cursor = L2Cursor.next;
            }

            mergeCursor = mergeCursor.next;
        }

        if (L1Cursor == null) {
            mergeCursor.next = L2Cursor;
        } else {
            mergeCursor.next = L1Cursor;
        }

        return mergeHead;
    }
}
