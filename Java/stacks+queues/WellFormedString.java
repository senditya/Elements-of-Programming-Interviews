import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Objects;

public class WellFormedString {
    public static boolean isWellFormed(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            switch (c) {
                case '(':
                case '{':
                case '[':   stack.push(c);
                            break;
                case ')':   if (!Objects.equals(stack.poll(), '(')) return false;
                            break;
                case '}':   if (!Objects.equals(stack.poll(), '{')) return false;
                            break;
                case ']':   if (!Objects.equals(stack.poll(), '[')) return false;
                            break;
                default:    break;
            }
        }

        return stack.isEmpty();
    }
}
