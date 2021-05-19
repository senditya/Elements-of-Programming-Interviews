import java.util.Deque;
import java.util.ArrayDeque;
import java.lang.StringBuilder;

public class PathNormalizer {
    public static String shortestEquivalentPath(String path) {
        Deque<String> stack = new ArrayDeque<>();

        StringBuilder sb = new StringBuilder();
        for (char c : path.toCharArray()) {
            if (c == '/') {
                String s = sb.toString();
                sb.setLength(0);

                if (s.equals(".") || s.equals("")) {
                    continue;
                } else if (s.equals("..") && !stack.isEmpty() && !stack.peek().equals("..")) {
                    stack.pop();
                } else {
                    stack.push(s);
                }
            } else {
                sb.append(c);
            }
        }

        String s = sb.toString();
        if (s.length() > 0 && !s.equals(".")) {
            if (s.equals("..") && !stack.isEmpty() && !stack.peek().equals("..")) {
                stack.pop();
            } else {
                stack.push(s);
            }
        }

        sb.setLength(0);
        while (!stack.isEmpty()) {
            sb.insert(0, '/').insert(0, stack.pop());
        }

        if (sb.length() <= 1) {
            return "/";
        } else {
            sb.deleteCharAt(sb.length() - 1);
            if (path.charAt(0) == '/') {
                sb.insert(0, '/');
            }
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        System.out.println(shortestEquivalentPath("../a/b/../c"));
    }
}
