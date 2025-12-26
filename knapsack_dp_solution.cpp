#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> wt(N), val(N);
    for (int i = 0; i < N; i++)
        cin >> wt[i] >> val[i];

    // dp[i][w] = best value using items i..N-1 with capacity w
    int dp[25][105];

    // Base case: when i == N → no items left → all zero
    for (int w = 0; w <= W; w++)
        dp[N][w] = 0;

    // Fill table from bottom-up
    for (int i = N - 1; i >= 0; i--) {
        for (int w = 0; w <= W; w++) {

            // Option 1: skip item i
            dp[i][w] = dp[i + 1][w];

            // Option 2: take item i (if it fits)
            if (wt[i] <= w) {
                dp[i][w] = max(dp[i][w], val[i] + dp[i + 1][w - wt[i]]);
            }
        }
    }

    // Answer = best using items 0..N-1 with capacity W
    cout << dp[0][W] << endl;

    return 0;
}
