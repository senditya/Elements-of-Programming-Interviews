import java.util.List;

public class CyclicSortStartSearch {
    public static int searchSmallest(List<Integer> A) {
        int start = 0;
        int end = A.size() - 1;

        while (end - start > 1) {
            int mid = start + (end - start)/2;
            if (A.get(mid) < A.get(start)) {
                end = mid;
            } else if (A.get(mid) > A.get(end)) {
                start = mid;
            } else {
                return start;
            }
        }

        return A.get(start) < A.get(end) ? start : end;
    }
}

