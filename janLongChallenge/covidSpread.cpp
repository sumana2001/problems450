#include <iostream>

using namespace std;

int main()
{
    int t;
    long n, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        long infected = 1;
        for (long i = 1; i <= d; i++)
        {
            if (i <= 10)
            {
                infected *= 2;
                if (infected > n)
                {
                    infected = n;
                    break;
                }
            }
            else
            {
                infected *= 3;
                if (infected > n)
                {
                    infected = n;
                    break;
                }
            }
        }
        cout << infected << endl;
    }
    return 0;
}