class Solution {
public:
    bool check(string a, string b, string rest) {
        if (a.size() > 1 && a[0] == '0') return false;
        if (b.size() > 1 && b[0] == '0') return false;

        while (!rest.empty()) {
            string sum = add(a, b);

            if (rest.substr(0, sum.size()) != sum)
                return false;

            rest = rest.substr(sum.size());

            a = b;
            b = sum;
        }

        return true;
    }

    string add(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res += char('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        // Choose first number
        for (int i = 1; i <= n - 2; i++) {

            // Leading zero
            if (num[0] == '0' && i > 1)
                break;

            string a = num.substr(0, i);

            // Choose second number
            for (int j = i + 1; j <= n - 1; j++) {

                if (num[i] == '0' && j - i > 1)
                    break;

                string b = num.substr(i, j - i);
                string rest = num.substr(j);

                if (check(a, b, rest))
                    return true;
            }
        }

        return false;
    }
};
