import java.util.List;
import java.util.Collections;
import java.util.Arrays;

public class DutchFlag {
    public enum Color { RED, WHITE, BLUE }

    public static void dutchFlagPartition(int pivotIndex, List<Color> A) {
        Color pivot = A.get(pivotIndex);

        int smaller = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A.get(i).ordinal() < A.get(pivotIndex).ordinal()) {
                Collections.swap(A, i, smaller);
                smaller++;
            }
        }

        System.out.println(A);

        int larger = A.size()-1;
        for (int i = A.size() - 1; i >= 0; i--) {
            if (A.get(i).ordinal() > A.get(pivotIndex).ordinal()) {
                Collections.swap(A, i, larger);
                larger--;
            }
        }

        System.out.println(A);
    }

    public static void main(String[] args) {
        dutchFlagPartition(
            2,
            Arrays.asList( Color.RED, Color.RED,
                Color.WHITE, Color.BLUE, Color.RED )
        );
    }
}
