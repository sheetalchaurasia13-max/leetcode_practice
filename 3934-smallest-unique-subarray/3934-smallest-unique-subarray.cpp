class Solution {
    static constexpr long long BASE1 = 100003LL;
    static constexpr long long MOD1  = 1000000007LL;
    static constexpr long long BASE2 = 100019LL;
    static constexpr long long MOD2  = 1000000009LL;

    struct PairHash {
        size_t operator()(const pair<long long, long long>& p) const noexcept {
            return (static_cast<size_t>(p.first) * 1315423911ULL) ^
                   (static_cast<size_t>(p.second) + 0x9e3779b97f4a7c15ULL);
        }
    };

    bool hasUniqueOfLength(const vector<int>& nums, int len,
                           const vector<long long>& pow1,
                           const vector<long long>& pow2) {
        int n = static_cast<int>(nums.size());
        if (len <= 0 || len > n) return false;

        long long h1 = 0, h2 = 0;
        for (int i = 0; i < len; ++i) {
            long long val = nums[i];
            h1 = (h1 * BASE1 + val) % MOD1;
            h2 = (h2 * BASE2 + val) % MOD2;
        }

        unordered_map<pair<long long, long long>, int, PairHash> freq;
        freq.reserve(n - len + 1);
        freq[{h1, h2}] = 1;

        for (int i = len; i < n; ++i) {
            long long outVal = nums[i - len];
            long long inVal  = nums[i];

            h1 = (h1 - (outVal * pow1[len - 1]) % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE1 + inVal) % MOD1;

            h2 = (h2 - (outVal * pow2[len - 1]) % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE2 + inVal) % MOD2;

            ++freq[{h1, h2}];
        }

        for (const auto& [hashPair, count] : freq) {
            if (count == 1) return true;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLength(nums, mid, pow1, pow2)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};