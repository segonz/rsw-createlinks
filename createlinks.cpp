#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>


using namespace std;


int main(){
	//pull list of item numbers into vector of strings
	const string LINK = "http://shopalphacomm.com/";
	vector<string> items;
	string input_item;
	int count = 0;
	bool continue_open = true;
	
	ifstream fin;
	ofstream fout;

	fin.open("items.txt");
	while (fin >> input_item){
		string appendlink = LINK + input_item;
		items.push_back(appendlink);
	}
	fin.close();

	fout.open("linklist.csv");
	for (int i = 0; i < items.size(); i++){
		fout << LINK << items[i] << "\n";
	}
	fout.close();

	cout << "Start From? ";
	cin >> count;
	while (count > items.size() - 1){
		cout << "Invalid. Enter Number less than " << items.size() << ": ";
		cin >> count;
	}

	while ((continue_open) && (count < items.size())){
		string open_file = string("start ").append(items[count]);
		string cont_yn;
		system(open_file.c_str());
		cout << count + 1 << ". " << items[count] << "\n";
		count++;
		if (count % 10 == 0){
			cout << "\nContinue? ";
			cin >> cont_yn;
			if ((cont_yn != "y") || (cont_yn != "Y"))
				continue_open = false;
		}
		
	}

	fin.close();

	return 0;
}