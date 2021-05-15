public class ListLoopScanner {
    public static ListNode<Integer> hasCycle(ListNode<Integer> head) {
        ListNode<Integer> slowCursor = step(head, 1, 1);
        ListNode<Integer> fastCursor = step(head, 2, 1);

        int slowSteps = 1;

        while (slowCursor != fastCursor) {
            slowCursor = step(slowCursor, 1, 1);
            slowSteps++;
            fastCursor = step(fastCursor, 2, 1);
        }

        if (slowCursor == null) {
            return null;
        }

        // At this point, it is confirmed that there is a loop
        ListNode<Integer> cursor = head;
        while (cursor != slowCursor) {
            cursor = step(cursor, 1, 1);
            slowCursor = step(slowCursor, 1, 1);
        }

        return cursor;
    }

    private static ListNode<Integer> step(ListNode<Integer> node, int stepSize,
                                          int numSteps) {
        ListNode<Integer> cursor = node;
        for (int i = 0; i < numSteps; i++) {
            for (int j = 0; j < stepSize; j++) {
                if (cursor == null) return null;
                cursor = cursor.next;
            }
        }
        return cursor;
    }
}
