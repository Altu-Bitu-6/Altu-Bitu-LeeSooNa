#include <iostream>
#include <vector>

using namespace std;

int main(){

  //계단개수 입력
  int n;
  cin >> n;

  vector <int> arr(n);
  vector <int> dp(n,0);

  //계단의 점수 입력
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  dp[0] = arr[0]; //1번째 계단 최댓값 = 1번째 계단 점수
  dp[1] = arr[0] + arr[1]; //2번째 계단 최대값 = 1번째 + 2번째
  dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]); //3번째 계단 최댓값 = 2+3 혹은 1+3의 최댓값

  for(int i=3;i<n;i++){ //4번째 계단의 최댓값 부터는 1,2,3번째 계단을 활용한다
    dp[i] = max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]);
  }

  // 출력
  cout << dp[n-1]<<'\n';

}