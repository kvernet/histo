#include "MHisto2D.h"

#include <iostream>

int main(int /*argc*/, char **/*argv*/) {
	
	const double xmin = -10;
	const double xmax = 10;
	long nx = 5;	
	const double ymin = -10;
	const double ymax = 10;
	long ny = 5;
	
	MHisto2D mHisto2D(xmin, xmax, nx, ymin, ymax, ny);
	for(long i = 0; i < 1000; i++) {
		double xi = (xmax - xmin) / (i + 1);
		for(long j = 0; j < 1000; j++) {
			double yj = (ymax - ymin) / (j + 1);
			double weight = 1;
			mHisto2D.Fill(xi, yj, weight);
		}
	}
	
	nx = mHisto2D.GetNX() - 1;
	ny = mHisto2D.GetNY() - 1;
	for(long i = 0; i < nx; i++) {
		double xi = mHisto2D.GetXBinCenter(i);
		for(long j = 0; j < ny; j++) {
			double yj = mHisto2D.GetYBinCenter(j);
			double content = mHisto2D.GetBinContent(i, j);
			double content2 = mHisto2D.GetBinContent2(i, j);
			
			printf("(%.3f, %.3f) %.3f %.3f\n", xi, yj, content, content2);
		}
	}
	
	return 0;
}
