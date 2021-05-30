public class FirstMatch {
    public static int searchFirstOfK(List<Integer> A, int k) {
        int start = 0;
        int end = A.size() - 1;
        int match = -1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if (A.get(mid) == k) {
                match = mid;
                end = mid - 1;
            } else if (A.get(mid) > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return match;
    }
}

