#include <iostream>
#include <vector>
#include <map>

using namespace std;

class orderData
{
private:
    /* data */
    string m_name;
    int m_price;
public:
    string getName();
    int getPrice();
    orderData(string name, int price);
    ~orderData();
};

orderData::orderData(string name, int price)
{
    m_name = name;
    m_price = price;
}

orderData::~orderData()
{
}

string orderData::getName()
{
    return m_name;
}

int orderData::getPrice()
{
    return m_price;
}

map<string, string> m_userData = {{"U01", "Tom"}, {"U02", "Sam"}, {"U03", "John"}};
map<string, orderData> m_orderData = {{"T01", orderData("A", 499)}, {"T02", orderData("B", 599)}, {"T03", orderData("C", 699)}, {"T04", orderData("B", 799)}};

int main() {
    map<string, vector<string>> result = {{"U01", {"T01", "T02"}}, {"U02", {}}, {"U03", {"T03"}}};
    cout << "result = [" << endl;
    for (auto tp : result) {
        cout << "\t{" << endl;
        cout << "\t\tuser:" << "{ id:" << tp.first << ", name:" << m_userData.find(tp.first)->second << "}," << endl;
        cout << "\t\torder:[" << endl;
        for (auto order : tp.second) {
            // { id: ‘T01’, name: ‘A’, price: 499 },
            cout << "\t\t\t{ id:" << order << ", name:" <<  m_orderData.find(order)->second.getName() << ", price:" <<  m_orderData.find(order)->second.getPrice() << "}," << endl;
        }
        cout << "\t\t],"<< endl;
    }
    cout << "\t}" << endl;
    cout << "]" << endl;
}
