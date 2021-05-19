public class MyStack<T> {
    private ListNode<T> head = null;

    public void push(T value) {
        ListNode<T> newNode = new ListNode<>();
        newNode.data = value;

        if (head != null) {
            newNode.next = head;
        }

        head = newNode;
    }

    public T pop() {
        if (head == null) {
            return null;
        } else {
            ListNode<T> temp = head;
            head = head.next;
            return temp.data;
        }
    }

    public T peek() {
        if (head == null) {
            return null;
        } else {
            return head.data;
        }
    }

    private static class ListNode<T> {
        T data;
        ListNode<T> next;
    }

    public static void main(String[] args) {
        MyStack<Integer> stack = new MyStack<>();

        System.out.println("Initial stack head: " + stack.peek());

        stack.push(1);
        System.out.println("Stack top: " + stack.peek());
        System.out.println("Stack pop: " + stack.pop());
        System.out.println("Stack pop: " + stack.pop());
        System.out.println("Stack top: " + stack.peek());

        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Stack top: " + stack.peek() + "; Stack pop: " + stack.pop());
        System.out.println("Stack top: " + stack.peek() + "; Stack pop: " + stack.pop());
        System.out.println("Stack top: " + stack.peek() + "; Stack pop: " + stack.pop());
        System.out.println("Stack top: " + stack.peek() + "; Stack pop: " + stack.pop());
    }
}
