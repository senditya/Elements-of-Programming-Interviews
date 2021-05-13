public class BaseConverter {
    public static String convertBase(String numAsString, int b1, int b2) {
        if (numAsString == "0" || numAsString == "-0") {
            return "0";
        }

        boolean negative = numAsString.charAt(0) == '-';

        int decimalNumber = 0;
        int e = 1;
        for (int i = numAsString.length() - 1; i >= 0; i--) {
            char c = numAsString.charAt(i);
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
                decimalNumber += letterToDecimal(c) * e;
            }
            e *= b1;
        }

        StringBuilder sb = new StringBuilder();
        while (decimalNumber != 0) {
            int n = decimalNumber%b2;
            sb.insert(0, decimalToLetter(n));
            decimalNumber /= b2;
        }

        if (negative) {
            sb.insert(0, '-');
        }

        return sb.toString();
    }

    private static int letterToDecimal(char c) {
        if (c >= 'A' && c <= 'F') {
            return (10 + c - 'A');
        } else if (c >= '0' && c <= '9') {
            return (c - '0');
        } else {
            throw new UnsupportedOperationException();
        }
    }

    private static char decimalToLetter(int n) {
        if (n >= 0 && n <= 9) {
            return (char)('0' + n);
        } else if (n >= 10 && n <= 15) {
            return (char)('A' + (n - 10));
        } else {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {

    }
}
