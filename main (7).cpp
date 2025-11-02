#include <iostream>
#include <string>
using namespace std;

class Kahraman {
public:
    string ad;
    int can;
    int hasar;

    Kahraman() {
        hasar = 100;
        can = 1000;
    }

    void ozelGuc(Kahraman &rakip) {
        int ozelHasar = hasar * 2;
        rakip.can -= ozelHasar;
        cout << ad << " özel gücünü kullandı!" << rakip.ad 
             << " " << ozelHasar << " hasar aldı!" << endl;
    }
};

int main() {
    Kahraman spiderman;
    spiderman.ad = "spiderman";

    Kahraman batman;
    batman.ad = "batman";

    cout << "Süper kahramanlar kapışıyor!" << endl;
    bool savasbittimi = true;

    while (savasbittimi) {
        char karaktersecimi;
        cout << "\nHangi süperkahraman saldırsın? (s/b) veya özel güç (d/k): ";
        cin >> karaktersecimi;

        if (karaktersecimi == 's') {
            batman.can -= spiderman.hasar;
            cout << "Spiderman saldırdı!️🕷️" << endl;
        }
        else if (karaktersecimi == 'b') {
            spiderman.can -= batman.hasar;
            cout << "Batman saldırdı!🦇" << endl;
        }
        else if (karaktersecimi == 'd') {
            spiderman.ozelGuc(batman);
        }
        else if (karaktersecimi == 'k') {
            batman.ozelGuc(spiderman);
        }
        else {
            cout << "⚠️ Hatalı seçim!" << endl;
        }

        cout << "Spiderman kalan can: " << spiderman.can 
             << " | Batman kalan can: " << batman.can << endl;

        if (spiderman.can <= 0 || batman.can <= 0) {
            savasbittimi = false;
            if (spiderman.can <= 0)
                cout << "\nKazanan: Batman!🦇" << endl;
            else
                cout << "\nKazanan: Spiderman!️🕷️" << endl;
        }
    }

    return 0;

}