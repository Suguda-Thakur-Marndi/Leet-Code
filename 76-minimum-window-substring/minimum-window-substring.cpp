class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp, window;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int req = mp.size();
        int from = 0;
        int left = 0;
        int right = 0;
        int minl = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char ch = s[right];
            window[ch]++;
            if (mp.count(ch) && window[ch] == mp[ch]) {
                from++;
            }
            while (from == req) {
                if (right - left + 1 < minl) {
                    minl = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (mp.count(leftChar) && window[leftChar] < mp[leftChar]) {
                    from--;
                }

                left++;
            }

            right++;
        }

        if (minl == INT_MAX)
            return "";

        return s.substr(start, minl);
    }
};