#include "MHisto1D.h"
#include "histo_header.h"

MHisto1D::MHisto1D(const double& xMin, const double& xMax, const long& nx) : 
			m_xMin(xMin), m_xMax(xMax), m_nx(nx), m_sum(0), m_sum2(0), m_entries(0) {
	if(nx <= 1) {
		std::cout << "Error occurs in MHisto1D::MHisto1D()" << std::endl;
		std::cout << "nx of the histogram should be greater or equal to 2" << std::endl;
		exit(-1);
	}
	// compute entries
	m_entries = nx - 1;
	m_xdelta = (xMax - xMin) / (nx - 1);
	// define sum & sum2 tables
	m_sum  = new double[m_entries];
	m_sum2 = new double[m_entries];
	for(long i = 0; i < m_entries; i++) {
		m_sum[i] = m_sum2[i] = 0;
	}
}
MHisto1D::~MHisto1D() {
	delete[] m_sum;
	delete[] m_sum2;
}
long MHisto1D::GetXBin(const double& x) const {
	long bin = std::floor((x - m_xMin) / m_xdelta);
	if(bin < 0 || bin >= m_nx - 1) bin = MIN_LONG;	
	return bin;
}
void MHisto1D::Fill(const double& x) {
	this->Fill(x, 1);
}
void MHisto1D::Fill(const double& x, const double& weight) {
	const long ix = GetXBin(x);	
	if(ix < 0 || ix >= m_nx - 1) return;	
	m_sum[ix]  += weight;
	m_sum2[ix] += weight * weight;
}
double MHisto1D::GetXBinCenter(const long& ix) {
	if(ix < 0 || ix >= m_nx - 1) {
		return MAX_DOUBLE;
	}
	return m_xMin + (ix + 0.5) * m_xdelta;
}
double MHisto1D::GetBinContent(const long& ix) {
	if(ix < 0 || ix >= m_nx - 1) {
		return MAX_DOUBLE;
	}
	return m_sum[ix];
}
double MHisto1D::GetBinContent2(const long& ix) {
	if(ix < 0 || ix >= m_nx - 1) {
		return MAX_DOUBLE;
	}
	return m_sum2[ix];
}
