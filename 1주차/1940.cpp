// 백준 1940

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> id;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        id.push_back(tmp);
    }

    sort(id.begin(),id.end());
    vector<bool> visited(id.back(),false);

    int result = 0;
    for(int j = 0; j<n; j++){
        if(visited[id[j]]){
            continue;
        }
        int target = m-id[j];
        if(target == id[j]){
            continue;
        }
        else if(binary_search(id.begin(),id.end(),target)){
            visited[id[j]] = true;
            visited[target] = true;
            result++;
        }
    }

    cout<<result;
}