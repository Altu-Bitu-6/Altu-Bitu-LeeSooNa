#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

vector <int>v; //수열 입력 받음

//순열 생성 : dfs 사용
void dfs(int start){
  if(start == m){ //길이가 m인 수열 출력
    for(int i=0;i<m;i++){
      cout << arr[i] << ' ';
    }
    cout << "\n";
  }else{
    for(int i=1;i<=v.size()-1; i++){ 
      arr[start] = v[i-1];
      dfs(start + 1); //재귀 함수로 순열 생성
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(0);

  cin >> n >> m;
  //수열 생성 : 숫자 입력받아 벡터에 저장
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    v.push_back(num);
  }
  //입력받은 숫자를 정렬
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(),v.end()), v.end()-1); //중복 제거
  dfs(0);
}