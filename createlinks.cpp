#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>


using namespace std;


int main(){

	const string LINK = "http://shopalphacomm.com/";
	vector<string> items;
	string input_item;
	int count = 0;
	bool continue_open = true;
	
	ifstream fin;
	ofstream fout;

	//open a list of vendor skus
	fin.open("items.txt");
	while (fin >> input_item){
		//add base url to vedor sku
		string appendlink = LINK + input_item;
		items.push_back(appendlink);
	}
	fin.close();

	//create a backup list
	fout.open("linklist.csv");
	for (int i = 0; i < items.size(); i++){
		fout << LINK << items[i] << "\n";
	}
	fout.close();
	
	//declare where to start on master list - For beginning, enter 0
	cout << "Start From? ";
	cin >> count;
	while (count > items.size() - 1){
		cout << "Invalid. Enter Number less than " << items.size() << ": ";
		cin >> count;
	}
	
	
	//opens up browswer window for each link, using default browser
	//if default browser is open, will open new tabs
	//otherwise, will open new windows
	while ((continue_open) && (count < items.size())){
		string open_file = string("start ").append(items[count]);
		string cont_yn;
		system(open_file.c_str());
		cout << count + 1 << ". " << items[count] << "\n";
		count++;
		//open 10 at a time
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
