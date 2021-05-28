import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class IncreasingDecreasingSorter {
    public static List<Integer> sortKIncreasingDecreasingArray(List<Integer> A) {
        if (A == null) return null;
        if (A.size() <= 1) return new ArrayList<>(A);

        List<SubSeqIterator> iters = new ArrayList<>();
        boolean reverse = false;
        int start = 0;
        for (int i = 1; i < A.size(); i++) {
            if (!reverse ^ (A.get(i) > A.get(i-1))) {
                if (!reverse) {
                    iters.add(new SubSeqIterator(A, start, i-1));
                } else {
                    iters.add(new SubSeqIterator(A, i-1, start));
                }

                start = i;
                reverse = !reverse;
            }
        }
        if (!reverse) {
            iters.add(new SubSeqIterator(A, start, A.size() - 1));
        } else {
            iters.add(new SubSeqIterator(A, A.size() - 1, start));
        }

        PriorityQueue<HeapEntry> minHeap = new PriorityQueue<>(Comparator.comparingInt(e -> e.element));
        for (SubSeqIterator iter : iters) {
            if (iter.hasNext()) minHeap.add(new HeapEntry(iter, iter.next()));
        }

        List<Integer> sortedList = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            HeapEntry top = minHeap.poll();
            sortedList.add(top.element);
            if (top.iter.hasNext()) {
                top.element = top.iter.next();
                minHeap.add(top);
            }
        }

        return sortedList;
    }

    private static class HeapEntry {
        SubSeqIterator iter;
        int element;

        HeapEntry(SubSeqIterator iter, int element) {
            this.iter = iter;
            this.element = element;
        }
    }

    private static class SubSeqIterator implements Iterator<Integer> {
        final List<Integer> list;
        int cursor;
        final int last;
        final boolean reverse;

        SubSeqIterator(List<Integer> list, int first, int last) {
            this.list = list;
            this.cursor = first;
            this.last = last;
            this.reverse = (first > last);
        }

        @Override
        public boolean hasNext() {
            return reverse ? (cursor >= last) : (cursor <= last);
        }

        @Override
        public Integer next() {
            return reverse ? list.get(cursor--) : list.get(cursor++);
        }
    }
}

