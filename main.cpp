#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream infile("ruck.in");

x struct wc{
    int w,c;
};
vector<wc> v;
int main(){
    int n,W;
    infile >> n >> W;
    v = vector<wc>(n+1);
    int ww, cc;
    for(int i=1; i<=n;i++){
        infile >> ww >> cc;
        v[i].w = ww;
        v[i].c = cc;
    }
    vector<vector<int>> d(n+1, vector<int> (W+1, 0));
    int last = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            d[i][j] = d[i-1][j];
            if(j - v[i].w >=0){
                if(d[i-1][j-v[i].w]+v[i].c > d[i][j] && last != d[i-1][j-v[i].w]+v[i].c) {
                    last = d[i-1][j-v[i].w]+v[i].c;
                    cout << i << "-" << j << " =" << d[i - 1][j - v[i].w] + v[i].c << endl;
                }
                d[i][j] = max(d[i][j], d[i-1][j-v[i].w]+v[i].c);

                //cout << d[i][j] << endl;
            }
            //cout << i<< " - " << j << " : " << d[i][j] << " ";
        }
        //cout << endl;
    }
    cout << d[n][W] << endl;
    return 0;
}
