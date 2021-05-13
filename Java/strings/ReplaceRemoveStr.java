public class ReplaceRemoveStr {
    public static int replaceAndRemove(int size, char[] s) {
        int bees = 0;
        int finalSize = size;
        for (int i = 0, j = 0; j < size; j++) {
            if (s[j] == 'a') {
                finalSize++;
            } else if (s[j] == 'b') {
                finalSize--;
                bees++;
            }

            if (s[j] != 'b') {
                s[i] = s[j];
                i++;
            }
        }

        size -= bees;

        for (int i = size - 1, j = finalSize - 1; i < j; i--, j--) {
            if (s[i] != 'a') {
                s[j] = s[i];
            } else {
                s[j] = 'd';
                s[j-1] = 'd';
                j--;
            }
        }

        return finalSize;
    }
}
