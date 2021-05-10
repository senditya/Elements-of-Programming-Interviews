public class ArrayAdvancing {
    public static boolean canReachEnd(List<Integer> maxAdvanceSteps) {
        int furthestReachable = 0;
        for (int i = 0; i <= furthestReachable
                        && furthestReachable < maxAdvanceSteps.size(); i++) {
            if (i + maxAdvanceSteps.get(i) > furthestReachable) {
                furthestReachable = i + maxAdvanceSteps.get(i);
            }
        }

        return furthestReachable >= maxAdvanceSteps.size() - 1;
    }

    public static void main(String[] args) {

    }
}
