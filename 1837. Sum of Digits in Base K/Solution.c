int sumBase(int n, int k)
{
    int res = 0;
    for (; n; n /= k)
        res += n % k;
    return res;
}
