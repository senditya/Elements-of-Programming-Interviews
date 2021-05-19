import java.util.Arrays;
import java.util.NoSuchElementException;

public class CircularQueue {
    private int[] array;
    private int head;
    private int tail;

    public CircularQueue(int capacity) {
        capacity = capacity <= 0 ? 1 : capacity;
        this.array = new int[capacity];
        this.head = -1;
        this.tail = -1;
    }

    public void enqueue(Integer x) {
        resizeIfFull();
        tail = (tail + 1) % array.length;
        if (head == -1) head = 0;
        array[tail] = x;
    }

    public Integer dequeue() {
        if (head == -1) {
            return null;
        } else {
            int element = array[head];
            if (head == tail) {
                head = -1;
                tail = -1;
            } else {
                head = (head + 1) % array.length;
            }
            return element;
        }
    }

    public int size() {
        if (head == -1) {
            return 0;
        } else if (head <= tail) {
            return tail - head + 1;
        } else {
            return (array.length - head) + (tail + 1);
        }
    }

    @Override
    public String toString() {
        return "Queue {" + "head=" + head + ", tail=" + tail + ", entries="
                + Arrays.toString(array) + "}";
    }

    private boolean isFull() {
        return (
            (tail > head && tail - head + 1 == array.length)
            || (tail < head && head - tail == 1)
            || (tail == 0 && head == 0 && array.length == 1)
        );
    }

    private void resizeIfFull() {
        if (!isFull()) return;

        int initCapacity = array.length;
        int newCapacity = initCapacity * 2;

        int[] newArray = new int[newCapacity];

        if (head > tail) {
            System.arraycopy(array, head, newArray, 0, array.length - head);
            System.arraycopy(array, 0, newArray, array.length - head, tail + 1);
        } else {
            System.arraycopy(array, head, newArray, 0, tail - head + 1);
        }

        head = 0;
        tail = array.length - 1;
        array = newArray;
    }
}
