//
//  Point.cpp
//  Queen Issue
//
//  Created by Khachatur Hakobyan on 1/25/20.
//  Copyright © 2020 Zero. All rights reserved.
//

#include "Point.hpp"

Point::Point(int row, int column) {
	this->row = row;
	this->column = column;
}

Point Point::next() throw() {
	if (this->row >= 7 && this->column >= 7) {
		throw "This is last point, and it has not next point!";
	}
	
	int row = (this->row);
	int column = (this->column);
	
	if(column < 7) {
		++column;
	} else {
		++row;
	}

	return Point(row, column);
}

QueenResponse Point::pointsForQueen() {
	Point* queenPonits = new Point [64];
	int currentIndex = 0;
	
	int row = this->row;
	int column = this->column;
	
	for(int i = 0; i <= 7; ++i) {
		queenPonits[currentIndex] = Point(row, i);
		++currentIndex;
	}
	
	for(int i = 0; i <= 7; ++i) {
		if (row != i) {
			queenPonits[currentIndex] = Point(i, column);
			++currentIndex;
		}
	}
	
	while (Point(--row, --column).isValid()) {
		queenPonits[currentIndex] = Point(row, column);
		++currentIndex;
	}
	
	row = this->row;
	column = this->column;
	
	while (Point(--row, ++column).isValid()) {
		queenPonits[currentIndex] = Point(row, column);
		++currentIndex;
	}
	
	
	row = this->row;
	column = this->column;
	
	while (Point(++row, --column).isValid()) {
		queenPonits[currentIndex] = Point(row, column);
		++currentIndex;
	}
	
	row = this->row;
	column = this->column;
	
	while (Point(++row, ++column).isValid()) {
		queenPonits[currentIndex] = Point(row, column);
		++currentIndex;
	}
	
	return QueenResponse(currentIndex, queenPonits);
}

bool Point::isValid() {
	return this->row >= 0 &&
	this->row <= 7 &&
	this->column >= 0 &&
	this->column <= 7;
}

ostream& operator<<(ostream& os, const Point& point) {
    os << "Point("<<point.row << ", " << point.column<<") ";
    return os;
}

ostream& operator<<(ostream& os, const QueenResponse& reponse) {
	for(int i = 0; i < reponse.size; ++i) {
		os<<reponse.array[i]<<" ";
	}

	return os;
}
