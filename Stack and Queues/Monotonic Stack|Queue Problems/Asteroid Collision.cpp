/*
 * Problem: Asteroid Collision
 * Platform: LeetCode
 * 
 * Description:
 *   We are given an array of integers representing asteroids moving in a row.
 *   - Positive values → asteroids moving right.
 *   - Negative values → asteroids moving left.
 * 
 *   All asteroids move at the same speed. When two asteroids meet:
 *   - The smaller one explodes.
 *   - If they are the same size, both explode.
 *   - Asteroids moving in the same direction never collide.
 *
 *   Return the state of the asteroids after all collisions.
 *
 * Approaches:
 *   1. Brute Force Simulation
 *   2. Optimized using Stack
 */

/* ---------------- BRUTE FORCE ----------------
 * Idea:
 *   - Repeatedly scan through the list and check adjacent asteroids.
 *   - If a right-moving asteroid (positive) meets a left-moving asteroid (negative),
 *     simulate the collision and update the array.
 *   - Keep doing this until no more collisions happen.
 *
 * Time Complexity: O(n^2) 
 *   - Each pass may shrink array by at most 1 asteroid.
 *   - Worst case requires O(n) passes for n asteroids.
 * Space Complexity: O(1) 
 *   - We modify the array directly (besides result container).
 */
class SolutionBrute {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool changed = true;
        while (changed) {
            changed = false;
            vector<int> temp;
            for (int i = 0; i < asteroids.size(); i++) {
                if (!temp.empty() && temp.back() > 0 && asteroids[i] < 0) {
                    // Collision detected
                    if (abs(temp.back()) == abs(asteroids[i])) {
                        temp.pop_back(); // both destroyed
                    } else if (abs(temp.back()) < abs(asteroids[i])) {
                        temp.pop_back(); // right asteroid destroyed
                        i--; // recheck current asteroid against new top
                    }
                    changed = true;
                } else {
                    temp.push_back(asteroids[i]);
                }
            }
            asteroids = temp; // update after this pass
        }
        return asteroids;
    }
};

/* ---------------- OPTIMIZED (STACK) ----------------
 * Idea:
 *   - Use a stack to keep track of "surviving" asteroids.
 *   - Iterate through the list:
 *     - If asteroid is positive (moving right), just push it.
 *     - If asteroid is negative (moving left), check for collisions with stack top:
 *       * While stack top is smaller right-moving asteroid → pop it.
 *       * If equal → pop stack top (both destroyed).
 *       * If stack is empty or top is negative → push current asteroid.
 *
 * Time Complexity: O(n)
 *   - Each asteroid is pushed and popped at most once.
 * Space Complexity: O(n)
 *   - Stack may hold all asteroids in the worst case.
 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> st;   // acts like a stack
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                // Right-moving asteroid → always safe
                st.push_back(arr[i]);
            } else {
                // Left-moving asteroid
                while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i])) {
                    // Destroy smaller right-moving asteroids
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(arr[i])) {
                    // Both same size → destroy both
                    st.pop_back();
                } else if (st.empty() || st.back() < 0) {
                    // No collision possible → push it
                    st.push_back(arr[i]);
                }
                // else: st.back() is bigger positive → current asteroid destroyed
            }
        }

        return st;
    }
};
