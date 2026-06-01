#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class TicketRequest
{
private:
    static int idCounter;
    int id;
    string destination;
    string passengerName;
    string departureDate;

public:
    TicketRequest();
    TicketRequest(string destination, string passengerName, string departureDate);

    int getId() const;
    string getDestination() const;
    string getPassengerName() const;
    string getDepartureDate() const;

    void setDestination(string destination);
    void setPassengerName(string passengerName);
    void setDepartureDate(string departureDate);


    void showInfo() const;

    bool operator<(const TicketRequest& other) const;
};