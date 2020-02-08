//
//  main.cpp
//  Queen Issue
//
//  Created by Khachatur Hakobyan on 1/25/20.
//  Copyright © 2020 Zero. All rights reserved.
//

#include <iostream>
#include "Point.hpp"
using namespace std;

int** createMultipleArray();
void setupArray(int** array);
void displayArray(int** array);
void displayArray(Point* array, int size);

void setupValues(int** array, Point point) throw();
QueenResponse checkFreePositionForQueens(int** array);

void moveQueenIfNeeded(Point position, int count, int** array, Point*);

int** copyMultipleArray(int** array);
Point* copyPointsArray(Point* array);


int main(int argc, const char * argv[]) {
	

	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int** array = createMultipleArray();
			Point* solutionPoints = new Point[9];
			
//			cout<<"\n\n\n\n####### START ######\n\n\n\n";
//			cout<<"Point("<<i<<", "<<j<<")"<<endl;
			moveQueenIfNeeded(Point(i, j), 8, array, solutionPoints);
//			cout<<"\n\n\n\n####### END ######\n\n\n\n";
		}
	}
	
	
	
	

	return 0;
}


int** createMultipleArray() {
	int** array = new int* [8];
	
	for (int i = 0; i < 8;  ++i) {
		array[i] = new int [8];
	}
	
	setupArray(array);
	
	return array;
}

void setupArray(int** array) {
	for (int i = 0; i <= 7;  ++i) {
		for (int j = 0; j <=7;  ++j) {
			array[i][j] = 0;
		}
	}
}

void displayArray(int** array) {
	cout<<endl;

	for (int i = 0; i <= 7;  ++i) {
		for (int j = 0; j <=7;  ++j) {
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

void displayArray(Point* array, int size) {
	if (array == nullptr) {
		cout<<"Array is empty"<<endl;
		return;
	}
	
	cout<<endl;
	for (int i = 0; i <size;  ++i) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void setupValues(int** array, Point point) throw() {
	if(array[point.row][point.column] != 0) {
		throw "This point is already busy!!!";
	}
	
	QueenResponse response = point.pointsForQueen();
	
	for(int i = 0; i < response.size; ++i) {
		Point point = response.array[i];
		
		array[point.row][point.column]++;
	}
	
	//displayArray(array);
}

void moveQueenIfNeeded(Point position, int count, int** array, Point* points) {
	points[count] = position;
	
	if (count == 1) {
		cout<<"Successfull!!!"<<endl;
		cout<<"Solutions are: ";
		displayArray(points, 9);
		return;
	}
	
	try {
		setupValues(array, position);
		
		QueenResponse freeResponse = checkFreePositionForQueens(array);
		
		if (freeResponse.size >= count - 1) {
			
			for (int i = 0; i < freeResponse.size; ++i) {
				Point freePoint = freeResponse.array[i];
								
				int** copyArray = copyMultipleArray(array);
				Point* copyPoints = copyPointsArray(points);
				
				moveQueenIfNeeded(freePoint, count - 1, copyArray, copyPoints);
			}
		} else {
			//cout<<"No Free Postions! ";
			//displayArray(points, 9);
		}
		
	} catch (const char* error) {
		cout<<"Error: "<<error<<endl;
	}
}

QueenResponse checkFreePositionForQueens(int** array) {
	Point* queenPoints = new Point [64];
	int currentIndex = 0;
	
	for (int i = 0; i <= 7;  ++i) {
		for (int j = 0; j <=7;  ++j) {
			if (array[i][j] == 0) {
				queenPoints[currentIndex] = Point(i, j);
				++currentIndex;
			}
		}
	}
	
	QueenResponse response = QueenResponse(currentIndex, queenPoints);

	return response;
}

int** copyMultipleArray(int** array) {
	int** copyArray = createMultipleArray();
	
	for (int i = 0; i <= 7;  ++i) {
		for (int j = 0; j <=7;  ++j) {
			copyArray[i][j] = array[i][j];
		}
	}
	
	return copyArray;
}

Point* copyPointsArray(Point* array) {
	Point* copyArray = new Point[9];
	
	for (int i = 0; i < 9;  ++i) {
		copyArray[i] = array[i];
	}
	
	return copyArray;
}
