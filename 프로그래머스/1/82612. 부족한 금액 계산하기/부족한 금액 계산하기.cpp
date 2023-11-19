using namespace std;

long long solution(int price, int money, int count)
{
    long long m = ((long long)price + (long long)price * count) * (long long)count / 2;
    if (money > m)
        return 0;
    else
        return m - money;
}