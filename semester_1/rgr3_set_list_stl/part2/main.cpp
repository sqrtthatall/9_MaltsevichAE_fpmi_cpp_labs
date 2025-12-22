#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

struct Authtor {
	std::string surname;
	std::string name;
	std::string dadyname;
};

struct Book {
	int udk;
	std::string title;
	int year;
	std::list<Authtor> authors;
};

class Library {
private:
	std::list<Book> Books;


public:

	Library() = default;
	
	void AddBook(const Book& book) {
		Books.push_back(book);
	}
	bool RemoveBook(const std::string& title) {

	}
	std::list<Book> FindBooksByName(const std::string& title) {

	}
	std::list<Book> FindBokByAuthor(const Authtor& authtor) {

	}
	bool AddBookIntoList(const std::string& title, const Authtor& authtor) {

	}
	bool RemoveAuthBooks(const std::string& title, const Authtor& authtor) {

	}
};





std::list<Book> ParsingFromFile(const std::string& filename) {
	std::ifstream fin(filename);
	if (!fin.is_open()) throw "Could not open the file!\n";
	if (fin.peek() == std::fstream::traits_type::eof) throw "File is empty!\n";
	std::list<Book> books;
	std::string line;
	std::vector<std::string> CurrentBookInfo;
	while (std::getline(fin, line)) {

	}
	
}



int main()
{

}

