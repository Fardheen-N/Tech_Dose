class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m * n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, n, mid, k))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    bool check(int m, int n, int x, int k) {
        int cnt = 0;
        int num = x / m;
        cnt+=num*m;
        for (int i = num; i<n; i++) {
            cnt+=(x/(i+1));
        }
        return cnt<k;
    }
};