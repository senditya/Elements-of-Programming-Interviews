import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class IntArrayMultiply {
    public static List<Integer> addTwoIntegers(List<Integer> A, List<Integer> B) {
        List<Integer> larger;
        List<Integer> smaller;
        if (A.size() > B.size()) {
            larger = A;
            smaller = B;
        } else {
            larger = B;
            smaller = A;
        }

        List<Integer> sum = new ArrayList<>();
        int carryOver = 0;
        for (int i = 0; i < larger.size(); i++) {
            int a = larger.get(larger.size() - 1 - i) + carryOver;
            if (smaller.size() - 1 - i >= 0) {
                a += smaller.get(smaller.size() - 1 -i);
            }

            carryOver = a/10;
            sum.add(0, a%10);
        }

        if (carryOver != 0) {
            sum.add(0, carryOver);
        }

        return sum;
    }

    public static List<Integer> multiply(List<Integer> num1,
                                         List<Integer> num2) {
        int sign1 = 1;
        int sign2 = 1;
        if (num1.get(0) < 0) {
            sign1 = -1;
            num1.set(0, num1.get(0) * -1);
        }
        if (num2.get(0) < 0) {
            sign2 = -1;
            num2.set(0, num2.get(0) * -1);
        }

        List<Integer> multiplicand;
        List<Integer> multiplier;
        if (num1.size() > num2.size()) {
            multiplicand = num1;
            multiplier = num2;
        } else {
            multiplicand = num2;
            multiplier = num1;
        }

        List<Integer> product = new ArrayList<>();
        int pad = 0;
        for (int i = multiplier.size() - 1; i >= 0; i--) {
            int mul = multiplier.get(i);

            List<Integer> subproduct = new ArrayList<>();
            int carryOver = 0;
            for (int j = multiplicand.size() - 1; j >= 0; j--) {
                int prod = multiplicand.get(j) * mul + carryOver;
                carryOver = prod/10;
                subproduct.add(0, prod%10);
            }
            if (carryOver != 0) {
                subproduct.add(0, carryOver);
            }

            for (int p = 0; p < pad; p++) {
                subproduct.add(0);
            }

            pad++;

            product = addTwoIntegers(product, subproduct);
        }

        product.set(0, product.get(0) * sign1 * sign2);

        int firstNonZero = 0;
        for (int i = 0; i < product.size() - 1; i++) {
            if (product.get(i) != 0) {
                break;
            } else {
                firstNonZero++;
            }
        }

        return product.subList(firstNonZero, product.size());
    }

    public static void main(String[] args) {
        List<Integer> num1 = Arrays.asList(1, 2);
        List<Integer> num2 = Arrays.asList(1, 0);

        System.out.println(multiply(num1, num2));
    }
}
