class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxStr = s;
        string minStr = s;

        // Get max: Replace first non-9 digit with 9
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char& c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // Get min:
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char& c : minStr) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < s.size(); ++i) {
                    if (minStr[i] == toReplaceMin) minStr[i] = '0';
                }
            }
        }

        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);
        return maxVal - minVal;
    }
};
