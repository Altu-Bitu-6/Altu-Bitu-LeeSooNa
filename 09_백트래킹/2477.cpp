#include <iostream>
#include <vector>
using namespace std;

int main(){

  int n;
  cin >> n; //밭에서 자라는 참외의 수

  pair<int, int> arr[12];
  int maxArea, emptyArea;
  int dir, len;

  //변의 길이 입력
  for(int i=0; i<6;i++){
    cin >> dir >> len;
    arr[i] = arr[i+6] = {dir, len};
  } //길이가 12인 arr에 방향과 길이를 입력함

  //ABAB 형태로 반복되는 길이를 발견하면 emptyArea의 가로세로 길이가 됨
  for(int i=3; i<12 ;i++){
    if(arr[i].first == arr[i-2].first && arr[i-1].first == arr[i-3].first)
    {
      maxArea = arr[i+1].second * arr[i+2].second;
      emptyArea = arr[i-1].second * arr[i-2].second;

      break;
    }
  }
    cout << n*(maxArea - emptyArea);
  return 0;

}