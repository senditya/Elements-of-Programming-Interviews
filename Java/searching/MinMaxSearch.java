import java.util.List;

public class MinMaxSearch {
    public static MinMax findMinMax(List<Integer> A) {
        if (A.size() == 0) throw new IllegalArgumentException();
        if (A.size() == 1) return new MinMax(A.get(0), A.get(0));

        MinMax minMax = A.get(0) < A.get(1) ? new MinMax(A.get(0), A.get(1)) : new MinMax(A.get(1), A.get(0));

        for (int i = 2; i < A.size() - 1; i += 2) {
            if (A.get(i) < A.get(i+1)) {
                // compare i with min and i+1 with max
                if (A.get(i) < minMax.smallest) minMax.smallest = A.get(i);
                if (A.get(i+1) > minMax.largest) minMax.largest = A.get(i+1);
            } else {
                // compare i with max and i+1 with min
                if (A.get(i) > minMax.largest) minMax.largest = A.get(i);
                if (A.get(i+1) < minMax.smallest) minMax.smallest = A.get(i+1);
            }
        }

        if (A.size() % 2 == 1) {
            if (A.get(A.size() - 1) < minMax.smallest) {
                minMax.smallest = A.get(A.size() - 1);
            } else if (A.get(A.size() - 1) > minMax.largest) {
                minMax.largest = A.get(A.size() - 1);
            }
        }

        return minMax;
    }

    private static class MinMax {
        int smallest;
        int largest;

        MinMax(int smallest, int largest) {
            this.smallest = smallest;
            this.largest = largest;
        }
    }
}

