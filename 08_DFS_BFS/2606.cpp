#include <iostream>
#include <vector>
using namespace std;

vector<int> a[101]; //연결된 네트워크 저장
bool visited[101]; //방문 여부 확인
int cnt=0;

void dfs(int x){
    visited[x] = true;

    for(int i=0;i<a[x].size();i++){ //연결된 모든 node 탐색
        int y = a[x][i];

        if(!visited[y]){ //방문하지 않은 node
            dfs(y);
            cnt++;
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m; //컴퓨터의 수, 연결된 컴퓨터 쌍의 수

    for(int i=0;i<m;i++){ //m개의 연결된 컴퓨터
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1); //1번 컴퓨터를 통해 바이러스에 걸리는 컴퓨터 수 
    cout << cnt <<"\n";
}