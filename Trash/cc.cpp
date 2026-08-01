class Solution
{
private:
    bool check(long double dist, int k, vector<int> &v)
    {
        int cnt = 0;
        int n = v.size();
        for (int i = 0; i < n - 1; i++)
        {
            int numberInBetween = (v[i + 1] - v[i]) / dist;

            if (numberInBetween * dist == v[i + 1] - v[i])
            {
                numberInBetween--;
            }

            cnt += numberInBetween;
        }

        if (cnt > k)
            return true;
        else
            return false;
    }

public:
    double minMaxDist(vector<int> &v, int k)
    {
        int n = v.size();

        long double low = 0, high = 0;
        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (long double)(v[i + 1] - v[i]));
        }

        while (high - low > 1e-6)
        {
            long double mid = (long double)(high + low) / (2.0);
            if (check(mid, k, v))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return high;
    }
};