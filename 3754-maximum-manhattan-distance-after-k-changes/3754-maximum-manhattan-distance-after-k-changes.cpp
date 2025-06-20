class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0;
        int maxDist = 0;
        int gainSum = 0;

        // Min-heap to store top k gain values
        priority_queue<int, vector<int>, greater<int>> pq;

        for (char c : s) {
            int dx = 0, dy = 0;

            if (c == 'N') dy = 1;
            else if (c == 'S') dy = -1;
            else if (c == 'E') dx = 1;
            else if (c == 'W') dx = -1;

            int prevX = x, prevY = y;
            x += dx;
            y += dy;

            int originalDist = abs(x) + abs(y);
            int bestGain = 0;

            // Try all 3 other directions
            vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            for (auto [nx, ny] : dirs) {
                if (nx == dx && ny == dy) continue; // same direction
                int altX = prevX + nx;
                int altY = prevY + ny;
                int altDist = abs(altX) + abs(altY);
                bestGain = max(bestGain, altDist - originalDist);
            }

            if (bestGain > 0) {
                pq.push(bestGain);
                gainSum += bestGain;

                if (pq.size() > k) {
                    gainSum -= pq.top();
                    pq.pop();
                }
            }

            maxDist = max(maxDist, originalDist + gainSum);
        }

        return maxDist;
    }
};
