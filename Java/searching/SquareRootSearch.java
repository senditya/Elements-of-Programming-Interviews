public class SquareRootSearch {
    public static int squareRoot(int k) {
        if (k == 0) return 0;

        int smallest = 1;
        int largest = k/2;
        int match = 1;

        while (smallest <= largest) {
            int mid = smallest + (largest - smallest)/2;
            long midSq = (long) mid * mid;
            if (midSq == k) {
                return mid;
            } else if (midSq > k) {
                largest = mid - 1;
            } else {
                match = mid;
                smallest = mid + 1;
            }
        }

        return match;
    }
}

