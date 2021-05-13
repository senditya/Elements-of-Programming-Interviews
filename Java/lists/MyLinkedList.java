import java.lang.StringBuilder;

public class MyLinkedList<T> {
    private ListNode<T> head = null;
    private int length = 0;

    public void insert(T data) {
        insert(length, data);
    }

    public void insert(int position, T data) {
        if (position > length) {
            throw new IllegalArgumentException(
                "Cannot insert a node in position "
                + position + " when the list itself is of length " + length
            );
        }
        if (position < 0) {
            throw new IllegalArgumentException(
                "Position cannot be negative: " + position
            );
        }

        ListNode<T> newNode = new ListNode<>();
        newNode.data = data;
        newNode.next = null;

        if (length == 0) {
            head = newNode;
        } else {
            ListNode<T> preceedingNode = getNode(position - 1);
            ListNode<T> succeedingNode = preceedingNode.next;
            preceedingNode.next = newNode;
            newNode.next = succeedingNode;
        }

        length++;
    }

    public void delete(int position) {
        if (position >= length || position < 0) {
            throw new IllegalArgumentException("No node at position " + position);
        }

        if (position == 0) {
            head = head.next;
        } else {
            ListNode<T> preceedingNode = getNode(position - 1);
            preceedingNode.next = preceedingNode.next.next;
        }

        length--;
    }

    public T get(int position) {
        return getNode(position).data;
    }

    private ListNode<T> getNode(int position) {
        if (position >= length || position < 0) {
            throw new IllegalArgumentException("No node at position " + position);
        }

        ListNode<T> cursorNode = head;

        for (int i = 0; i < position; i++) {
            cursorNode = cursorNode.next;
        }

        return cursorNode;
    }

    public int findPosition(T data) {
        ListNode<T> cursorNode = head;
        int position;
        for (position = 0; position < length; position++) {
            if (cursorNode.data == data) return position;
            cursorNode = cursorNode.next;
        }

        return -1;
    }

    @Override
    public String toString() {
        if (length == 0) return "";

        StringBuilder sb = new StringBuilder();

        ListNode<T> cursorNode = head;
        sb.append(cursorNode.data);
        cursorNode = cursorNode.next;

        for (int position = 1; position < length; position++) {
            sb.append(" -> ").append(cursorNode.data);
            cursorNode = cursorNode.next;
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        MyLinkedList<Integer> list1 = new MyLinkedList<>();
        System.out.println(list1);
        System.out.println(list1.findPosition(12));
        list1.insert(10);
        System.out.println(list1.findPosition(10));
        System.out.println(list1);
        list1.insert(12);
        System.out.println(list1);
        list1.insert(1, 11);
        System.out.println(list1);
        System.out.println("10 at position: " + list1.findPosition(10));
        System.out.println("11 at position: " + list1.findPosition(11));
        System.out.println("12 at position: " + list1.findPosition(12));

        list1.delete(2);
        System.out.println(list1);
        list1.insert(12);
        System.out.println(list1);
        list1.delete(1);
        System.out.println(list1);
        list1.insert(1, 11);
        System.out.println(list1);
        list1.delete(0);
        System.out.println(list1);
    }
}
