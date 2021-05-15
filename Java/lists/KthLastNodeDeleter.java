public class KthLastNodeDeleter {
    public static ListNode<Integer> removeKthLast(ListNode<Integer> L, int k) {
        ListNode<Integer> further = L;
        for (int i = 0; i < k; i++) {
            further = further.next;
        }

        if (further == null) {
            return L.next;
        } else {
            further = further.next;
            ListNode<Integer> cursor = L;
            while (further != null) {
                cursor = cursor.next;
                further = further.next;
            }
            cursor.next = cursor.next.next;
            return L;
        }
    }
}
