#ifndef MHISTO_1D_H
#define MHISTO_1D_H

class MHisto1D {
	public:
		MHisto1D(const double& xMin, const double& xMax, const long& nx);
		~MHisto1D();		
		double GetXMin() const { return m_xMin; }
		double GetXMax() const { return m_xMax; }
		long GetNX() const { return m_nx; }
		double GetXWidth() const { return m_xdelta; }
		long GetXBin(const double& x) const;		
		void Fill(const double& x);
		void Fill(const double& x, const double& weight);
		long GetEntries() const { return m_entries; }		
		double GetXBinCenter(const long& ix);
		double GetBinContent(const long& ix);
		double GetBinContent2(const long& ix);		
		double GetXBinCenter(const double& x) const {
			return GetXBinCenter( GetXBin(x) );
		}
		double GetBinContent(const double& x) const {
			return GetBinContent( GetXBin(x) );
		}
		double GetBinContent2(const double& x) const {
			return GetBinContent2( GetXBin(x) );
		}
	
	private:
		double m_xMin, m_xMax, m_xdelta;
		long m_nx;		
		double *m_sum, *m_sum2;
		long m_entries;
};

#endif	//MHISTO_1D_H
