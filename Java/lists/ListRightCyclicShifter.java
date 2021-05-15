public class ListRightCyclicShifter {
    public static ListNode<Integer> cyclicallyRightShiftList(ListNode<Integer> L,
                                                             int k) {
        if (L == null) return null;

        ListNode<Integer> frontCursor = L;
        int size = 0;
        while (frontCursor != null) {
            size++;
            frontCursor = frontCursor.next;
        }
        k = k % size;
        if (k == 0) return L;

        frontCursor = L;
        for (int i = 0; i < k; i++) {
            frontCursor = frontCursor.next;
        }

        if (frontCursor == null) {
            return L;
        }

        ListNode<Integer> backCursor = L;
        while (frontCursor.next != null) {
            backCursor = backCursor.next;
            frontCursor = frontCursor.next;
        }

        ListNode<Integer> newHead = backCursor.next;
        ListNode<Integer> newTail = backCursor;

        newTail.next = null;
        frontCursor.next = L;
        return newHead;
    }
}
