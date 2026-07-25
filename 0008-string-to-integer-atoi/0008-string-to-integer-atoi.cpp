class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == ' ') i++;

        int sg = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sg = -1;
            i++;
        }

        long r = 0;
        while (i < n && isdigit(s[i])) {
            r = r * 10 + (s[i] - '0');
            if (r * sg > INT_MAX) return INT_MAX;
            if (r * sg < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(r * sg);
    }
};