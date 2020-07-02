/*
 *  Source.cpp
 *
 *  Created on: Oct 23, 2019
 *  Author: Mohammad Okasha
 */



#include <fstream> //for file I/O
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "rectangle.h"


using namespace std;
using namespace std::chrono;

void groupRectangles(vector<rectangle>rects);

int main()
{
	char inf = 'Y';
	while (inf == 'Y')
	{
		vector<rectangle> rects;						//container for rectangles
		int error_flag = 0;
		int x1, x2, y1, y2;								//coordinates to construct two points
		int buffer;										//buffer from input file to the container						
		int counter = 0;								//to count the number of variables read from the file 
		ifstream infile;								//connection with input file
		int data_set_number;							//data set number to be loaded
		char source;
		string path;
		cout << "Enter P to enter path for input file .. D for data_set file" << endl;
		cin >> source;
		if (source == 'D')								//to choose between the task datasets
		{
			cout << "Enter data_set number" << endl;
			cin >> data_set_number;
			path = "data_set_" + to_string(data_set_number) + ".txt";

		}
		else if (source == 'P')							//to try another test file
		{
			cout << "Enter File Path" << endl;
			cin >> path;
		}
		else
		{
			cout << "wrong source" << endl;
			error_flag = 1;
		}
		auto start = high_resolution_clock::now();		//start counting for time calculation
		infile.open(path); //open file
		if (infile.is_open())
		{
			if (infile.peek() == std::ifstream::traits_type::eof()) //empty file checking
			{
				cout << "This file is empty .. please select another file"<<endl;
				error_flag = 1;
			}
			else
			{
				while (infile >> buffer)					//read 1 value from the file
				{
					if (counter % 4 == 0)
					{
						x1 = buffer;
					}
					else if (counter % 4 == 1)
					{
						y1 = buffer;
					}
					else if (counter % 4 == 2)
					{
						x2 = buffer;
					}
					else if (counter % 4 == 3)
					{
						y2 = buffer;
						if (!(x2 > x1&& y2 > y1))			//check for wrong coordinates arrangement
						{
							error_flag = 1;
							break;
						}
						rectangle temp_rect(x1, y1, x2, y2);//construct rectangle
						rects.push_back(temp_rect);			//add this rectangle to the container
					}
					counter++;
				}
				if (infile.eof() && counter % 4 == 0 && !error_flag)		//check if there are missing data or wrong input format
					infile.close();
				else
				{
					cout << "Error reading the file" << endl;
					error_flag = 1;
				}
			}
		}
		if (!error_flag)
		{
			cout << "Number Of Inputs = " << rects.size() << endl;
			groupRectangles(rects);						//divide rectangles into groups
			auto stop = high_resolution_clock::now();	//calculating time consumed by the algorithm
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time Consumed = " << (float)duration.count() / 1000000.0 << " sec" << endl;
		}
		cout << "Enter Y to re-enter file .. Any key to exit" << endl;
		cin >> inf;
	}
}


void groupRectangles(vector<rectangle>rects)
{
	int group_id = 1;									//for output file names
	vector<bool> taken(rects.size(), false);			//true if a rectangle is already in a group
	for (unsigned int i = 0; i < rects.size(); i++)
	{
		if (!taken[i])									//check if rectangle[i] is not in group
		{
			vector<rectangle> temp_result;
			taken[i] = true;
			temp_result.push_back(rects[i]);			//add this rectangle to the current group
			for (unsigned int j = i + 1; j < rects.size(); j++) //loop over the upcomming rectangles
			{
				if (!taken[j] && rects[j].dontOverlap_Group(temp_result)) //check if rectangle[j] dont overlap with the current group
				{
					temp_result.push_back(rects[j]);			//add rectangle[j] to the current group
					taken[j] = true;
				}
			}
			if (temp_result.size() != 0)						//writing the current group to an output file
			{
				ofstream outfile;
				outfile.open("groups_" + to_string(group_id) + ".txt", ios::out);
				for (unsigned int k = 0; k < temp_result.size(); k++)
				{
					outfile << temp_result[k].getC1_X() << " " << temp_result[k].getC1_Y() << " " << temp_result[k].getC2_X() << " " << temp_result[k].getC2_Y() << endl;
				}
				outfile.close();
				group_id++;
			}
		}
	}
	cout << "Number Of Groups = " << (group_id - 1) << endl;
}

