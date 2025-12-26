class Solution {
public:
    int bestClosingTime(string customers) {
        int curPenalty = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') {
                curPenalty++;
            }
        }

        // Start with closing at hour 0, the penalty equals all 'Y' in closed
        // hours.
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); ++i) {
            char ch = customers[i];

            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penalty by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penalty is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};