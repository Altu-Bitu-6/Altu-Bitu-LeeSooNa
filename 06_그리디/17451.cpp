#include <iostream>
#include <vector>

using namespace std;

int arr[300000] = {};


int main(){

  int i,n;
  long long speed;

  //입력
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  
  //마지막 행성의 속도
  speed = arr[n-1];

  for(int i=n-2; i>=0;i--){
    if (arr[i]>speed){ //현재 속도가 작을 경우
      speed = arr[i];//i번째 속도로
    }else{
      if(speed%arr[i]){ 
        speed = (speed/arr[i] + 1) * arr[i]; //배수
      }
    }
  }
  cout << speed;

  return 0;
}