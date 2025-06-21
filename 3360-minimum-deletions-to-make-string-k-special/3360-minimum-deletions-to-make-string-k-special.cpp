class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& [ch, freq] : freqMap) {
            freqs.push_back(freq);
        }

        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        int minDeletions = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int baseFreq = freqs[i];
            int deletions = 0;

            // delete all lower frequencies entirely
            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];
            }

            // delete excess of higher frequencies
            for (int j = i + 1; j < n; ++j) {
                if (freqs[j] > baseFreq + k) {
                    deletions += freqs[j] - (baseFreq + k);
                }
            }

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
