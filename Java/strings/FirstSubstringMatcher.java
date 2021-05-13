public class FirstSubstringMatcher {
    private static final long BASE = 26;

    public static int rabinKarp(String t, String s) {
        if (s.length() > t.length()) return -1;
        if (s.length() == 0) return 0;

        long tHash = 0L;
        long sHash = 0L;
        long maxIndexS = 1L;
        for (int i = 0; i < s.length(); i++) {
            sHash = sHash * BASE + s.charAt(i) - 'a' + 1;
            tHash = tHash * BASE + t.charAt(i) - 'a' + 1;
            maxIndexS *= BASE;
        }
        maxIndexS /= BASE;

        if (tHash == sHash && trueMatch(s, t, 0)) {
            return 0;
        }

        for (int i = 1; i <= t.length() - s.length(); i++) {
            tHash -= maxIndexS * (t.charAt(i-1) - 'a' + 1);
            tHash = tHash * BASE + (t.charAt(i + s.length() - 1) - 'a' + 1);
            if (tHash == sHash && trueMatch(s, t, i)) {
                return i;
            }
        }

        return -1;
    }

    private static boolean trueMatch(String s, String t, int tStart) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i + tStart)) {
                return false;
            }
        }

        return true;
    }
}
