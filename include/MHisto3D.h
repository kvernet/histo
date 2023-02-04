#ifndef MHISTO_3D_H
#define MHISTO_3D_H

class MHisto3D {
	public:
		MHisto3D(const double& xMin, const double& xMax, const long& nx, 
				const double& yMin, const double& yMax, const long& ny, 
				const double& zMin, const double& zMax, const long& nz);
		~MHisto3D();		
		double GetXMin() const { return m_xMin; }
		double GetXMax() const { return m_xMax; }
		double GetYMin() const { return m_yMin; }
		double GetYMax() const { return m_yMax; }
		double GetZMin() const { return m_zMin; }
		double GetZMax() const { return m_zMax; }
		long GetNX() const { return m_nx; }
		long GetNY() const { return m_ny; }
		long GetNZ() const { return m_nz; }
		double GetXWidth() const { return m_xdelta; }
		double GetYWidth() const { return m_ydelta; }
		double GetZWidth() const { return m_zdelta; }
		long GetXBin(const double& x) const;
		long GetYBin(const double& y) const;
		long GetZBin(const double& z) const;		
		void Fill(const double& x, const double& y, const double& z);
		void Fill(const double& x, const double& y, const double& z, const double& weight);
		long GetEntries() const { return m_entries; }		
		double GetXBinCenter(const long& ix);
		double GetYBinCenter(const long& iy);
		double GetZBinCenter(const long& iz);
		double GetBinContent(const long& ix, const long& iy, const long& iz);
		double GetBinContent2(const long& ix, const long& iy, const long& iz);		
		double GetXBinCenter(const double& x) const {
			return GetXBinCenter( GetXBin(x) );
		}
		double GetYBinCenter(const double& y) const {
			return GetYBinCenter( GetYBin(y) );
		}
		double GetZBinCenter(const double& z) const {
			return GetZBinCenter( GetZBin(z) );
		}

		double GetBinContent(const double& x, const double& y, const double& z) {
			return GetBinContent( GetXBin(x), GetYBin(y), GetZBin(z) );
		}
		double GetBinContent2(const double& x, const double& y, const double& z) {
			return GetBinContent2( GetXBin(x), GetYBin(y), GetZBin(z) );
		}
	
	private:
		double m_xMin, m_xMax, m_yMin, m_yMax, m_zMin, m_zMax;
		long m_nx, m_ny, m_nz;
		double m_xdelta, m_ydelta, m_zdelta;
		
		double *m_sum, *m_sum2;
		long m_entries;
};

#endif	//MHISTO_3D_H
