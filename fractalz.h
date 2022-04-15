// This program was guided by the lab exercise found at https://courses.cs.washington.edu/courses/cse142/01sp/misc/fractal_lab.htm
// We specifically used their graphics program so that we could focus on fractal generation

// All code here was written by Will Gushee, Parker Mathena, Sobina Kim, Daniel Peacock
// for the Math 214 Final Project for the University of Michigan, Ann Arbor

#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_POINTS = 65536;

struct Vector {
	double x;
	double y;
};

struct Matrix {
	double a;
	double b;
	double c;
	double d;
};

struct AffineTransformation {
	Matrix mat;
	Vector vec;
};

Vector do_affineTransformation(AffineTransformation* atr, Vector* vec);

Vector matMult(Matrix* mat, Vector* vec);

Vector add(Vector* a, Vector* b);

void printVect(Vector* vec);

void drawFractal(vector<AffineTransformation>& afs, int max_depth);

void PlotVector(Vector* vec);

void recursivePlot(Vector* vec, vector<AffineTransformation>& afs, int num_trans, int depth, int max_depth);

size_t read_input(vector<AffineTransformation>& afs);
