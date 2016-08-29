
#include <string>
#include <iostream>
// using declarations states our intent to use these names from the namespace std.
using std::cin;
using std::string;
struct Sales_item1 {
// no need for public label, members are public by default
// operations on Sales_item objects
private:
std::string isbn;
unsigned units_sold;
double revenue;
};
class Sales_item {
public:
// operations on Sales_item objects will go here
private:
std::string isbn;
unsigned units_sold;
double revenue;
};

int main()
{
string s; // ok: string is now a synonym for std::string
cin >> s; // ok: cin is now a synonym for std::cin
std::cout << s; // use full name.
std::cout << s; // ok: explicitly use cout from namepsace std
}