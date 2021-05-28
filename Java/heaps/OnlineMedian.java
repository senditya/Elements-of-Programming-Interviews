import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Comparator;

public class OnlineMedian {
    public static List<Double> onlineMedian(Iterator<Integer> sequence) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        List<Double> medians = new ArrayList<>();
        
        if (sequence.hasNext()) {
            medians.add(Double.valueOf(sequence.next()));
        }

        if (sequence.hasNext()) {
            int number = sequence.next();
            maxHeap.add((int) Math.min(number, medians.get(0)));
            minHeap.add((int) Math.max(number, medians.get(0)));
            medians.add((maxHeap.peek() + minHeap.peek()) / 2.0);
        }

        while (sequence.hasNext()) {
            int number = sequence.next();
            
            if (number > minHeap.peek()) {
                minHeap.add(number);
            } else {
                maxHeap.add(number);
            }

            if (minHeap.size() > maxHeap.size()) {
                maxHeap.add(minHeap.poll());
            } else if (maxHeap.size() - minHeap.size() > 1) {
                minHeap.add(maxHeap.poll());
            }

            if (minHeap.size() == maxHeap.size()) {
                medians.add((maxHeap.peek() + minHeap.peek()) / 2.0);
            } else {
                medians.add(Double.valueOf(maxHeap.peek()));
            }
        }

        return medians;
    }
}

