import java.util.Deque;
import java.util.ArrayDeque;

public class QueueMax {
    Deque<Integer> queue = new ArrayDeque<>();
    Deque<Integer> maxCandidates = new ArrayDeque<>();

    public void enqueue(Integer x) {
        while (!maxCandidates.isEmpty() && maxCandidates.peekLast() < x) {
            maxCandidates.removeLast();
        }

        queue.addLast(x);
        maxCandidates.addLast(x);
    }

    public Integer dequeue() {
        if (queue.isEmpty()) return null;

        int head = queue.removeFirst();
        if (maxCandidates.peekFirst().equals(head)) maxCandidates.removeFirst();

        return head;
    }

    public Integer max() {
        if (maxCandidates.isEmpty()) {
            return null;
        } else {
            return maxCandidates.peekFirst();
        }
    }
}
