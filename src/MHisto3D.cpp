#include "MHisto3D.h"
#include "histo_header.h"

MHisto3D::MHisto3D(const double& xMin, const double& xMax, 
		const long& nx, const double& yMin, const double& yMax, const long& ny, 
		const double& zMin, const double& zMax, const long& nz) : 
			m_xMin(xMin), m_xMax(xMax), m_yMin(yMin), m_yMax(yMax), 
			m_zMin(zMin), m_zMax(zMax), m_nx(nx), m_ny(ny), m_nz(nz), 
			m_sum(0), m_sum2(0), m_entries(0) {
	if(nx <= 1 || ny <= 1 || nz <= 1) {
		std::cout << "Error occurs in MuographyHisto2D::MuographyHisto2D()" << std::endl;
		std::cout << "nx and ny and nz of the histogram should be greater or equal to 2" << std::endl;
		exit(-1);
	}
	// compute entries
	m_entries = (nx - 1) * (ny - 1) * (nz - 1);
	m_xdelta = (xMax - xMin) / (nx - 1);
	m_ydelta = (yMax - yMin) / (ny - 1);
	m_zdelta = (zMax - zMin) / (nz - 1);
	// define sum sum2 tables
	m_sum  = new double[m_entries];
	m_sum2 = new double[m_entries];
}
MHisto3D::~MHisto3D() {
	// free memory
	delete m_sum;
	delete m_sum2;
}
long MHisto3D::GetXBin(const double& x) const {
	long bin = floor((x - m_xMin) / m_xdelta);
	if(bin < 0 || bin >= m_nx - 1) bin = MIN_LONG;	
	return bin;
}
long MHisto3D::GetYBin(const double& y) const {
	long bin = floor((y - m_yMin) / m_ydelta);
	if(bin < 0 || bin >= m_ny - 1) bin = MIN_LONG;	
	return bin;
}
long MHisto3D::GetZBin(const double& z) const {
	long bin = floor((z - m_zMin) / m_zdelta);
	if(bin < 0 || bin >= m_nz - 1) bin = MIN_LONG;	
	return bin;
}
void MHisto3D::Fill(const double& x, const double& y, const double& z) {
	Fill(x, y, z, 1);
}
void MHisto3D::Fill(const double& x, const double& y, const double& z, const double& weight) {
	const long ix = GetXBin(x);
	const long iy = GetYBin(y);
	const long iz = GetZBin(z);	
	if(ix < 0 || ix >= m_nx - 1 || 
			iy < 0 || iy >= m_ny - 1 || 
			iz < 0 || iz >= m_nz - 1) return;	
	const long index = iz * (m_nx - 1) * (m_ny - 1) + iy * (m_nx - 1) + ix;
	m_sum[index]  += weight;
	m_sum2[index] += weight * weight;
}
double MHisto3D::GetXBinCenter(const long& ix) {
	if(ix < 0 || ix >= m_nx - 1) {
		return MAX_DOUBLE;
	}
	return m_xMin + (ix + 0.5) * m_xdelta;
}
double MHisto3D::GetYBinCenter(const long& iy) {
	if(iy < 0 || iy >= m_ny - 1) {
		return MAX_DOUBLE;
	}
	return m_yMin + (iy + 0.5) * m_ydelta;
}
double MHisto3D::GetZBinCenter(const long& iz) {
	if(iz < 0 || iz >= m_nz - 1) {
		return MAX_DOUBLE;
	}
	return m_zMin + (iz + 0.5) * m_zdelta;
}
double MHisto3D::GetBinContent(const long& ix, const long& iy, const long& iz) {
	if(ix < 0 || ix >= m_nx - 1 || 
			iy < 0 || iy >= m_ny - 1 || iz < 0 || iz >= m_nz - 1) {
		return MAX_DOUBLE;
	}
	const long index = iz * (m_nx - 1) * (m_ny - 1) + iy * (m_nx - 1) + ix;
	return m_sum[index];
}
double MHisto3D::GetBinContent2(const long& ix, const long& iy, const long& iz) {
	if(ix < 0 || ix >= m_nx - 1 || 
			iy < 0 || iy >= m_ny - 1 || iz < 0 || iz >= m_nz - 1) {
		return MAX_DOUBLE;
	}
	const long index = iz * (m_nx - 1) * (m_ny - 1) + iy * (m_nx - 1) + ix;
	return m_sum2[index];
}
