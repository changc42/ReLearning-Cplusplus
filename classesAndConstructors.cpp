#include <iostream>
using namespace std;

class Book {
	public:
		string title;
		string author;
		int pages;

		Book() {

		}
		Book(string t) {
			cout << "Creating object" << endl;
		}
};

int main()
{
	Book book1;
    cout << book1.title;
}
