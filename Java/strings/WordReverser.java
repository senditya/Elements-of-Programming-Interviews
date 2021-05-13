public class WordReverser {
    public static void reverseWords(char[] input) {
        char temp;
        for (int i = 0, j = input.length - 1; i < j; i++, j--) {
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }

        int i = 0;
        while (i < input.length) {
            if (Character.isLetterOrDigit(input[i])) {
                int wordStart = i;
                int wordEnd = i+1;
                while (wordEnd < input.length && Character.isLetterOrDigit(input[wordEnd])) {
                    wordEnd++;
                }

                for (int j = wordStart, k = wordEnd - 1; j < k; j++, k--) {
                    temp = input[j];
                    input[j] = input[k];
                    input[k] = temp;
                }

                i = wordEnd - 1;
            }
            i++;
        }
    }
}
