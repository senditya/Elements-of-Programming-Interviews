import java.util.List;

public class IntArrayIncrement {
    public List<Integer> plusOne(List<Integer> A) {
        boolean carryOver = 1;
        for (int i = A.size() - 1; i >= 0; i--) {
            if (A.get(i) == 9) {
                A.set(i, 0);
                carryOver = 1;
            } else {
                A.set(i, A.get(i) + carryOver);
                carryOver = 0;
                break;
            }
        }

        if (carryOver != 0) {
            A.set(0, 1);
            A.add(0);
        }

        return A;
    }
}
