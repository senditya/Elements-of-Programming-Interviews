public class RunLengthCodec {
    public static String encoding(String s) {
        if (s.length() == 0) return s;

        StringBuilder sb = new StringBuilder();

        char c = s.getAt(0);
        int count = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                count++;
            } else {
                sb.append(count).append(c);
                c = s.charAt(i);
                count = 1;
            }
        }
        sb.append(count).append(c);

        return sb.toString();
    }

    public static String decoding(String s) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            int count = 0;
            while(Character.isDigit(s.charAt(i))) {
                count = 10*count + s.charAt(i++) - '0';
            }
            sb.append(String.valueOf(s.charAt(i)).repeat(count));
        }

        return sb.toString();
    }
}
