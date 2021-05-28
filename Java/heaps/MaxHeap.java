import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;

public class MaxHeap<T extends Comparable<T>> {
    private final List<T> array = new ArrayList<>();
    private int length = 0;

    public void insert(T data) {
        array.add(data);
        heapifyUp(length++);
    }

    public T extract() {
        if (length == 0) {
            return null;
        }

        T top = peek();
        array.set(0, array.get(--length));
        heapifyDown();

        return top;
    }

    public T peek() {
        if (length == 0) {
            return null;
        } else {
            return array.get(0);
        }
    }

    public boolean isEmpty() {
        return (length == 0);
    }
    
    @Override
    public String toString() {
        return Arrays.toString(array.subList(0, length).toArray());
    }

    private void heapifyUp(int ix) {
        while (ix > 0) {
            int parentIx = ix % 2 == 0 ? ix/2 - 1 : ix/2;
            if (array.get(parentIx).compareTo(array.get(ix)) >= 0) {
                break;
            }
            Collections.swap(array, ix, parentIx);
            ix = parentIx;
        }
    }

    private void heapifyDown() {
        int ix = 0;
        while (2*ix + 1 < length) {
            int elderChildIx = 2*ix + 1;
            if (2*ix + 2 < length && array.get(elderChildIx).compareTo(array.get(2*ix + 2)) < 0) {
                elderChildIx = 2*ix + 2;
            }

            if (array.get(ix).compareTo(array.get(elderChildIx)) >= 0) {
                break;
            } else {
                Collections.swap(array, ix, elderChildIx);
                ix = elderChildIx;
            }
        }
    }

    public static void main(String[] args) {
        MaxHeap<Integer> maxHeap = new MaxHeap<>();
        System.out.println(maxHeap.isEmpty());

        maxHeap.insert(28);
        System.out.println(maxHeap.isEmpty());
        System.out.println(maxHeap.peek());

        maxHeap.insert(359);
        maxHeap.insert(401);
        maxHeap.insert(11);
        maxHeap.insert(314);
        maxHeap.insert(156);
        maxHeap.insert(3);
        maxHeap.insert(561);
        maxHeap.insert(271);

        System.out.println(maxHeap.isEmpty());
        System.out.println(maxHeap.toString());

        while (!maxHeap.isEmpty()) {
            System.out.println(maxHeap.extract());
            System.out.println(maxHeap.toString());
        }
    }
}
