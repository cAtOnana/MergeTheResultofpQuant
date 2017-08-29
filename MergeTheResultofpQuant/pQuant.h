#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<valarray>

using namespace std;
struct pquant {
	string name_ms2;
	string seq;
	string modi;
	double score_modi;
	double intensity;
	string locus;
	string description;
	int number;
	double ratio;
	double score_inten;
	double similarity1;
	double similarity2;
	double inten_s1;
	double inten_s2;
	int flag;
	bool output_tag;
	int marker = 0;
	bool is_mut = false;
};

ifstream& operator>>(ifstream& in, vector<pquant>& list);
ostream& operator<<(ostream& os, pquant& item);
void qtest(vector<pquant>& veclist, valarray<double>& vallist);
