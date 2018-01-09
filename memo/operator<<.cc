#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

template <typename T>
std::ostream& operator << (std::ostream& os, std::vector<T>& v) {
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << (i + 1 == v.size() ? "" : ", ");
	}
	os << "]";
	return os;
}

template <typename T>
std::ostream& operator << (std::ostream& os, std::vector<std::vector<T> >& v) {
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << (i + 1 == v.size() ? "" : ", ");
	}
	os << "]";
	return os;
}

template <typename T, typename U>
std::ostream& operator << (std::ostream& os, std::pair<T, U>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

int main() {
	std::vector<std::vector<int> > a;
	std::vector<int> v{ 1, 2, 3 };
	std::pair<int, double> p{ 10, -2.5 };

	for (int i = 0; i < 3; ++i) {
		a.push_back(v);
	}

	v[1] = 4;

	// std::vector<int> の出力
	cout << *(new std::vector<int>(0)) << endl;

	// std::pair<int, double> の出力
	cout << p << endl;

	// std::pair<std::string, std::pair<double, int> > の出力
	cout << *(new std::pair<std::string, std::pair<double, int> >{ "Hello, world!", { 4.9, 2222 } }) << endl;

	// std::vector<int> の出力
	cout << v << endl;

	// std::vector<std::vector<int> > の出力
	cout << a << endl;

	return 0;
}
