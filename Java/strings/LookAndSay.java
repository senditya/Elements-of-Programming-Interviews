import java.lang.StringBuilder;

public class LookAndSay {
    public static String lookAndSay(int n) {
        String s = "1";

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < n; i++) {
            char c = s.charAt(0);
            int count = 1;
            for (int j = 1; j < s.length(); j++) {
                if (s.charAt(j) == c) {
                    count++;
                } else {
                    sb.append(count);
                    sb.append(c);
                    c = s.charAt(j);
                    count = 1;
                }
            }
            sb.append(count);
            sb.append(c);

            s = sb.toString();
            sb.setLength(0);
        }

        return s;
    }
}
