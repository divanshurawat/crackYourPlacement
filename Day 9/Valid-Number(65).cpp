class Solution {
public:
    bool isNumber(string s) {
        // Helper function to trim spaces from both ends of the string
        auto trim = [](std::string& str) {
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
            str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), str.end());
        };

        trim(s);

        bool pointPresent = false;
        bool ePresent = false;
        bool numberPresent = false;
        bool numberAfterE = true;

        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                numberPresent = true;
                numberAfterE = true;
            } else if (s[i] == '.') {
                if (ePresent || pointPresent) {
                    return false;
                }
                pointPresent = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (ePresent || !numberPresent) {
                    return false;
                }
                numberAfterE = false;
                ePresent = true;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return numberPresent && numberAfterE;
    }
};
