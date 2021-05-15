public class ListPivoter {
    public static ListNode<Integer> listPivoting(ListNode<Integer> l, int x) {
        if (l == null) return null;
        if (l.next == null) return l;

        ListNode<Integer> lessHead = null, lessTail = null;
        ListNode<Integer> equalHead = null, equalTail = null;
        ListNode<Integer> moreHead = null, moreTail = null;

        while (l != null) {
            if (l.data < x) {
                lessTail = insert(l, lessTail);
                if (lessHead == null) lessHead = lessTail;
            } else if (l.data > x) {
                moreTail = insert(l, moreTail);
                if (moreHead == null) moreHead = moreTail;
            } else {
                equalTail = insert(l, equalTail);
                if (equalHead == null) equalHead = equalTail;
            }

            l = l.next;
        }

        ListNode<Integer> head = null;
        if (lessHead != null) {
            head = lessHead;
            lessTail.next = equalHead;
        }
        if (equalHead != null) {
            if (head == null) head = equalHead;
            equalTail.next = moreHead;
        }
        if (moreHead != null) {
            if (head == null) head = moreHead;
            moreTail.next = null;
        }

        return head;
    }

    private static ListNode<Integer> insert(ListNode<Integer> node,
                               ListNode<Integer> tail) {
        if (tail == null) {
            tail = node;
        } else {
            tail.next = node;
            tail = tail.next;
        }
        return tail;
    }
}
