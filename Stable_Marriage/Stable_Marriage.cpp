#include <iostream>
#include <stack>
#include <map>

void fillPreferences(int* pref, unsigned count){
	for(int i=0; i<count; i++){
		pref[i] = i;
	}
	for(int i = count-1; i>0; i--){
		std::swap(pref[i], pref[std::rand() % (i+1)]);
	}
}

void findStableMarriage(int pairs, int** preferencesMen, int** preferencesWomen, int* matchesFinal){

	std::stack<int> freeMen;
	int menPriorityCurrent[pairs];
	for(int i = 0; i < pairs; i++){
		freeMen.push(i);
		menPriorityCurrent[i] = 0;
	}

	int womenPartners[pairs];
	for(int i = 0; i < pairs; i++){
		womenPartners[i] = -1;
	}

	int prefWomenRank[pairs][pairs];
	for(int i=0; i<pairs; i++){
		for(int j=0; j<pairs; j++){
			prefWomenRank[i][preferencesWomen[i][j]] = j;
		}
	}


	std::map<int,int> matches;
	while(!freeMen.empty()){
		int man = freeMen.top();
		freeMen.pop();
		int woman = preferencesMen[man][menPriorityCurrent[man]];
		if(womenPartners[woman] == -1 ){
			matches.insert(std::pair<int,int>(man, woman));
			womenPartners[woman] = man;
		}
		else if(prefWomenRank[woman][man] < prefWomenRank[woman][womenPartners[woman]]){
			matches.insert(std::pair<int,int>(man, woman));
			int freedMan = womenPartners[woman];
			womenPartners[woman] = man;
			matches.erase(freedMan);
			freeMen.push(freedMan);
		}
		else{
			freeMen.push(man);
		}
		menPriorityCurrent[man]++;
	}

	std::map<int,int>::iterator it;
	for(it = matches.begin(); it != matches.end(); it++){
		matchesFinal[it->first] = it->second;
	}
}

int main()
{
	unsigned pairs;
	std::cout << "\nEnter number of pairs.\n";
	std::cin >> pairs;

	if(pairs == 0){
		std::cout << "\nInvalid number of pairs\n";
		return 0;
	}

	int** preferencesMen = new int*[pairs];
	int** preferencesWomen = new int*[pairs];
	for(int i=0; i<pairs; i++){
		preferencesMen[i] = new int[pairs];
		preferencesWomen[i] = new int[pairs]; 
	}
	int matches[pairs];

	for(int i = 0; i < pairs; i++){
		fillPreferences(preferencesMen[i], pairs);
		fillPreferences(preferencesWomen[i], pairs);
	}


	findStableMarriage(pairs, preferencesMen, preferencesWomen, matches);

	for(int i=0; i<pairs; i++){
		std::cout << "\nMan " << i+1 << " matched with Woman " << matches[i] + 1 << "\n";
	}

	for(int i=0; i<pairs; i++){
		delete[] preferencesMen[i];
		delete[] preferencesWomen[i];
	}

	delete[] preferencesMen;
	delete[] preferencesWomen;


	return 0;
}