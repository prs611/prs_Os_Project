#include <bits/stdc++.h> 
#include<math.h>
using namespace std; 

struct process { 
	int processno; 
	int ArrivalTime; 
	int BurstTime; 

	// for backup purpose to print in last 
	int BTbackup; 
	int WaitingTime; 
	int Turn_Around_Time; 
	int CompletionTime; 
}; 

struct process p[3]; 
int totaltime = 0; 
int prefinaltotal = 0; 
bool compare(process p1, process p2) 
{ 
	return p1.ArrivalTime < p2.ArrivalTime; 
} 

int Finding_The_Largest(int at) 
{ 
	int max = 0, i; 
	for (i = 0; i < 3; i++) { 
		if (p[i].ArrivalTime <= at) { 
			if (p[i].BurstTime > p[max].BurstTime) 
				max = i; 
		} 
	} 
	return max; 
} 
int Finding_Completion_Time() 
{ 

	int index; 
	int flag = 0; 
	int i = p[0].ArrivalTime; 
	while (1) { 
		if (i <= 3) { 
			index = Finding_The_Largest(i); 
		} 

		else
			index = Finding_The_Largest(3); 
		cout << "Process executing at time " << totaltime 
			<< " is: P" << index + 1 << "\t"; 

		p[index].BurstTime -= 1; 
		totaltime += 1; 
		i++; 

		if (p[index].BurstTime == 0) { 
			p[index].CompletionTime = totaltime; 
			cout << " Process P" << p[index].processno 
				<< " is completed at " << totaltime; 
		} 
		cout << endl; 

	
		if (totaltime == prefinaltotal) 
			break; 
	} 
} 

int main() 
{ 
	int i; 										
	for (i = 0; i < 3; i++) { 
		cout<< " Please enter the Process Id \ Number  for process  " << i+1  ;
		int a ;
		cin >> a ;
		p[i].processno = a; 
	} 								
	for (i = 0; i < 3; i++) 
	{ 
		p[i].ArrivalTime = 0; 
	} 
	for (i = 0; i < 3; i++) { 
		p[i].BurstTime = pow(2,i+1); 
		p[i].BTbackup = p[i].BurstTime; 
		prefinaltotal += p[i].BurstTime; 
	} 	
	cout << "PNo\tAT\tBT\n"; 

	for (i = 0; i < 3; i++) { 
		cout << p[i].processno << "\t"; 
		cout << p[i].ArrivalTime << "\t"; 
		cout << p[i].BurstTime << "\t"; 
		cout << endl; 
	} 
	cout << endl; 
	sort(p, p + 3, compare); 
	totaltime += p[0].ArrivalTime;  
	prefinaltotal += p[0].ArrivalTime; 
	Finding_Completion_Time(); 
	int totalWT = 0; 
	int totalTAT = 0; 
	for (i = 0; i < 3; i++) { 
		p[i].Turn_Around_Time = p[i].CompletionTime - p[i].ArrivalTime; 
		p[i].WaitingTime = p[i].Turn_Around_Time - p[i].BTbackup; 
		totalWT += p[i].WaitingTime; 
		totalTAT += p[i].Turn_Around_Time; 
	} 

	cout << "After execution of all processes ... \n"; 
	cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n"; 

	for (i = 0; i < 3; i++) { 
		cout << p[i].processno << "\t"; 
		cout << p[i].ArrivalTime << "\t"; 
		cout << p[i].BTbackup << "\t"; 
		cout << p[i].CompletionTime << "\t"; 
		cout << p[i].Turn_Around_Time << "\t"; 
		cout << p[i].WaitingTime << "\t"; 
		cout << endl; 
	} 

	cout << endl; 
	cout << "Total Turn_Around_Time = " << totalTAT << endl; 
	cout << "Average Turn_Around_Time = " << totalTAT / 4.0 << endl; 
	cout << "Total WaitingTime = " << totalWT << endl; 
	cout << "Average WaitingTime = " << totalWT / 4.0 << endl; 
	return 0; 
}

