import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class SortApproximateSort {
   public static List<Integer> sortApproximatelySortedData(Iterator<Integer> sequence, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i <= k; i++) {
            if (sequence.hasNext()) minHeap.add(sequence.next());
        }

        List<Integer> sortedList = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            sortedList.add(minHeap.poll());
            if (sequence.hasNext()) minHeap.add(sequence.next());
        }

        return sortedList;
   }
}

