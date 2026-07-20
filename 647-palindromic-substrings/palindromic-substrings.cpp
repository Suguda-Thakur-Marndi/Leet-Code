class Solution {
public:

    bool ispalindrome(string s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {

            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }

        return true;
    }

    int countSubstrings(string s) {

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            string temp = "";

            for (int j = i; j < n; j++) {

                temp += s[j];

                if (ispalindrome(temp)) {
                    count++;
                }
            }
        }

        return count;
    }
};