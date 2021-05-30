import java.util.List;
import java.util.ArrayList;

public class BinarySearch<T> {
    public static int binarySearch(List<T> array, T target) {
        int start = 0;
        int end = array.size() - 1;

        while (start <= end) {
            int middle = start + (end - start)/2;
            if (array.get(middle).eqauls(target)) {
                return middle;
            } else if (array.get(middle) > target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        return -1;
   }
}
