#include <iostream>
#include <set>
#include <string>
#include <Windows.h>
#include "TicketRequest.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;

void showAllRequests(const set<TicketRequest>& container) {
    if (container.empty()) {
        cout << "--- Немає доступних заявок ---" << endl;
        return;
    }
    cout << "\n--- Усі заявки на авіаквитки (відсортовані) ---" << endl;
    for (const auto& request : container) {
        request.showInfo();
    }
}

void deleteRequestById(set<TicketRequest>& container, int targetId) {
    auto it = container.begin();
    bool found = false;

    while (it != container.end()) {
        if (it->getId() == targetId) {
            it = container.erase(it);
            found = true;
            cout << "Заявку з ID " << targetId << " успішно видалено." << endl;
            break;
        }
        else {
            ++it;
        }
    }
    if (!found) {
        cout << "Заявку з ID " << targetId << " не знайдено." << endl;
    }
}

void showRequestsByDestination(const set<TicketRequest>& container, const string& dest) {
    bool found = false;
    cout << "\n--- Результати пошуку для: " << dest << " ---" << endl;
    for (const auto& r : container) {
        if (r.getDestination() == dest) {
            r.showInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "Заявок за цим пунктом призначення не знайдено." << endl;
    }
}

void countRequestsInDateRange(const set<TicketRequest>& container,
    const string& dest,
    const string& startDate,
    const string& endDate) {
    int count = 0;
    cout << "\n--- Відповідні заявки для " << dest << " з " << startDate << " по " << endDate << " ---" << endl;

    for (const auto& r : container) {
        if (r.getDestination() == dest && r.getDepartureDate() >= startDate && r.getDepartureDate() <= endDate) {
            r.showInfo();
            count++;
        }
    }
    cout << "Всього знайдено: " << count << endl;
}

int main() {

    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    set<TicketRequest> requests;
    int choice;

    requests.insert(TicketRequest("Kyiv", "Shevchenko T.G.", "2026-06-15"));
    requests.insert(TicketRequest("London", "Smith J.", "2026-07-20"));
    requests.insert(TicketRequest("Kyiv", "Petrenko I.I.", "2026-06-10"));

    while (true) {
        cout << "\n===== МЕНЮ =====" << endl;
        cout << "1. Додати заявку" << endl;
        cout << "2. Видалити заявку за ID" << endl;
        cout << "3. Вивести заявки за пунктом призначення" << endl;
        cout << "4. Визначити кількість заявок за напрямком і проміжком дат" << endl;
        cout << "5. Вивести всі заявки" << endl;
        cout << "0. Вихід" << endl;
        cout << "Оберіть дію: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Завершення програми..." << endl;
            break;
        }

        if (choice == 1) {
            string dest, name, date;
            cout << "Введіть пункт призначення: ";
            cin >> dest;
            cout << "Введіть прізвище та ініціали (наприклад, Ivanov_I.I.): ";
            cin >> name;
            cout << "Введіть бажану дату вильоту (YYYY-MM-DD): ";
            cin >> date;

            requests.insert(TicketRequest(dest, name, date));
            cout << "Заявку успішно додано!" << endl;
        }
        else if (choice == 2) {
            int idToDelete;
            cout << "Введіть ID заявки для видалення: ";
            cin >> idToDelete;
            deleteRequestById(requests, idToDelete);
        }
        else if (choice == 3) {
            string dest;
            cout << "Введіть пункт призначення для пошуку: ";
            cin >> dest;
            showRequestsByDestination(requests, dest);
        }
        else if (choice == 4) {
            string dest, startDate, endDate;
            cout << "Введіть пункт призначення: ";
            cin >> dest;
            cout << "Введіть початкову дату (YYYY-MM-DD): ";
            cin >> startDate;
            cout << "Введіть кінцеву дату (YYYY-MM-DD): ";
            cin >> endDate;
            countRequestsInDateRange(requests, dest, startDate, endDate);
        }
        else if (choice == 5) {
            showAllRequests(requests);
        }
        else {
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    }

    return 0;
}