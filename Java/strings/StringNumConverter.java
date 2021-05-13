import java.lang.StringBuilder;

public class StringNumConverter {
    public static String intToString(int x) {
        if (x == 0) return "0";

        int sign = x < 0 ? -1 : 1;

        StringBuilder sb = new StringBuilder();
        while (x != 0) {
            int digit = x%10 * sign;
            sb.insert(0, (char)('0' + digit));
            x /= 10;
        }

        if (sign < 0) {
            sb.insert(0, '-');
        }

        return sb.toString();
    }

    public static int stringToInt(String s) {
        boolean negative = s.charAt(0) == '-';
        int e = 1;
        int number = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                number += e * (s.charAt(i) - '0');
                e *= 10;
            }
        }
        return negative ? number * -1 : number;
    }

    public static void main(String[] args) {
        System.out.println("Int MAX: " + Integer.MAX_VALUE);
        System.out.println("Int MIN: " + Integer.MIN_VALUE);

        System.out.println(intToString(-2147483648));
        System.out.println(stringToInt("-2147483648"));
    }
}
