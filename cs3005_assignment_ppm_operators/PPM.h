#ifndef  _PPM_H_
#define _PPM_H_
#include <iostream>
#include <string>
#include <vector>

class PPM{

	private:
		int mheight;
		int mwidth;
		int mMaxColor;
		std::vector<int> image;

	public:
		PPM( );

		PPM(const int& height, const int& width);

		int getHeight( ) const; 

		int getWidth( ) const;

		int getMaxColorValue( ) const;

		int getChannel( const int& row, const int& column, const int& channel ) const; 

		bool indexValid( const int& row, const int& column, const int& channel ) const; 

		int index( const int& row, const int& column, const int& channel ) const; 

		bool valueValid( const int& value ) const;
	
		void setHeight( const int& height ); 

		void setWidth( const int& width ); 

		void setMaxColorValue( const int& max_color_value );

		void setChannel( const int& row, const int& column, const int& channel, const int& value );

		void setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ); 
		
		void grayFromChannel( PPM& dst, const int& src_channel ) const;

		void grayFromRed( PPM& dst ) const;

		void grayFromGreen( PPM& dst ) const;

		void grayFromBlue( PPM& dst ) const;

		double linearColorimetricPixelValue( const int& row, const int& column ) const;

		void grayFromLinearColorimetric( PPM& dst ) const;

		bool operator==( const PPM& rhs ) const;

		bool operator!=( const PPM& rhs ) const;
		
		bool operator<( const PPM& rhs ) const;
		
		bool operator<=( const PPM& rhs ) const;
		
		bool operator>( const PPM& rhs ) const;
		
		bool operator>=( const PPM& rhs ) const;
		
		PPM& operator+=( const PPM& rhs );
	
		PPM& operator-=( const PPM& rhs );
	
		PPM& operator*=( const double& rhs );
	
		PPM& operator/=( const double& rhs );
	
		PPM operator+( const PPM& rhs ) const;
	
		PPM operator-( const PPM& rhs ) const;
	
		PPM operator*( const double& rhs ) const;
	
		PPM operator/( const double& rhs ) const;

};

std::istream& operator>>( std::istream& is, PPM& rhs );

std::ostream& operator<<( std::ostream& os, const PPM& rhs );


#endif

