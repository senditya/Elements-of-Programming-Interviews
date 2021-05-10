import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

public class SodukoChecker {
    public static boolean isValidSudoku(List<List<Integer>> partialAssignment) {
        for (int row = 0; row < 9; row++) {
            if(!checkOneToNine(getRow(partialAssignment, row))) {
                return false;
            }
        }

        for (int col = 0; col < 9; col++) {
            if(!checkOneToNine(getColumn(partialAssignment, col))) {
                return false;
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                if (!checkOneToNine(linearize3Square(partialAssignment, row, col))) {
                    return false;
                }
            }
        }

        return true;
    }

    public static List<Integer> getColumn(List<List<Integer>> sudoku, int col) {
        return sudoku.stream()
                .map(row -> row.get(col)).collect(Collectors.toList());
    }

    public static List<Integer> getRow(List<List<Integer>> sudoku, int row) {
        return sudoku.get(row);
    }

    public static List<Integer> linearize3Square(List<List<Integer>> sudoku,
                                                 int row, int column) {
        List<Integer> numbers = new ArrayList<>();
        for (int i = row; i < row + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                numbers.add(sudoku.get(i).get(j));
            }
        }
        return numbers;
    }

    public static boolean checkOneToNine(List<Integer> numbers) {
        List<Integer> checks = new ArrayList<>(Collections.nCopies(9, 0));
        for (int num: numbers) {
            if (num > 0) {
                checks.set(num-1, checks.get(num-1)+1);
            }
        }
        for (int check: checks) {
            if (check > 1) return false;
        }
        return true;
    }
}
