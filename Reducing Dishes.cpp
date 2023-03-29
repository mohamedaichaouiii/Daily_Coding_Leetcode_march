

class Solution {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end());
        int pos_sum = 0;
        int time = 0;
        int ans = 0;
        for (int s : satisfaction) {
            if (s >= 0) {
                pos_sum += s;
                time++;
                ans += time * s;
            }
        }
        int neg_sum = 0;
        int neg_seen = 0;
        int neg_ans = 0;
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            if (satisfaction[i] < 0) {
                int total = neg_sum + satisfaction[i];
                if (pos_sum + total > 0) {
                    neg_ans += total;
                    neg_sum += satisfaction[i];
                    neg_seen++;
                } else {
                    break;
                }
            }
        }
        return ans + (pos_sum * neg_seen) + neg_ans;
    }
};
