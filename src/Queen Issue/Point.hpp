//
//  Point.hpp
//  Queen Issue
//
//  Created by Khachatur Hakobyan on 1/25/20.
//  Copyright © 2020 Zero. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class QueenResponse;

class Point {
public:
	int row;
	int column;
	bool isValid();
	Point(int = 0, int = 0);
	Point next() throw();
	QueenResponse pointsForQueen();
	
    friend ostream& operator<<(ostream& os, const Point& dt);
};


struct QueenResponse {
	public:

	int size;
	Point* array;
	

	QueenResponse(int size, Point* array) {
		this->size = size;
		this->array = array;
	}
    friend ostream& operator<<(ostream& os, const QueenResponse& reponse);
};



#endif /* Point_hpp */
