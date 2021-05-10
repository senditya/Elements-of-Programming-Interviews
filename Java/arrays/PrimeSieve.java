import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class PrimeSieve {
    public static List<Integer> generatePrimes(int n) {
        List<Boolean> numberIsPrime =
            new ArrayList<>(Collections.nCopies(n, true));
        List<Integer> primes = new ArrayList<>();

        for (int i = 2; i <= n; i++) {
            if (!numberIsPrime.get(i-1)) continue;

            primes.add(i);

            int j = i;
            while (j <= n && j > 0) {
                numberIsPrime.set(j-1, false);
                j += i;
            }
        }

        return primes;
    }
}
