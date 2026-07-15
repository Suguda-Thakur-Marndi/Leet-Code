class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;

        for (string email : emails) {
            string local = "";
            string domain = "";
            
            int i = 0;

            while (email[i] != '@') {
                if (email[i] == '.') {
                    i++;
                    continue;
                }

                if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                    break;
                }

                local += email[i];
                i++;
            }

            while (i < email.size()) {
                domain += email[i];
                i++;
            }

            s.insert(local + domain);
        }

        return s.size();
    }
};