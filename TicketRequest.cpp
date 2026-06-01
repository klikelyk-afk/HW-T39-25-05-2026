#include "TicketRequest.h"

int TicketRequest::idCounter = 1;

TicketRequest::TicketRequest()
{
    id = idCounter++;
    destination = "undefined";
    passengerName = "undefined";
    departureDate = "undefined";
}

TicketRequest::TicketRequest(string destination, string passengerName, string departureDate)
{
    this->id = idCounter++;
    this->destination = destination;
    this->passengerName = passengerName;
    this->departureDate = departureDate;
}

int TicketRequest::getId() const {
    return id;
}
string TicketRequest::getDestination() const {
    return destination;
}
string TicketRequest::getPassengerName() const {
    return passengerName;
}
string TicketRequest::getDepartureDate() const {
    return departureDate;
}

void TicketRequest::setDestination(string destination) { 
    this->destination = destination; 
}
void TicketRequest::setPassengerName(string passengerName) {
    this->passengerName = passengerName; 
}
void TicketRequest::setDepartureDate(string departureDate) { 
    this->departureDate = departureDate;
}

void TicketRequest::showInfo() const
{
    cout << "ID: " << id
        << " | Пункт призначення: " << destination
        << " | Пасажир: " << passengerName
        << " | Дата вильоту: " << departureDate << endl;
}

bool TicketRequest::operator<(const TicketRequest& other) const
{
    if (this->destination != other.destination) {
        return this->destination < other.destination;
    }
    if (this->departureDate != other.departureDate) {
        return this->departureDate < other.departureDate;
    }
    return this->id < other.id;
}