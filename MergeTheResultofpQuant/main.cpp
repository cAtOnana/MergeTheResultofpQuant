#include"pQuant.h"
#include"pFind_PairResearch.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
string pquantname = "";
string reflectname = "";
string outname = "";
int main()
{
	string logname = pquantname;
	logname = logname.erase(logname.find('.')) + ".log";
	ofstream log(logname);
	if (!log.is_open)
	{
		cout << "�޷�����־�ļ���������ֹ" << endl;
		char z;
		cin >> z;
		exit(EXIT_FAILURE);
	}
	ifstream inpq(pquantname);
	if (!inpq.is_open())
	{
		log << "�޷��򿪶����ļ��������˳�\n";
		exit(EXIT_FAILURE);
	}
	ifstream inre(reflectname);
	if (!inre.is_open())
	{
		log << "�޷����Ķ�ӳ���ļ��������˳�\n";
		exit(EXIT_FAILURE);
	}
	vector<pquant> pqlist;
	inpq >> pqlist;
	unordered_map<string, int> pqindexcontainer;
	for (int i=0;i<pqlist.size();i++)
	{
		pqindexcontainer[pqlist[i].name_ms2] = i;
	}
	vector<spectra> relist;
	inre >> relist;
	int markcount =mark(relist);
	bool * cout_modi = new bool[markcount];
	bool* cout_no = new bool[markcount];
	for (auto n : relist)
	{
		if (pqindexcontainer.find(n.file_name) != pqindexcontainer.end())
		{
			int i = pqindexcontainer[n.file_name];
			pqlist[i].marker = n.marker;
			pqlist[i].is_mut = n.is_mut;
			if (n.is_mut == true)
				cout_modi[n.marker] = true;
			else
				cout_no[n.marker] = true;
		}
	}
	//���
	ofstream out(outname);
	for (auto n : pqlist)
	{
		if (cout_modi[n.marker] && cout_no[n.marker])
			out << n << endl;
	}
	cout << "Done!\n�밴������˳�...\n";
	char z;
	cin >> z;
	return 0;
}