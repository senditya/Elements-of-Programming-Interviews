import java.util.List;
import java.util.ArrayList;

public class SpiralOrder {
    public static List<Integer> matrixInSpiralOrder(List<List<Integer>> squareMatrix) {
        if (squareMatrix.size() == 0) return new ArrayList<>();

        List<Integer> spiralList = new ArrayList<>();

        int leftCol = 0;
        int rightCol = squareMatrix.get(0).size() - 1;
        int upRow = 0;
        int downRow = squareMatrix.size() - 1;

        while (leftCol <= rightCol || upRow <= downRow) {
            // read top row
            for (int i = leftCol; i <= rightCol; i++) {
                spiralList.add(squareMatrix.get(upRow).get(i));
            }

            // read right col
            for (int j = upRow + 1; j <= downRow; j++) {
                spiralList.add(squareMatrix.get(j).get(rightCol));
            }

            // read bottom row
            for (int i = rightCol - 1; i >= leftCol; i--) {
                spiralList.add(squareMatrix.get(downRow).get(i));
            }

            // read left col
            for (int j = downRow - 1; j > upRow; j--) {
                spiralList.add(squareMatrix.get(j).get(leftCol));
            }

            leftCol++;
            rightCol--;
            upRow++;
            downRow--;
        }

        return spiralList;
    }
}
