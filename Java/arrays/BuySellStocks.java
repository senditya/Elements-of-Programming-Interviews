public class BuySellStocks {
    public static double computeMaxProfit(List<Double> prices) {
        if (prices.size() < 2) {
            return 0;
        }

        double min = prices.get(0);
        double maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if (prices.get(i) - min > maxProfit) {
                maxProfit = prices.get(i) - min;
            }
            if (prices.get(i) < min) {
                min = prices.get(i);
            }
        }

        return maxProfit;
    }
}
