class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map each stop to the buses that go through it
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;

        q.push(source);
        visitedStops.insert(source);

        int busesTaken = 0; //result

        while (!q.empty()) {
            int levelSize = q.size();
            busesTaken++;

            //BFS
            for (int i = 0; i < levelSize; i++) {
                int currStop = q.front(); //本層從currStop出發
                q.pop();

                for (int bus : stopToBuses[currStop]) {
                    if (visitedBuses.count(bus)) continue;

                    visitedBuses.insert(bus); //造訪currStop對應的bus

                    for (int nextStop : routes[bus]) {
                        if (nextStop == target) return busesTaken; //hit
                        if (!visitedStops.count(nextStop)) { //若nextStop未被造訪
                            visitedStops.insert(nextStop);
                            q.push(nextStop); //q插入當前bus對應的nextStop
                        }
                    }
                }
            }
        }

        return -1; // Not reachable
    }
};
