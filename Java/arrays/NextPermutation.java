import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class NextPermutation {
    public static List<Integer> nextPermutation(List<Integer> perm) {
        if (perm.size() < 2) {
            return Collections.emptyList();
        }

        int switchIndex;
        for(switchIndex = perm.size() - 2; switchIndex >= 0; switchIndex--) {
            if (perm.get(switchIndex) < perm.get(switchIndex + 1)) break;
        }
        if (switchIndex < 0) {
            return Collections.emptyList();
        }

        int minGreaterThanSwitchIndex = -1;
        int minGreaterThanSwitch = Integer.MAX_VALUE;
        for (int i = switchIndex + 1; i < perm.size(); i++) {
            if (perm.get(i) > perm.get(switchIndex) && perm.get(i) <= minGreaterThanSwitch) {
                minGreaterThanSwitch = perm.get(i);
                minGreaterThanSwitchIndex = i;
            }
        }

        Collections.swap(perm, switchIndex, minGreaterThanSwitchIndex);

        int head = switchIndex + 1;
        int tail = perm.size() - 1;
        while (head < tail) {
            Collections.swap(perm, head++, tail--);
        }

        return perm;
    }
}
