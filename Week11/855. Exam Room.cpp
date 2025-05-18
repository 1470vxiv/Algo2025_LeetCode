#include <set>
#include <iostream>
using namespace std;

class ExamRoom {
private:
    int n;
    set<int> seats;

public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        
        int maxDist = *seats.begin(); // distance from seat 0
        int pos = 0;
        
        int prev = -1;
        for (int s : seats) {
            if (prev != -1) {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    pos = prev + dist;
                }
            }
            prev = s;
        }
        
        // check the distance from the last seat
        if ((n - 1 - *seats.rbegin()) > maxDist) {
            pos = n - 1;
        }
        
        seats.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};
