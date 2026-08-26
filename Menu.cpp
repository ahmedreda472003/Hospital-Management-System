#include "Menu.h"


     void Menu::printAccountMenu() {

        cout << "\n═════════════════════════════════════════\n";
        Console::white();
        cout << "             MY ACCOUNT";
        Console::cyan();
        cout << "\n═════════════════════════════════════════\n\n";

        Console::white();
        cout << "Account\n";
        Console::cyan();
        cout << "─────────────────────────\n";


        cout << "▸ [1] View Profile\n\n";
        cout << "▸ [2] Update My Information\n\n";

        Console::white();
        cout << "Bank Account\n";
        Console::cyan();
        cout << "─────────────────────────\n";

        cout << "▸ [3] View Balance\n\n";
        cout << "▸ [4] Deposit Balance\n\n";

        Console::white();
        cout << "Return\n";
        Console::cyan();
        cout << "─────────────────────────\n";
        Console::red();
        cout << "↩ [0] Back\n\n";

        Console::lightGray();
        cout << "➜ Select an option: ";
    }

