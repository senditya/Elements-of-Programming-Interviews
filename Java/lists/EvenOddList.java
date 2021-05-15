public class EvenOddList {
    public static ListNode<Integer> evenOddMerge(ListNode<Integer> L){
        if (L == null) return null;
        if (L.next == null || L.next.next == null) return L;

        ListNode<Integer> evenCursor = L;
        ListNode<Integer> oddHead = L.next;
        ListNode<Integer> oddCursor = oddHead;

        while (oddCursor != null && oddCursor.next != null && evenCursor.next != null) {
            ListNode<Integer> nextOdd = oddCursor.next.next;
            ListNode<Integer> nextEven = evenCursor.next.next;

            evenCursor.next = nextEven;
            oddCursor.next = nextOdd;

            evenCursor = nextEven;
            oddCursor = nextOdd;
        }

        evenCursor.next = oddHead;

        return L;
    }
}
