#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = rand() % 2 + 3;
        for (int i = 0; i < SIZE; i++)
            prices[i] = rand() % 89999 / 100.0 + 100.0;
    }
    Chair(int l, double p[3]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3, new double[SIZE]{ 525.25, 434.34, 252.52 });
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++){
        collection[i] = Chair();
        collection[i].print();
    }
    return 0;
} 