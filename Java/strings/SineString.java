public class SineString {
    public static String snakeString(String s) {
        StringBuilder top = new StringBuilder();
        StringBuilder mid = new StringBuilder();
        StringBuilder bottom = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                // this goes to mid
                mid.append(s.charAt(i));
            } else if (i % 4 == 1) {
                // this goes to top
                top.append(s.charAt(i));
            } else {
                // this goes to bottom
                bottom.append(s.charAt(i));
            }
        }

        return top.append(mid).append(bottom).toString();
    }

    public static void main(String[] args) {
        System.out.println(snakeString("Hello World!"));
    }
}
