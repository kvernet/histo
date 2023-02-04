#ifndef MHISTO_2D_H
#define MHISTO_2D_H

class MHisto2D {
	public:
		MHisto2D(const double& xMin, const double& xMax, const long& nx, 
				const double& yMin, const double& yMax, const long& ny);
		~MHisto2D();		
		double GetXMin() const { return m_xMin; }
		double GetXMax() const { return m_xMax; }
		double GetYMin() const { return m_yMin; }
		double GetYMax() const { return m_yMax; }
		long GetNX() const { return m_nx; }
		long GetNY() const { return m_ny; }
		double GetXWidth() const { return m_xdelta; }
		double GetYWidth() const { return m_ydelta; }
		long GetXBin(const double& x) const;
		long GetYBin(const double& y) const;		
		void Fill(const double& x, const double& y);
		void Fill(const double& x, const double& y, const double& weight);
		long GetEntries() const { return m_entries; }		
		double GetXBinCenter(const long& ix);
		double GetYBinCenter(const long& iy);
		double GetBinContent(const long& ix, const long& iy);
		double GetBinContent2(const long& ix, const long& iy);		
		double GetXBinCenter(const double& x) const {
			return GetXBinCenter( GetXBin(x) );
		}
		double GetYBinCenter(const double& y) const {
			return GetYBinCenter( GetYBin(y) );
		}
		double GetBinContent(const double& x, const double& y) const {
			return GetBinContent( GetXBin(x), GetYBin(y) );
		}
		double GetBinContent2(const double& x, const double& y) const {
			return GetBinContent2( GetXBin(x), GetYBin(y) );
		}
	
	private:
		double m_xMin, m_xMax, m_yMin, m_yMax;
		long m_nx, m_ny;
		double m_xdelta, m_ydelta;
		
		double *m_sum, *m_sum2;
		long m_entries;
};

#endif	//MHISTO_2D_H
