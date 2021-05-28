import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Iterator;
import java.util.Comparator;

public class ClosestStars {
    public static class Star implements Comparable<Star> {
        private double x, y, z;

        public Star(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public double distance() { return Math.sqrt(x * x + y * y + z * z); }

        @Override
        public int compareTo(Star that) {
            return Double.compare(this.distance(), that.distance());
        }

        @Override
        public String toString() {
            return String.valueOf(distance());
        }
    }

    public static List<Star> findClosestKStars(Iterator<Star> stars, int k) {
        PriorityQueue<Star> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        
        while (stars.hasNext()) {
            if (maxHeap.size() < k) {
                maxHeap.add(stars.next());
            } else {
                Star farthest = maxHeap.poll();
                Star star = stars.next();
                Star closer = star.distance() < farthest.distance() ? star : farthest;
                maxHeap.add(closer);
            }
        }

        return new ArrayList<>(maxHeap);
    }
}

