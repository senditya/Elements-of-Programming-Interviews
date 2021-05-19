import java.util.Deque;
import java.util.ArrayDeque;

public class RpnEvaluator {
    public static int eval(String expression) {
        Deque<Integer> stack = new ArrayDeque<>();

        StringBuilder sb = new StringBuilder();
        for (char c : expression.toCharArray()) {
            if (c == ',') {
                String s = sb.toString();
                if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                    int n2 = stack.pop();
                    int n1 = stack.pop();
                    stack.push(operate(n1, n2, s));
                } else {
                    stack.push(parse(s));
                }
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }

        if (sb.length() > 0) {
            String s = sb.toString();
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int n2 = stack.pop();
                int n1 = stack.pop();
                return operate(n1, n2, s);
            } else {
                return parse(s);
            }
        } else {
            return stack.pop();
        }
    }

    private static int parse(String s) {
        int n = 0;
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                n = 10*n + c - '0';
            }
        }
        if (s.charAt(0) == '-') n *= -1;
        return n;
    }

    private static int operate(int n1, int n2, String op) {
        switch (op) {
            case "+": return n1 + n2;
            case "-": return n1 - n2;
            case "*": return n1 * n2;
            case "/": return n1 / n2;
            default: throw new UnsupportedOperationException(op);
        }
    }
}
