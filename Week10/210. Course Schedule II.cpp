class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build graph and count in-degrees
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        vector<int> result;

        // Start with nodes having 0 in-degree (no prerequisites)
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If we were able to take all courses
        if (result.size() == numCourses)
            return result;
        else
            return {}; // cycle detected
    }
};
