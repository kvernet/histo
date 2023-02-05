#include "MHisto1D.h"

#include <iostream>

int main(int /*argc*/, char **/*argv*/) {
	
	const double min = -10;
	const double max = 10;
	const long bins = 20;
	
	MHisto1D *mHisto1D = new MHisto1D(min, max, bins);
	for(long i = 0; i < 1000; i++) {
		double xi = (max - min) / (i + 1);
		mHisto1D->Fill(xi);
	}
	
	const long nx = mHisto1D->GetNX() - 1;
	for(long ix = 0; ix < nx; ix++) {
		double xi = mHisto1D->GetXBinCenter(ix);
		double content = mHisto1D->GetBinContent(ix);
		double content2 = mHisto1D->GetBinContent2(ix);
		
		printf("%.3f %.3f %.3f\n", xi, content, content2);
	}
	
	delete mHisto1D;
	
	return 0;
}
