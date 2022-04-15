// This program was guided by the lab exercise found at https://courses.cs.washington.edu/courses/cse142/01sp/misc/fractal_lab.htm

// We specifically used their graphics program so that we could focus on fractal generation

// All code here was written by Will Gushee, Parker Mathena, Sobina Kim, Daniel Peacock
// for the Math 214 Final Project for the University of Michigan, Ann Arbor

#include<iostream>
#include <vector>
#include <cmath>
#include <string>
#include "fractalz.h"

using namespace std;

//DONE
Vector do_affineTransformation(AffineTransformation* atr, Vector* vec) {
	Vector vect = matMult(&atr->mat, vec);
	return add(&vect, &atr->vec);
}

//DONE
Vector matMult(Matrix* mat, Vector* vec) {
	Vector result;
	result.x = ((mat->a * vec->x) + (mat->b * vec->y));
	result.y = ((mat->c * vec->x) + (mat->d * vec->y));
	return result;
}

//DONE
Vector add(Vector* a, Vector* b) {
	Vector newVect;
	newVect.x = a->x + b->x;
	newVect.y = a->y + b->y;
	return newVect;
}

//DONE
void printVect(Vector* vec) {
	cout << vec->x << ", " << vec->y << "\n";
}

//DONE
void drawFractal(vector<AffineTransformation>& afs, int max_depth) {
	Vector start_pt;
	start_pt.x = 0;
	start_pt.y = 0;
	recursivePlot(&start_pt, afs, afs.size(), 0, max_depth);
}

//DONE
void PlotVector(Vector* vec) {
	printVect(vec);
}

//DONE
void recursivePlot(Vector* vec, vector<AffineTransformation>& afs, int num_trans, int depth, int max_depth) {
	if (depth == max_depth) {
		PlotVector(vec);
		return;
	}
	for (int i = 0; i < num_trans; i++) {
		Vector new_vec = do_affineTransformation(&afs[i], vec);
		recursivePlot(&new_vec, afs, num_trans, depth + 1, max_depth);
	}
}

//DONE
size_t read_input(vector<AffineTransformation>& afs) {
	string comment;
	getline(cin, comment);
	size_t num_transformations;
	cin >> num_transformations;
	afs.resize(num_transformations);
	afs.resize(num_transformations);

	for (size_t i = 0; i < num_transformations; ++i) {
		cin >> afs[i].mat.a >> afs[i].mat.b >> afs[i].mat.c >> afs[i].mat.d;
		cin >> afs[i].vec.x >> afs[i].vec.y;
	}
	return num_transformations;
}

int main() {
	//* Init AffineTransformation vec, pass this to read_input
	vector<AffineTransformation> my_affine_vec;
	size_t num_transformations = read_input(my_affine_vec);
	int max_depth = (int)(log(MAX_POINTS) / log((int)(num_transformations)));
	drawFractal(my_affine_vec, max_depth);
}