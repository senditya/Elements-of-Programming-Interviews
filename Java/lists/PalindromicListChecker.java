public class PalindromicListChecker {
    public static boolean isLinkedListAPalindrome(ListNode<Integer> L) {
        if (L == null || L.next == null) return true;

        ListNode<Integer> cursor = L;
        int size = 0;
        while (cursor != null) {
            size++;
            cursor = cursor.next;
        }

        int halfwayPoint = size/2;
        if (size % 2 == 1) halfwayPoint++;

        cursor = L;
        for (int i = 1; i < halfwayPoint; i++) {
            cursor = cursor.next;
        }

        ListNode<Integer> secondCursor = reverse(cursor.next);
        cursor = L;

        for (int i = 0; i < size/2; i++) {
            if (!cursor.data.equals(secondCursor.data)) {
                return false;
            } else {
                cursor = cursor.next;
                secondCursor = secondCursor.next;
            }
        }
        return true;
    }

    private static ListNode<Integer> reverse(ListNode<Integer> head) {
        if (head == null) return null;
        if (head.next == null) return head;

        ListNode<Integer> current = head;
        ListNode<Integer> next = current.next;
        head.next = null;

        while (next != null) {
            ListNode<Integer> temp = next.next;
            next.next = current;
            current = next;
            next = temp;
        }

        return current;
    }
}
