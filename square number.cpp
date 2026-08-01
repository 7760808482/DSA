#include <iostream>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T,N;

    cin >> T;

    for(int i = 0; i < 5; i++)
    {
        cin >> N;
        cout << "Case #" << i << ": " << N*N << endl;
    }

    return 0;
}