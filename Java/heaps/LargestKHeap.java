import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Comparator;

public class LargestKHeap {
    public static List<Integer> kLargestInBinaryHeap(List<Integer> A, int k) {
        if (A.size() == 0) return Collections.emptyList();

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.comparingInt(A::get).reversed());
        maxHeap.add(0);

        List<Integer> kLargest = new ArrayList<>();
        while (kLargest.size() != k) {
            int topIx = maxHeap.poll();

            if (2*topIx + 1 < A.size()) {
                maxHeap.add(2*topIx + 1);
            }
            if (2*topIx + 2 < A.size()) {
                maxHeap.add(2*topIx + 2);
            }

            kLargest.add(A.get(topIx));
        }

        return kLargest;
    }
}

