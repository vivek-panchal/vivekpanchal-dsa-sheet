#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
bool isValid(vector<ll > v, ll p,int time)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)// this loop will give no. of paratha made in the specified time
    {
        int t = time;
        int count = 0,k=1;
        while (t>0)
        {
            t = t - k*v[i];
            if (t >= 0)
            {
                count++;
                k++;
            }
        }
        sum += count;
        //cout << count << endl;
    }
    //cout << "parathas made " << sum << endl;
    if (sum < p)
        return false;
    return true;

}

ll check_ans(vector<ll> v, ll p)
{
    ll s = 0, e = (v[0] * p*(p + 1)) / 2;// we can consider the maximum time taking that all th parathas are cooked by the first cook
    ll mid = (s + e) / 2;
    ll  ans;
    while (s <= e)
    {
        //cout << s << " " << e << " " << mid << endl;
        if (isValid(v,p,mid))
        {
            //cout << "valid"<<endl<<endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
        //    cout << "not valid" << endl;
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

int main()
{
    ll p, size;
    cin >> p >> size;
    vector<ll> v;
    while (size--)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    ll ans = check_ans(v, p);
    cout << ans << endl;

    return 0;
}
