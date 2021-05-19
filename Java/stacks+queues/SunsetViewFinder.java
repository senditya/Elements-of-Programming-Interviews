import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

public class SunsetViewFinder {
    public static List<Integer>
    examineBuildingsWithSunset(Iterator<Integer> sequence) {
        Deque<Building> stack = new ArrayDeque<>();
        int i = 0;
        while (sequence.hasNext()) {
            int height = sequence.next();
            while (!stack.isEmpty() && stack.peek().height <= height) {
                stack.pop();
            }

            stack.push(new Building(i, height));

            i++;
        }

        List<Integer> views = new ArrayList<>();
        while (!stack.isEmpty()) {
            views.add(stack.pop().index);
        }

        return views;
    }

    private static class Building {
        int index;
        int height;

        Building(int index, int height) {
            this.index = index;
            this.height = height;
        }
    }
}
