#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;
using namespace std::chrono;

class word {//class
	string sentence;
	int number{};
public:
	void setSentence(string newSentence) { sentence = newSentence; }
	string getSentence() { return sentence; }
	void setNumber(int newNumber) { number = newNumber; }
	int getNumber() { return number; }
};

	char randomLetter() {
		int r = rand() % 52;
		char base = (r < 26) ? 'A' : 'a';
		return (char)(base + r % 26);
	}

	vector <char> w(){
		vector<char>d;
		srand(time(NULL));
		for (int i = 0; i <= 5; ++i) {
			char ch = randomLetter();
			d.push_back(ch);
		}
		return d;
	}

/*	char randomLetter() とvector <char> w()は
https://www.techiedelight.com/ja/select-random-letters-in-cpp/
を参考とした*/

vector<int>x() {
	vector<int>y;
	random_device engine;
	uniform_int_distribution<unsigned>dist2(100,999);
	for (int i = 0; i <= 5; ++i) {
		y.push_back(dist2(engine));
	}
	return y;
}

int main() {
	auto t0 = high_resolution_clock::now();

	ofstream outfile("ansewer.txt", ios_base::out);
	string sentence;
	int number=0;

	vector<int>t;
	t = x();
	sort(t.begin(), t.end());//イテレータ

	vector<char>o;
	o = w();
	sort(o.begin(), o.end());//イテレータ

	for (auto k : t) {
		cout << k << "を入力してください" << endl;
		cin >> number;
			}
	
	for (auto b:o) {
		cout << b << "表示された文を入力してください" << endl;
		cin >> sentence;;
	}
	outfile.close();

	vector<word>v;
	ifstream datafile("ansewer.txt");
	while (datafile >> sentence >> number)
	{
		v.emplace_back();
		v[v.size() - 1].setSentence(sentence);
		v[v.size() - 1].setNumber(number);
		cout << v[v.size() - 1].getSentence() << "(" << v[v.size() - 1].getNumber() << ")" << endl;
	}
	datafile.close();
	auto t1 = high_resolution_clock::now();
	cout << "かかった時間は" << duration_cast<milliseconds>(t1 - t0).count() / 1000. << "秒です．" << endl;
		}
