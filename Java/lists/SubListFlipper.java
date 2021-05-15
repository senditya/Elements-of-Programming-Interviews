public class SubListFlipper {
    public static ListNode<Integer> reverseSublist(ListNode<Integer> L,
                                                   int start, int finish) {
        if (start == finish) return L;

        ListNode<Integer> current = L;
        ListNode<Integer> subListHead = null;
        int position = 1;
        while (position < start) {
            subListHead = current;
            current = current.next;
            position++;
        }

        ListNode<Integer> next = current.next;
        ListNode<Integer> nextPlus = next.next;

        ListNode<Integer> subListStart = current;
        ListNode<Integer> subListEnd;

        while (position < finish) {
            next.next = current;
            current = next;
            next = nextPlus;
            if (next != null) nextPlus = next.next;
            position++;
        }

        subListEnd = current;
        subListStart.next = next;

        if (start == 1) return subListEnd;
        else {
            subListHead.next = subListEnd;
            return L;
        }
    }

    private static void printCurrentNextNextPlus(int position,
                                                 ListNode<Integer> current,
                                                 ListNode<Integer> next,
                                                 ListNode<Integer> nextPlus) {
        System.out.println("POSITION: " + position);
        System.out.println("CURRENT: " + current.data);
        if (next != null)
            System.out.println("NEXT: " + next.data);
        else
            System.out.println("NEXT: null");
        if (nextPlus != null)
            System.out.println("PLUS: " + nextPlus.data);
        else
            System.out.println("PLUS: null");
    }

    public static void main(String[] args) {
        ListNode<Integer> one = new ListNode<>();
        one.data = 1;
        one.next = new ListNode<>();
        one.next.data = 2;
        one.next.next = new ListNode<>();
        one.next.next.data = 3;

        reverseSublist(one, 2, 3);
    }
}
