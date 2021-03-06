#ifndef _NUMBERGRID_H_
#define _NUMBERGRID_H_
#include <iostream>
#include <string>
#include <vector>
#include "PPM.h"
#include "ColorTable.h"


class NumberGrid{
        private:
                int mheight;
                int mwidth;

        public:
                int mMaxValue;
                std::vector<int> image;
                NumberGrid( );
                NumberGrid( const int& height, const int& width );
                int getHeight( ) const;
                int getWidth( ) const;
                int getMaxNumber( ) const;
                virtual void setGridSize( const int& height, const int& width );
                void setMaxNumber( const int& number );
                const std::vector< int >& getNumbers( ) const;
                int index( const int& row, const int& column ) const;
                bool indexValid( const int& row, const int& column ) const;
                bool numberValid( const int& number ) const;
                int getNumber( const int& row, const int& column ) const;
                void setNumber( const int& row, const int& column, const int& number );
                void setPPM( PPM& ppm ) const;
                virtual ~NumberGrid();
                virtual int calculateNumber(const int& row, const int& column) const = 0;
                virtual void calculateAllNumbers();
                void setPPM(PPM& ppm, const ColorTable& colors) const;
};
#endif
