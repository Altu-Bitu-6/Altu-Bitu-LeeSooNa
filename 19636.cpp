#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {//반환값이 3개이므로 tuple 자료형 사용
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    while (d--) { //다이어트 기간 d만큼 반복
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a); // (case1) 변화하는 체중
        w2 += i - (m2 + a); // (case2) 변화하는 체중

        // 일일 기초대사량 변화 (m2만 변화)
        if (abs(i - (m2 + a)) > t) { //역치보다 변화가 클 때
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            //                              C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            //                              => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0; //체중이 증가한 것/2만큼 증가
        }
    }
    return { w1, w2, m2 }; //3개의 반환값 존재 & m1은 연산하며 값이 바뀌지 않아 반환X
}
int main() {
    int w0, i0, i, a; //변수 정의
    int d, t; //입력받을 변수 정의 
    int final_weight, final_meta; //결과값 변수 정의
    cin >> w0 >> i0 >> t; //첫 줄 입력 (다이어트 전 체중, 다이어트 전 일일 에너지 섭취량 및 일일 기초대사량, 기초 대사량 변화 역치)
    cin >> d >> i >> a; //둘째 줄 입력 (다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량)

    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t); //tuple & 입력받은 6개의 값을 사용하는 함수 diet 정의
    int w1 = get<0>(tmp), m1 = i0;          // (case1) 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // (case2) 기초대사량 변화 고려 O 

    // (case1)
    if (w1 <= 0) { //체중이 0이하인 경우
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n"; //문구 출력
    }
    else { //체중이 0보다 크면
        cout << w1 << " " << m1 << "\n"; //예상체중과 일일기초대사량 출력
    }

    // (case2)
    if (w2 <= 0 || m2 <= 0) { //체중이 0이하 or 일일기초대사량이 0이하
        cout << "Danger Diet"; //문구 출력
    }
    else { //사망하지 않는 경우
        cout << w2 << " " << m2 << " "; //예상체중과 일일기초대사량 출력
        if (m2 < i0) {  // 일일기초대사량이 초기값보다 작은 경우
            cout << "YOYO"; //문구 출력
        }
        else { //그렇지 않으면
            cout << "NO"; //문구 출력
        }
    }
    return 0;
}