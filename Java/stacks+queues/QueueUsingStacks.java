import java.util.Deque;
import java.util.ArrayDeque;

public class QueueUsingStacks {
    private final Deque<Integer> stack = new ArrayDeque<>();
    private final Deque<Integer> dequeueStack = new ArrayDeque<>();

    public void enqueue(Integer x) {
        stack.push(x);
    }

    public Integer dequeue() {
        if (dequeueStack.isEmpty()) {
            while (!stack.isEmpty()) {
                dequeueStack.push(stack.pop());
            }
        }

        return dequeueStack.pop();
    }
}
