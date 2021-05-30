import java.util.List;

public class EntryEqualsIndexSearch {
    public static int searchEntryEqualToItsIndex(List<Integer> A) {
        int start = 0;
        int end = A.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (A.get(mid) == mid) {
                return mid;
            } else if (A.get(mid) > mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
}
