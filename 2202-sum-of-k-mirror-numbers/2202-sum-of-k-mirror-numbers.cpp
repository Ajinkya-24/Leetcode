class Solution {
public:
    // Convert number to base-k string
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Check if string is palindrome
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Generate palindromes from integer roots
    long long kMirror(int k, int n) {
        vector<long long> result;
        int len = 1;

        while (result.size() < n) {
            // Generate odd-length palindromes
            for (int i = pow(10, len - 1); i < pow(10, len) && result.size() < n; ++i) {
                string s = to_string(i);
                string rs = s.substr(0, s.size() - 1);
                reverse(rs.begin(), rs.end());
                long long num = stoll(s + rs);
                if (isPalindrome(toBaseK(num, k))) {
                    result.push_back(num);
                }
            }

            // Generate even-length palindromes
            for (int i = pow(10, len - 1); i < pow(10, len) && result.size() < n; ++i) {
                string s = to_string(i);
                string rs = s;
                reverse(rs.begin(), rs.end());
                long long num = stoll(s + rs);
                if (isPalindrome(toBaseK(num, k))) {
                    result.push_back(num);
                }
            }

            ++len;
        }

        long long sum = 0;
        for (long long num : result) sum += num;
        return sum;
    }
};
