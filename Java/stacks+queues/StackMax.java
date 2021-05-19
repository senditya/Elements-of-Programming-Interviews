public class StackMax {
    IntListNode head = null;

    public boolean empty() {
        return (head == null);
    }

    public Integer max() {
        return head.max;
    }

    public Integer pop() {
        if (head != null) {
            Integer temp = head.data;
            head = head.next;
            return temp;
        } else {
            return null;
        }
    }

    public void push(Integer x) {
        IntListNode newNode = new IntListNode(x);

        if (head != null) {
            newNode.next = head;
            if (x > head.max) {
                newNode.max = x;
            } else {
                newNode.max = head.max;
            }
        }

        head = newNode;
    }

    private static class IntListNode {
        int data;
        int max;
        IntListNode next;

        IntListNode(int data) {
            this(data, null);
        }

        IntListNode(int data, IntListNode next) {
            this.data = data;
            this.next = next;
            this.max = data;
        }
    }
}
