import java.util.List;
import java.util.ArrayList;
import java.lang.Math;

public class BuySellStockTwice {
    public static double buyAndSellStockTwice(List<Double> prices) {
        if (prices.size() == 0) return 0.0;

        List<Double> maxProfitBy = new ArrayList<>(prices.size());

        double minPriceSoFar = Double.MAX_VALUE;
        double maxProfitSoFar = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPriceSoFar = Math.min(minPriceSoFar, prices.get(i));
            maxProfitSoFar = Math.max(maxProfitSoFar, prices.get(i) - minPriceSoFar);
            maxProfitBy.add(maxProfitSoFar);
        }

        double maxPriceAfter = Double.MIN_VALUE;
        double maxTotalProfit = maxProfitSoFar;
        for (int i = prices.size() - 1; i > 0; i--) {
            maxPriceAfter = Math.max(maxPriceAfter, prices.get(i));
            maxTotalProfit = Math.max(maxTotalProfit,
            maxPriceAfter - prices.get(i) + maxProfitBy.get(i-1));
        }

        return maxTotalProfit;
    }
}
