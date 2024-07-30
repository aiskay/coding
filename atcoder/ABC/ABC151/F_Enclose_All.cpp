#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

double solution(vector<int>& x, vector<int>& y)
{
    int N = x.size();

    auto dist = [&](double x_c, double y_c){  // 円の中心を選んだときの最遠点との距離
        double d = 0;
        REP(i, N) d = max(d, pow(x[i]-x_c, 2) + pow(y[i]-y_c, 2));
        return sqrt(d);
    };
    auto min_dist = [&](double x_c){  // 円の中心の x 座標を選んだときの最遠点との最小距離
        double y_l = 0, y_r = 1e+3;
        REP(_, 80){  
            double c_l = (2*y_l+y_r)/3;
            double c_r = (y_l+2*y_r)/3;
            if(dist(x_c, c_l) > dist(x_c, c_r)) y_l = c_l;
            else y_r = c_r;
        }
        return dist(x_c, y_l);
    };

    double x_l = 0, x_r = 1e+3;
    REP(_, 80){  // double の探索では while より回数を決めて for を回した方がエラーを避けやすい
        double c_l = (2*x_l+x_r)/3;
        double c_r = (x_l+2*x_r)/3;
        if(min_dist(c_l) > min_dist(c_r)) x_l = c_l;
        else x_r = c_r;
    }
    return min_dist(x_l);
}

int main()
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];

    cout << fixed << setprecision(7) << solution(x, y) << endl;

    return 0;
}