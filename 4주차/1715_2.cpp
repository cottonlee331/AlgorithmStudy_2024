// 백준 1715 우선순위 큐 사용

#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    priority_queue<int,vector<int>,greater<int>> que;
    int sum = 0;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        que.push(tmp);
    }

    if(n == 1){
        cout<<0;
    }
    else{
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        sum += a+b;
        que.push(a+b);
        while(!que.empty()){
            a = que.top();
            que.pop();
            if(que.empty()){
                break;
            }
            b = que.top();
            que.pop();
            que.push(a+b);
            sum+=a+b;
        }
        cout<<sum;
    }
}