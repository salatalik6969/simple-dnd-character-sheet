#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Sheet for my current DnD character && i had such hopes
// look mom i'm using goto 

int main(){
	bool terminate {0};
	char const menu[8] {'m', 'p', 'a', 's', 'e', 'l', 'd', 'r'};
	vector<pair<char, string>> dyn {{'a', "Ability"},{'s', "Stat"},{'e', "Equipment"},{'l', "Log"}};
	vector<vector<pair<int, string>>> data;
	vector<pair<int, string>> vec1 {{0, "Acrobatics"},{0, "Animal Handling"},{0, "Arcana"},{6, "+Athletics"}, {2, "Deception"},{0, "History"},{2, "+Insight"},{4, "+Intimidation"},{0, "Investigation"},{0, "Medicine"},{0, "Nature"},{0, "Perception"},{2, "Performance"},{4, "+Persuasion"},{0, "Religion"},{0, "Sleight of Hand"},{0, "Stealth"},{0, "Survival"}};  // Abilities
	vector<pair<int, string>> vec2 {{4, "Level"}, {35, "Health Points"}, {2, "Proficiency Bonus"}, {18, "Strength"}, {10, "Dexterity"}, {14, "Constitution"}, {10, "Intelligence"}, {10, "Wisdom"}, {14, "Charisma"}}; // Stats
	vector<pair<int, string>> vec3 {{16, "Armor Class"}, {1, "Chainmail"}, {1, "Greatsword"}, {1, "Morningstar"}, {1, "Light Crossbow"}, {1, "Shield"}}; // Equipment
	vector<pair<int, string>> vec4 {{8, "Kills"}, {10, "Gold Pieces"}, {1, "Near Death Experience"}}; // Logbook
	data.push_back(vec1);
	data.push_back(vec2);
	data.push_back(vec3);
	data.push_back(vec4);
	char inp;
	start:
	cout << "========================| Kozcan Temiz |========================\nRace: Dragonborn(Blue) - Gender: Male - Class: Paladin(Red Knight) - Level: " << data[1][0].first << "\n==============================================================================\n(A) - Abilities\n(S) - Stats\n(E) - Equipment\n(L) - Logbook\n(D) - Dice\n(Q) - Quit the application\n\nType your selection: ";
	while (!terminate){
		cin >> inp;
		inp = tolower(inp);
		if (inp == 'q')
			terminate = {1};
		auto comp = find(begin(menu), end(menu), inp);
		auto comp1 = distance(menu, comp);
		if (comp1 == 6){
			dstart:
			char dinp;
			cout << "\n(A) - Quick Dice \n(M) - Custom Dice \n(P) - Create new quick dice \n(R) - Return to main menu\n\nType your selection: ";
			cin >> dinp;
			dinp = tolower(dinp);
			if (dinp == 'r')
			goto dstart;
			auto subcomp2 = find(begin(menu), end(menu), dinp);
			auto subcomp3 = distance(menu, subcomp);
			if (subcomp3 < 3){
				if (subcomp3 == 0)
					
				}
			else{ 
				cout << "\nError - Invalid value\n\nType your selection: ";
				goto dstart;
			}
		}
		if ((comp1 > 1)&&(comp1 < 6)){
			int comp2 = comp1 - 2;
			auto ret = dyn[comp2].second;
			ret.erase(0, 1);
			char pp = menu[comp1];
			string pp1 {pp};
			ret.insert(0, pp1);
			substart:
			cout << "\n(A) - Add new " << ret << "\n(M) - Modify the current " << ret << "\n(P) - Print current " << ret << " values" << "\n(R) - Return to main menu\n\nType your selection: ";
			char subinp;
			cin >> subinp;
			subinp = tolower(subinp);
			if (subinp == 'r')
				goto start;
			auto subcomp = find(begin(menu), end(menu), subinp);
			auto subcomp1 = distance(menu, subcomp);
			if (subcomp1 < 3){
			//	cout << subcomp1 << "-" << comp2 << "-" << val; 	// input test because i'm stupid
				size_t val = data[comp2].size();
				if(subcomp1 == 1){
				for (size_t i {0}; i < val; ++i)
				cout << "\n" << data[comp2][i].second << ": " << data[comp2][i].first << "\n";
				goto substart;}
				if(subcomp1 == 2){
					subsubstart1:
					string str;
					unsigned st;
					char con;
					cout << "\nWhat stat you would like to add?: ";
					cin >> str;
					cout << "Please type value of " << str << ": ";
					cin >> st;
					cout << "Please confirm adding " << str << ": " << st << " to " << ret << " (Y/N): ";
					cin >> con;
					con = tolower(con);
					if (con == 'n')
						goto subsubstart1;
					if (con == 'y'){
						vector<pair<int, string>> temp {};
						temp = data[comp2];
						temp.push_back({st, str});
						data[comp2] = temp; 
						cout << "Success!\n New values of " << ret << " are ";
						size_t val = data[comp2].size();
						for (size_t i {0}; i < val; ++i)
						cout << " - " << data[comp2][i].second << ": " << data[comp2][i].first;
						goto substart;
						// todo push_back unto subvector 
						
					};
				};
				if (subcomp1 == 0){
					for (size_t i {0}; i < val; ++i){
					cout << (i+1) << ". " << data[comp2][i].second << ": " << data[comp2][i].first << "\n";}
					subsubstart2:
					cout << "\nPlease select the " << ret << " you wish to modify: ";
					int sel {};
					cin >> sel;
					sel = sel - 1;
					cout << "Please type new " << data[comp2][sel].second << " value: "; 
					int nw {};
					cin >> nw;
					cout << "Modifying " << data[comp2][sel].second << " from " << data[comp2][sel].first << " to " << nw << " - Confirm? (Y/N): ";
					char com;
					cin >> com; 
					com = tolower(com);
					if (com == 'y'){
						data[comp2][sel].first = nw;
						cout << "\nSucsessful!\nNew value of " << data[comp2][sel].second << " is " << data[comp2][sel].first << "\n=============================";
						goto substart;}
					if (com == 'n')
						goto subsubstart2;
					}
				}
				else{
					cout << "\nError - Invalid value\n\nType your selection: ";
					goto substart;}
		}
		else{
		cout << "\nError - Invalid value\n\nType your selection: ";
		goto start;}
	
	}
	return 0;
}
