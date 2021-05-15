public class ListSummer {
    public static ListNode<Integer> addTwoNumbers(ListNode<Integer> L1,
                                                  ListNode<Integer> L2) {
        ListNode<Integer> dummyHead = new ListNode<>(0, null);
        ListNode<Integer> tail = dummyHead;
        int carry = 0;

        while (L1 != null || L2 != null || carry != 0) {
            int sum = carry;
            if (L1 != null) {
                sum += L1.data;
                L1 = L1.next;
            }
            if (L2 != null) {
                sum += L2.data;
                L2 = L2.next;
            }

            tail.next = new ListNode<>(sum%10, null);
            tail = tail.next;

            carry = sum/10;
        }

        return dummyHead.next;
    }
}
