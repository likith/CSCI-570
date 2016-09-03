#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main()
{
	int tasks;
	std::cout << "\nEnter number of tasks\n";
	std::cin >> tasks;

	if(tasks < 1){
		std::cout << "\n Invalid number of tasks. Nothing to do\n";
		return 0;
	}

	int start_times[tasks];
	int finish_times[tasks];

	for(int i=0; i<tasks; i++){
		std::cout << "\n Enter start time for " << i+1 << "th task ";
		std::cin >> start_times[i];
		std::cout << "\n Enter finish times for " << i+1 << "th task ";
		std::cin >> finish_times[i];
	}

	std::map<int, int> reverse_finish;
	for(int i=0; i<tasks; i++){
		reverse_finish.insert(std::pair<int, int>(finish_times[i], i));
	}

	//std::sort(reverse_finish.begin(), reverse_finish.end());

	int max_tasks = 0;
	std::pair<int, int> current_task = *(reverse_finish.begin());
	std::vector<int> comp_tasks;
	comp_tasks.push_back(current_task.second);

	std::map<int, int>::iterator it; 

	if(reverse_finish.size() > 1){
		it = std::next(reverse_finish.begin());
	}

	for(; it != reverse_finish.end(); it++){
		if(start_times[it->second] > current_task.first){
			current_task = *it;
			comp_tasks.push_back(current_task.second);
		}
	}

	std::cout << "\nMaximum number of compatible tasks " << comp_tasks.size() << "\n";

	return 0;
}