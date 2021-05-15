public class SortedListDeduper {
    public static ListNode<Integer> removeDuplicates(ListNode<Integer> L) {
        if (L == null) return null;

        ListNode<Integer> currentCursor = L;
        ListNode<Integer> nextCursor = L.next;

        while (nextCursor != null) {
            if (currentCursor.data == nextCursor.data) {
                nextCursor = nextCursor.next;
            } else {
                currentCursor.next = nextCursor;
                currentCursor = nextCursor;
                nextCursor = currentCursor.next;
            }
        }
        currentCursor.next = null;

        return L;
    }
}
