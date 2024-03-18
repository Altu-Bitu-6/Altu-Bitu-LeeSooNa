#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc;


//input에 따라 이동하는 함수
cc move(string input, char x, char y){
  for(char how : input){
    if( how == 'R'){//명령이 R인 경우
      x++; //x좌표 양의 방향 이동
    }else if(how == 'L'){//명령이 L인 경우
      x--; //x좌표 음의 방향 이동
    }else if(how == 'B'){//명령이 B인 경우
      y--;//y좌표 음의 방향 이동
    }else{//명령이 T인 경우
      y++;//y좌표 양의 방향 이동
    }
   
  }
   return {x, y}; //이동한 좌표를 반환
}

// 돌과 킹의 좌표가 일치하는지 확인한다
bool isSame(cc k, cc s){
  return(k.first == s.first && k.second == s.second); //x좌표와 y좌표가 일치하는지
}

//체스판의 범위를 넘어서는지 확인한다
bool checkRange(cc pos){
  if(pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8'){ //범위를 넘어서면
    return false; //false 반환
  }
  return true; //넘어서지 않는다면 true 반환
}


int main(){
  cc k, s; //king, stone의 위치
  int n; //움직이는 횟수
  string input; //명령

  //입력
  cin>>k.first >> k.second >> s.first >> s.second >> n;

  while(n--){

    cin >> input; //이동명령

    cc next_k, next_s; //각각 이동할 위치 

    //king 이동
    next_k = move(input, k.first, k.second);

    //stone 이동
    if(isSame(next_k,s)){ //이동한 king과 stone의 위치가 일치하면
      //king이 움직인 방향과 같은 방향으로 이동
      next_s = move(input, s.first, s.second);
    }else{
      next_s = s; //일치하지 않는다면 제자리
    }

    //체스판 밖으로 나가지 않을 경우만 이동
    if(checkRange(next_k) && checkRange(next_s)){
      k = next_k; //이동
      s = next_s; //이동
    }

  }

  //출력
  cout << k.first << k.second << '\n' << s.first << s.second;

  return 0;
}