#include <bits/stdc++.h>
using namespace std;

int N, W;
int wt[25], val[25];

int solve(int i, int w) {
    if (i == N) return 0;   // no more items

    int best = 0;

    // Case 1: skip item i
    best = solve(i + 1, w);

    // Case 2: take item i (only if fits)
    if (wt[i] <= w) {
        best = max(best, val[i] + solve(i + 1, w - wt[i]));
    }

    return best;
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> wt[i] >> val[i];

    cout << solve(0, W);
}
