public class ListOverlap {
    public static ListNode<Integer>
    overlappingNoCycleLists(ListNode<Integer> l0, ListNode<Integer> l1) {
        if (l0 == l1) {
            return l0;
        } else if (l0 == null || l1 == null) {
            return null;
        }

        ListNode<Integer> l0Cursor = l0;
        int l0Size = 1;

        ListNode<Integer> l1Cursor = l1;
        int l1Size = 1;

        while (l0Cursor.next != null || l1Cursor.next != null) {
            if (l0Cursor.next != null) {
                l0Cursor = l0Cursor.next;
                l0Size++;
            }
            if (l1Cursor.next != null) {
                l1Cursor = l1Cursor.next;
                l1Size++;
            }
        }

        // If they don't even overlap on the last node, there is no overlap
        if (l1Cursor != l0Cursor) {
            return null;
        }

        // If they do overlap, return first point of overlap
        ListNode<Integer> larger;
        ListNode<Integer> smaller;
        int diff;
        if (l0Size < l1Size) {
            larger = l1;
            smaller = l0;
            diff = l1Size - l0Size;
        } else {
            larger = l0;
            smaller = l1;
            diff = l0Size - l1Size;
        }

        while (diff > 0) {
            larger = larger.next;
            diff--;
        }

        while (larger != smaller) {
            larger = larger.next;
            smaller = smaller.next;
        }

        return larger;
    }
}
