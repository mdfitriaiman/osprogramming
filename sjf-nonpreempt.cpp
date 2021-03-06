#include<iostream> 
using namespace std; 
int mat[10][6]; 

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void arrangeArrival(int num, int mat[][6]) 
{ 
	for(int i=0; i<num; i++) 
	{ 
		for(int j=0; j<num-i-1; j++) 
		{ 
			if(mat[j][1] > mat[j+1][1]) 
			{ 
				for(int k=0; k<5; k++) 
				{ 
					swap(mat[j][k], mat[j+1][k]); 
				} 
			} 
		} 
	} 
} 

void completionTime(int num, int mat[][6]) 
{ 
	int temp, val; 
	mat[0][3] = mat[0][1] + mat[0][2]; 
	mat[0][5] = mat[0][3] - mat[0][1]; 
	mat[0][4] = mat[0][5] - mat[0][2]; 
	
	for(int i=1; i<num; i++) 
	{ 
		temp = mat[i-1][3]; 
		int low = mat[i][2]; 
		for(int j=i; j<num; j++) 
		{ 
			if(temp >= mat[j][1] && low >= mat[j][2]) 
			{ 
				low = mat[j][2]; 
				val = j; 
			} 
		} 
		mat[val][3] = temp + mat[val][2]; 
		mat[val][5] = mat[val][3] - mat[val][1]; 
		mat[val][4] = mat[val][5] - mat[val][2]; 
		for(int k=0; k<6; k++) 
		{ 
			swap(mat[val][k], mat[i][k]); 
		} 
	} 
} 



int main() 
{ 
	int num, temp; 
	
	int mat[10][6] = {{2201,1,3,},{3401,2,2},{1103,3,1}}; 

	

	
	cout<<"Before Arrange...\n"; 
	cout<<"Process ID\tArrival Time\tBurst Time\n"; 
	for(int i=0; i<3; i++) 
	{ 
		cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\n"; 
	} 
	
	arrangeArrival(num, mat); 
	completionTime(num, mat); 
	cout<<"Final Result...\n"; 
	cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
	int total_wt = 0, total_tat = 0; 
	for(int i=0; i<3; i++) 
	{ 
		cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\n";
		total_wt = total_wt + mat[i][4]; 
		total_tat = total_tat + mat[i][5]; 
	} 
	
	cout << "Average waiting time = "<< (float)total_wt / (float)3<<endl; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)3; 
} 
 



