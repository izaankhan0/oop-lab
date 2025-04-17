#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interface for Booking System
class IBooking {
public:
    virtual bool reserveSeat(int) = 0;
    virtual bool revokeSeat(int passengerID) = 0;
    virtual bool elevateSeat(int passengerID) = 0;
};

class AirRoute : public IBooking {
private:
    string routeCode;
    string origin;
    string destination;
    int totalSeats;
    int currentBookings;
    vector<int> travelerIDs;

public:
    AirRoute(string code, string from, string to, int seats)
        : routeCode(code), origin(from), destination(to), totalSeats(seats), currentBookings(0) {}

    bool reserveSeat(int travelerID) override {
        if (currentBookings >= totalSeats) {
            cout << "[Reserve Failed] Route " << routeCode << " has no available seats.\n";
            return false;
        }

        for (int id : travelerIDs) {
            if (id == travelerID) {
                cout << "[Reserve Failed] Traveler already has a seat on " << routeCode << ".\n";
                return false;
            }
        }

        travelerIDs.push_back(travelerID);
        currentBookings++;
        cout << "[Reserve Success] Traveler " << travelerID << " booked on route " << routeCode << ".\n";
        return true;
    }

    bool revokeSeat(int travelerID) override {
        for (size_t i = 0; i < travelerIDs.size(); ++i) {
            if (travelerIDs[i] == travelerID) {
                travelerIDs.erase(travelerIDs.begin() + i);
                currentBookings--;
                cout << "[Revoke Success] Traveler " << travelerID << " removed from route " << routeCode << ".\n";
                return true;
            }
        }
        cout << "[Revoke Failed] Traveler " << travelerID << " not found on route " << routeCode << ".\n";
        return false;
    }

    bool elevateSeat(int travelerID) override {
        for (int id : travelerIDs) {
            if (id == travelerID) {
                cout << "[Upgrade Success] Traveler " << travelerID << " upgraded on route " << routeCode << ".\n";
                return true;
            }
        }
        cout << "[Upgrade Failed] No reservation found for traveler " << travelerID << ".\n";
        return false;
    }

    void showRouteInfo() const {
        cout << "Route: " << routeCode << " | Origin: " << origin << " | Destination: " << destination
             << " | Capacity: " << totalSeats << " | Seats Booked: " << currentBookings << endl;
    }
};

class Traveler {
private:
    int travelerID;
    string travelerName;

public:
    Traveler(int id, string name) : travelerID(id), travelerName(name) {}

    bool bookSeat(AirRoute &route) { return route.reserveSeat(travelerID); }
    bool cancelSeat(AirRoute &route) { return route.revokeSeat(travelerID); }
    bool upgradeSeat(AirRoute &route) { return route.elevateSeat(travelerID); }

    void showTravelerInfo() const {
        cout << "Traveler: " << travelerName << " | ID: " << travelerID << endl;
    }
};

int main() {
    AirRoute route1("SK123", "Lahore", "Istanbul", 2);
    AirRoute route2("EM404", "Dubai", "Berlin", 1);

    Traveler t1(201, "Usman");
    Traveler t2(202, "Ayan");
    Traveler t3(203, "Hamza");

    route1.showRouteInfo();
    route2.showRouteInfo();
    cout << endl;

    t1.bookSeat(route1);
    t2.bookSeat(route1);
    t3.bookSeat(route1); // Should fail (full)

    t2.cancelSeat(route1);
    t3.bookSeat(route1); // Should succeed now
    t3.upgradeSeat(route1); // Should succeed

    cout << "\n--- Final Route Status ---\n";
    route1.showRouteInfo();
    route2.showRouteInfo();

    return 0;
}
