#include "MHisto2D.h"
#include "histo_header.h"

MHisto2D::MHisto2D(const double& xMin, const double& xMax, 
		const long& nx, const double& yMin, const double& yMax, const long& ny) : 
			m_xMin(xMin), m_xMax(xMax), m_yMin(yMin), m_yMax(yMax), m_nx(nx), m_ny(ny), 
			m_sum(0), m_sum2(0), m_entries(0) {
	if(nx <= 1 || ny <= 1) {
		std::cout << "Error occurs in MHisto2D::MHisto2D()" << std::endl;
		std::cout << "nx and ny of the histogram should be greater or equal to 2" << std::endl;
		exit(-1);
	}
	// compute entries
	m_entries = (nx - 1) * (ny - 1);
	m_xdelta = (xMax - xMin) / (nx - 1);
	m_ydelta = (yMax - yMin) / (ny - 1);
	// define sum sum2 tables
	m_sum  = new double[m_entries];
	m_sum2 = new double[m_entries];
	for(long i = 0; i < m_entries; i++) {
		m_sum[i] = m_sum2[i] = 0;
	}
}
MHisto2D::~MHisto2D() {
	delete[] m_sum;
	delete[] m_sum2;
}
long MHisto2D::GetXBin(const double& x) const {
	long bin = std::floor((x - m_xMin) / m_xdelta);
	if(bin < 0 || bin >= m_nx - 1) bin = MIN_LONG;	
	return bin;
}
long MHisto2D::GetYBin(const double& y) const {
	long bin = std::floor((y - m_yMin) / m_ydelta);
	if(bin < 0 || bin >= m_ny - 1) bin = MIN_LONG;	
	return bin;
}
void MHisto2D::Fill(const double& x, const double& y) {
	this->Fill(x, y, 1);
}
void MHisto2D::Fill(const double& x, const double& y, const double& weight) {
	const long ix = GetXBin(x);
	const long iy = GetYBin(y);	
	if(ix < 0 || ix >= m_nx - 1 || iy < 0 || iy >= m_ny - 1) return;	
	const long index = iy * (m_nx - 1) + ix;
	m_sum[index]  += weight;
	m_sum2[index] += weight * weight;
}
double MHisto2D::GetXBinCenter(const long& ix) {
	if(ix < 0 || ix >= m_nx - 1) {
		return MAX_DOUBLE;
	}
	return m_xMin + (ix + 0.5) * m_xdelta;
}
double MHisto2D::GetYBinCenter(const long& iy) {
	if(iy < 0 || iy >= m_ny - 1) {
		return MAX_DOUBLE;
	}
	return m_yMin + (iy + 0.5) * m_ydelta;
}
double MHisto2D::GetBinContent(const long& ix, const long& iy) {
	if(ix < 0 || ix >= m_nx - 1 || iy < 0 || iy >= m_ny - 1) {
		return MAX_DOUBLE;
	}
	const long index = iy * (m_nx - 1) + ix;
	return m_sum[index];
}
double MHisto2D::GetBinContent2(const long& ix, const long& iy) {
	if(ix < 0 || ix >= m_nx - 1 || iy < 0 || iy >= m_ny - 1) {
		return MAX_DOUBLE;
	}
	const long index = iy * (m_nx - 1) + ix;
	return m_sum2[index];
}
