#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //톱니바퀴를 저장 li[0]-> 첫 톱니바퀴 저장
vector<pair<int, int> > stack; //회전해야하는 톱니바퀴의 인덱스와 방향
vector<int> visited; // 방문할 필요 없는 톱니바퀴를 저장

void check_rotation(int current_num, int current_dir) { //매개변수 : 현재 기준이되는 모든 바퀴의 인덱스, 회전 방향
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) { //검사 가능 조건(오른쪽)
        if (li[current_num][6] != li[current_num - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); //가능하다면 저장
            visited[current_num - 1] = 1; //방문했음 저장
            check_rotation(current_num - 1, current_dir * -1); 
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) { //검사 가능 조건(왼쪽)
        if (li[current_num][2] != li[current_num + 1][6]) { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); //가능하다면 저장
            visited[current_num + 1] = 1; //방문했음 저장
            check_rotation(current_num + 1, current_dir * -1);
        }
    }
}

int main() {
    int t;
    int k;

    cin >> t; //입력 : 톱니바퀴의 개수 T

    li.resize(t); //톱니바퀴 개수만큼 resize

    for (int i = 0; i < t; ++i)
        cin >> li[i]; //톱니바퀴 상태 입력

    cin >> k; // 톱니바퀴 회전 횟수 K 입력


    //첫 번째로 돌려야할 톱니바퀴에 대해 바로 회전
    for (int i = 0; i < k; ++i) { //k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;
        cin >> num >> direction; //방향 입력 (1이면 시계 방항, -1이면 반시계 방향)

        stack.clear(); //초기화
        stack.push_back(make_pair(num - 1, direction)); //톱니바퀴의 인덱스 = 번호-1
        visited.assign(t, 0); //t개만큼 0을 초기화
        visited[num - 1] = 1; //방문했음 표기
        check_rotation(num - 1, direction); //돌릴 톱니바퀴에 대한 체크함수

        while (!stack.empty()) { //톱니바퀴를 회전
            pair<int, int> top = stack.back();
            stack.pop_back();

            int tmp_num = top.first; //돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; //돌릴 방향
            if (tmp_dir == 1) { //시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); //인덱스 : 0번 -> 1번 , 7번 -> 0번  
            } else { //반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0]; //인덱스 : 0번 -> 7번 , 1번 -> 0번
            }
        }
    }
    //12시 방향이 S극인 톱니바퀴 개수 세기
    int cnt = 0;
    for (int i = 0; i < t; ++i) {
        if (li[i][0] == '1') { //첫 번째 index 1일 때 증가
            cnt++;
        }
    }

    cout << cnt << endl; //결과 출력
 
    return 0;
}