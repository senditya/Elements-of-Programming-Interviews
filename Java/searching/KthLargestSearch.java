import java.util.List;
import java.util.Random;
import java.util.Collections;

public class KthLargestSearch {
    public static int findKthLargest(int k, List<Integer> A) {
        if (A.size() == 1) return A.get(0);

        int start = 0;
        int end = A.size() - 1;

        Random random = new Random();
        
        while (start <= end) {
            int pivotIx = start + random.nextInt(end - start + 1);
            int pivotEqualIx = dutchFlag(A, start, end, A.get(pivotIx));

            if (pivotEqualIx == A.size() - k) {
                return A.get(pivotEqualIx);
            } else if (pivotEqualIx > A.size() - k) {
                end = pivotEqualIx - 1;
            } else {
                start = pivotEqualIx + 1;
            }
        }

        throw new RuntimeException("This point should never have been reached!");
    }

    pivate static int dutchFlag(List<Integer> A, int start, int end, int pivot) {
        int smaller = start;
        int equal = start;
        int larger = end;

        while (equal <= larger) {
            int element = A.get(equal);

            if (element < pivot) {
                Collections.swap(A, smaller++, equal++);
            } else if (element == pivot) {
                equal++;
            } else {
                Collections.swap(A, equal, larger--);
            }
        }

        return smaller;
    }
}

