// 백준 10986

#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n, m;
    cin>>n>>m;

    long long sum = 0;
    vector<long long> modulo;
    for(int j = 0; j<m; j++){
        modulo.push_back(0);
    }

    long long result = 0;
    for(int i = 0; i < n; i++){
        long long tmp;
        cin>>tmp;
        sum+=tmp;
        result+=modulo[sum%(long long)m]++;
    }
    result+=modulo[0];
    cout<<result<<'\n';
}