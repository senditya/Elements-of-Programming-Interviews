import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Comparator;

public class MergeSortedArrays {
    public static List<Integer> mergeSortedArrays(List<List<Integer>> sortedArrays) {
        List<Integer> mergedList = new ArrayList<>();
        PriorityQueue<ArrayElement> heap = new PriorityQueue<>(Comparator.comparingInt(e -> e.element));

        for (int i = 0; i < sortedArrays.size(); i++) {
            if (sortedArrays.get(i) != null && sortedArrays.get(i).size() != 0) {
                ArrayElement element = new ArrayElement(i, 0, sortedArrays.get(i).get(0));
                heap.add(element);
            }
        }

        while (!heap.isEmpty()) {
            ArrayElement top = heap.poll();
            mergedList.add(top.element);

            if (top.elementIx < sortedArrays.get(top.arrayId).size() - 1) {
                ArrayElement replacement = new ArrayElement(top.arrayId, top.elementIx + 1, 
                                                            sortedArrays.get(top.arrayId).get(top.elementIx + 1));
                heap.add(replacement);
            }
        }

        return mergedList;
    }

    private static class ArrayElement {
        int arrayId;
        int elementIx;
        int element;

        ArrayElement(int arrayId, int elementIx, int element) {
            this.arrayId = arrayId;
            this.elementIx = elementIx;
            this.element = element;
        }
    }
}

