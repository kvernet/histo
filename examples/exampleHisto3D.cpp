#include "MHisto3D.h"

#include <iostream>

int main(int /*argc*/, char **/*argv*/) {
	
	const double xmin = -10;
	const double xmax = 10;
	long nx = 5;	
	const double ymin = -10;
	const double ymax = 10;
	long ny = 5;
	const double zmin = -10;
	const double zmax = 10;
	long nz = 5;
	
	MHisto3D mHisto3D(xmin, xmax, nx, ymin, ymax, ny, zmin, zmax, nz);
	for(long i = 0; i < 100; i++) {
		double xi = (xmax - xmin) / (i + 1);
		for(long j = 0; j < 100; j++) {
			double yj = (ymax - ymin) / (j + 1);
			for(long k = 0; k < 100; k++) {
				double zk = (zmax - zmin) / (k + 1);
				mHisto3D.Fill(xi, yj, zk);
			}
		}
	}
	
	nx = mHisto3D.GetNX() - 1;
	ny = mHisto3D.GetNY() - 1;
	nz = mHisto3D.GetNZ() - 1;
	for(long i = 0; i < nx; i++) {
		double xi = mHisto3D.GetXBinCenter(i);
		for(long j = 0; j < ny; j++) {
			double yj = mHisto3D.GetYBinCenter(j);
			for(long k = 0; k < nz; k++) {
				double zk = mHisto3D.GetZBinCenter(k);
				double content = mHisto3D.GetBinContent(i, j, k);
				double content2 = mHisto3D.GetBinContent2(i, j, k);
				
				printf("(%.3f, %.3f, %.3f) %.3f %.3f\n", xi, yj, zk, content, content2);
			}
		}
	}
	
	return 0;
}
