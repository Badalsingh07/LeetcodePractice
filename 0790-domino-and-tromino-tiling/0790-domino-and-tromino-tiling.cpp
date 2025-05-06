#include <array>

using i64 = long long;

constexpr int MOD = 1E9 + 7;
constexpr int MAX_N = 1000;

class Solution {
 public:
  int numTilings(int n) {
    // dp[i] = dp[i-1] + dp[i-2] + 2 * g[i-1] // symmetrical
    // g[i] = dp[i-2] + g[i-1]                // PLACE a HORIZONTAL DOMINO TOO
    // NOTE: we can eliminate tracking of the state of g.
    // re-arranging g[i]=dp[i-2]+g[i-1]
    //            g[i-1]=g[i]-dp[i-2] --- (1)
    //        and g[i]-g[i-1]=dp[i-2] --- (2)
    // Then, from (1):
    //       dp[i]=dp[i-1]+dp[i-2]+2(g[i]-dp[i-2])
    //            =dp[i-1]-dp[i-2]+2g[i] --- (3)
    //     dp[i-1]=dp[i-2]+dp[i-3]+2(g[i-1]-dp[i-3])
    //            =dp[i-2]-dp[i-3]+2g[i-1] --- (4)
    // then substituting dp[i] - dp[i-1] (to get the transition):
    // dp[i]-dp[i-1]=(dp[i-1]-dp[i-2]+2g[i])-(dp[i-2]-dp[i-3]+2g[i-1])
    //              =dp[i-1]-2dp[i-2]+dp[i-3] + 2(g[i]-g[i-1])
    //              =dp[i-1]-2dp[i-2]+dp[i-3]+2dp[i-2] // substitute (1)
    //              =dp[i-1]+dp[i-3]
    // dp[i]        =2dp[i-1]+dp[i-3] // isolate dp[i]
    // Thus, we get a single-state recurrence.
    auto modPlus = [](i64 a, i64 b) -> int { return (a + b) % MOD; };
    std::array<int, MAX_N + 1> dp{};
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = modPlus(dp[i], 2LL * dp[i - 1] + dp[i - 3]);
    }
    return dp[n];
  }

  int numTilingsTwoState(int n) {
    // domino : xx
    // tromino: yy
    //          y
    // Number of ways to tile 2xn board.
    // Note that symmetrical tilings are considered.
    //
    // - 2xn means that this is effectively 1-dimensional.
    // - Even number of Tromino tiles must be used to tile the board.
    //   i.e., placed in pairs.
    // Hm. There are 4 block patterns in increasing order
    // x
    // x
    // ---
    // xx
    // yy
    // ---
    // xxy (can be rotated)
    // xyy
    // ---
    // xxyy (can be rotated)
    // xzzy
    //
    // DP?
    // based on width?
    // Then the transitions:
    // dp[i] = (2*dp[i-4]) + (2*dp[i-3]) + dp[i-2] + dp[i-1]
    //
    // NOPE. Wrong. On the right-track for tiling with dominoes. But not for
    // trominoes.
    // dp[i] = dp[i-1] + dp[i-2] // number of ways to end with 1/2 dominoes.
    // To add trominoes, consider the state at i-1:
    // _ | _  and x | _
    // x | _      _ | _
    // There must be an empty slot indicating a tromino was placed earlier.
    // Thus, we need to keep track of this additional state.
    // Suppose we have this state g(n).
    // Then, we can now complete our transitions:
    // dp[i] = dp[i-1] + dp[i-2] + 2 * g[i-1] // symmetrical
    // g[i] = dp[i-2] + g[i-1]                // PLACE a HORIZONTAL DOMINO TOO
    auto modPlus = [](i64 a, i64 b) -> int { return (a + b) % MOD; };
    std::array<int, MAX_N + 1> dp{}, incomplete{};
    // base cases for simplified loop.
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      // dp[i] = dp[i-1] + dp[i-2] + 2*g[i-1]
      dp[i] = modPlus(dp[i], 1LL * dp[i - 1] + dp[i - 2]);
      dp[i] = modPlus(dp[i], 2LL * incomplete[i - 1]);

      // g[i] = dp[i-2] + g[i-1]
      incomplete[i] =
          modPlus(incomplete[i], 1LL * dp[i - 2] + incomplete[i - 1]);
    }
    return dp[n];
  }
};