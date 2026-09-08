class Solution {
public:
    unordered_set<string> st;

    bool canForm(string word) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) continue;

                string part = word.substr(j, i - j);

                if (st.count(part)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words) {
            st.insert(word);
        }

        vector<string> ans;

        for (string word : words) {
            st.erase(word);  // Don't allow the word to use itself

            if (canForm(word)) {
                ans.push_back(word);
            }

            st.insert(word);
        }

        return ans;
    }
};
