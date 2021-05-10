public class SortedUniqCount {
    public static int deleteDuplicates(List<Integer> A) {
        if (A.size() == 0) return 0;
        if (A.size() == 1) return 1;

        int num = A.get(0);
        int uniqPosition = 1;

        for(int position = 1; position < A.size(); position++) {
            if (A.get(position) != num) {
                num = A.get(position);
                A.set(uniqPosition, num);
                uniqPosition++;
            }
        }

        return uniqPosition;
    }
}
