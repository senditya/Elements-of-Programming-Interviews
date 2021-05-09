public class BitParity {
    public static short getParity(long word) {
        boolean parity = true;

        while(word != 0) {
            if ((word & 1L) == 1) {
                parity = !parity;
            }
            word >>>= 1;
        }

        if (parity) {
            return 0;
        } else {
            return 1;
        }
    }

    public static void main(String[] args) {
        System.out.println(getParity(55L));
    }
}
