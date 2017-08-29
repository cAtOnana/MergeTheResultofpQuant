#include "pQuant.h"

ifstream & operator>>(ifstream & in, vector<pquant>& list)
{
	pquant temp;
	while (in >> temp.name_ms2) {
		in >> temp.seq;
		in >> temp.modi;
		in >> temp.score_modi;
		in >> temp.intensity;
		in >> temp.locus;
		in >> temp.description;
		in >> temp.number;
		in >> temp.ratio;
		in >> temp.score_inten;
		in >> temp.similarity1;
		in >> temp.similarity2;
		in >> temp.inten_s1;
		in >> temp.inten_s2;
		in >> temp.flag;
		list.push_back(temp);
	}
	return in;
	
}

void qtest(vector<pquant>& veclist, valarray<double>& vallist)
{
	static const double limit = 1 / (2 * vallist.size());
	for (int i = 0; i < vallist.size(); i++) 
	{
		double aver_out = (vallist.sum() - vallist[i]) / (vallist.size() - 1);
		double variance = 0.0;
		for (int j = 0; j < vallist.size(); j++)
		{
			if (j == i)
				continue;
			variance += pow(vallist[j] - aver_out, 2);
		}
		variance = sqrt(variance / vallist.size() - 1);
		double q = (vallist[i] - aver_out) / variance;
		if (q >= limit||q<= -limit)
			veclist[i].output_tag = true;
		else
			veclist[i].output_tag = false;
	}
}

ostream& operator<<(ostream& os, pquant& item)
{
	os << item.name_ms2 << '\t' << item.seq << '\t' << item.modi << '\t' << item.score_modi << '\t' << item.intensity << '\t' << item.locus << '\t'
		<< item.description << '\t' << item.number << '\t' << item.ratio << '\t' << item.score_inten << '\t' << item.similarity1 << '\t' << item.similarity2<< '\t'
		<< item.inten_s1 << '\t' << item.inten_s2 << '\t' << item.flag << item.marker <<'\t'<< item.is_mut;
	return os;
}
