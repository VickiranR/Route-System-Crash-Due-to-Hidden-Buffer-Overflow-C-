#include <iostream>

#define MAX_WAYPOINTS 5

class RouteManager {
private:
    int waypoints[MAX_WAYPOINTS]; // Fixed-size array
    int count;

public:
    RouteManager() : count(0) {}

    void addWaypointUnsafe(int wp) {
        // Hidden bug: no bounds check!
        waypoints[count] = wp;
        count++;  // Will go above MAX_WAYPOINTS eventually
    }

    void loadWaypoints() {
        std::cout << "[*] Loading waypoints...\n";
        for (int i = 0; i < MAX_WAYPOINTS + 2; ++i) {  // Purposely over-limit
            addWaypointUnsafe(100 + i);  // Unsafe internal write
        }
        std::cout << "[*] Waypoints loaded.\n";
    }

    int getWaypoint(int index) {
        if (index >= 0 && index < MAX_WAYPOINTS) {
            return waypoints[index];
        }
        return -1;
    }

    void printWaypoints() {
        std::cout << "[*] Route: ";
        for (int i = 0; i < MAX_WAYPOINTS; ++i) {
            std::cout << getWaypoint(i) << " ";
        }
        std::cout << "\n";
    }
};

class Router {
public:
    void calculate(RouteManager& rm) {
        std::cout << "[*] Starting route calculation...\n";
        rm.printWaypoints();  // This may crash due to corrupted memory
        std::cout << "[+] Route calculation complete!\n";
    }
};

int main() {
    std::cout << "[*] Initializing Route Manager...\n";
    RouteManager rm;
    rm.loadWaypoints();  // Triggers hidden buffer overflow

    Router r;
    r.calculate(rm);  // Crashes or prints junk due to overflow

    std::cout << "[*] Program finished.\n";
    return 0;
}
