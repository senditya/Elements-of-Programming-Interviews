public class SpreadsheetColumnNumber {
    public static int ssDecodeColID(final String col) {
        int num = 0;
        int e = 1;
        for (int i = col.length() - 1; i >= 0; i--) {
            num += (col.charAt(i) - 'A' + 1) * e;
            e *= 26;
        }
        return num;
    }
}
