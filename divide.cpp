class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; 
        if (dividend == divisor) return 1;

        bool sign = (dividend >= 0) == (divisor >= 0);
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            long long temp = d, cnt = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            n -= temp;
        }

        if (!sign) ans = -ans;
        return (int)ans;
    }
};
