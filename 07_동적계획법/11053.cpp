#include <iostream>
#include <vector>

using namespace std;

int arr[1001]; //전체 수열
vector<int> dp(1001, 1); // 부분 수열 크기, 1로 초기화

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) //전체 수열 생성
        cin >> arr[i];

    for (int i = 0; i < n; i++) { //부분 수열
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
        
    cout << ans << endl;
    return 0;
}