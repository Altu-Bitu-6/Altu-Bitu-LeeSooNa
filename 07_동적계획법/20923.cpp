#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;  // 0: 도도, 1: 수연
const int DO = 0, SU = 1;

/** 승리 판단하기 */
string judge(cards& deck) {
	int do_deck = deck[DO].size(), su_deck = deck[SU].size(); //덱의 사이즈 입력

	if (do_deck > su_deck) { //덱에 더 많은 카드를 지닌 사람이 승리
		return "do";
	}
	else if (do_deck < su_deck) { //덱에 더 많은 카드를 지닌 사람이 승리
		return "su";
	}
	return "dosu"; //비긴 경우
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) { //그라운드가 빌 때 까지
		deck.push_back(ground.back()); //덱에 push
		ground.pop_back(); //그라운드 pop
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]);// 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도: 카드의 숫자가 5일 때
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도: 카드의 숫자가 5일 때
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연
		return SU; //: 그라운드의 숫자 합이 5일 때
	}
	return -1; // 종을 울릴 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저

	while (m--) {//게임 진행횟수만큼 반복
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //내려놓았으므로 pop

		if (deck[turn].empty()) { //덱의 카드 개수가 0인 경우
			break;
		}

		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
    if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck);//결과 반환
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2;
	cards deck(2), ground(2); // 0: 도도, 1: 수연

	// 입력
	cin >> n >> m; //n: 카드개수, m: 게임 진행 횟수

	while (n--) { //각각의 카드 숫자 입력
		cin >> card1 >> card2;
		deck[DO].push_front(card1);
		deck[SU].push_front(card2);
	}

	// 출력 & 연산
	cout << game(m, deck, ground);
	
	return 0;
}