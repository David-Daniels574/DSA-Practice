#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;

class hello
{
    static int a;
    static int b;
    private:
        const int x=5;
    public:
        hello(){
                cout<<"Hi"<<endl;
        }
        void getx(){
            cout<<this->x<<endl;
        }
        ~hello(){
            cout<<"del"<<endl;
        }
    static void hello1(){
        cout << "interacting\n";
        cout << a * b << endl;
    }
};

int hello::a = 2;
int hello::b = 3;


int main() {
     int x = 0;

    while (true) {
        // Check if x*10 + 1 would overflow INT_MAX
        if (x > (INT_MAX - 1) / 10)
            break;

        x = x * 10 + 1;
        cout << x << ", ";
    }
}