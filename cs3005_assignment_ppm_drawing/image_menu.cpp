#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "image_menu.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt ){
  std::string color;
  os << prompt;
  is >> color;
  return color;
}

int getInteger( std::istream& is, std::ostream& os, const std::string& prompt ){
  int integer;
  os << prompt;
  is >> integer;
  return integer;
}
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt ){
  double number;
  os << prompt;
  is >> number;
  return number;
}

void writeUserImage(std::istream& is, std::ostream& os, const PPM& p){
	std::string file;
	file = getString(is, os, "Output filename? ");
	std::ofstream targetF;
	targetF.open(file, std::ios::binary);
	targetF << p;
	targetF.close();
	return;	

}

void showMenu(std::ostream& os){
	os << "\nActions available:\n\nwrite) Write output image to file.\ncopy) Copy input image 1 to output image.\n# Comment to end of line\nsize) Set the size of input image 1\nmax) Set the max color value of input image 1\nchannel) Set a channel value in input image 1\npixel) Set a pixel's 3 values in input image 1\nclear) Set all pixels to 0,0,0 in input image 1\ndiamond) Draw a diamond shape in input image 1\ncircle) Draw a circle shape in input image 1\nbox) Draw a box shape in input image 1\nquit) Quit\n\n";
	return;
}

std::string getChoice(std::istream& is, std::ostream& os){
	std::string choice;
	choice = getString(is,os, "Choice? ");
	return choice;
}

void commentLine(std::istream& is){
	std::string comment;
	getline(is, comment);
	return;
}

void setSize( std::istream& is, std::ostream& os, PPM& src ){
	int height=0;
	int width=0;
	height = getInteger(is,os, "Height? ");
	width = getInteger(is,os, "Width? ");
	src.setHeight(height);
	src.setWidth(width);
	return;
}

void setMaxColorValue( std::istream& is, std::ostream& os, PPM& src ){
	int max=0;
	max = getInteger(is,os,"Max color value? ");
	src.setMaxColorValue(max);
	return;
}

void setChannel( std::istream& is, std::ostream& os, PPM& src ){
	int row=0 ,column=0 ,channel=0 ,value=0;
	row = getInteger(is,os, "Row? ");
	column = getInteger(is,os, "Column? ");
	channel = getInteger(is,os, "Channel? ");
	value = getInteger(is,os, "Value? ");
	src.setChannel(row,column,channel,value);
	return;
}

void setPixel( std::istream& is, std::ostream& os, PPM& src ){
	int row=0 ,column=0 ,red=0 ,green=0 ,blue=0;
        row = getInteger(is,os, "Row? ");
        column = getInteger(is,os, "Column? ");
        red = getInteger(is,os, "Red? ");
        green = getInteger(is,os, "Green? ");
        blue = getInteger(is,os, "Blue? ");
	src.setPixel(row,column,red,green,blue);
        return;

}

void clearAll(PPM& src){
	int height = src.getHeight();
        int width = src.getWidth();
        int i = 0;
        int j = 0;
        int k = 0;
        for (; i < height; ++i){//goes through all rows
                for(j = 0; j < width; ++j){// goes through all columns
                        for (k = 0; k < 3; ++k){// goes through the 3 channels 0,1,2
                                src.setPixel(i,j,0,0,0);               
                        }
                }
        }

}

void drawDiamond(std::istream& is, std::ostream& os, PPM& src){
	int crow=0 ,ccolumn=0 ,size=0 ,red=0 ,green=0 ,blue=0;
        crow = getInteger(is,os, "Center Row? ");
        ccolumn = getInteger(is,os, "Center Column? ");
        size = getInteger(is,os, "Size? ");
	red = getInteger(is,os, "Red? ");
        green = getInteger(is,os, "Green? ");
        blue = getInteger(is,os, "Blue? ");
	int height = src.getHeight();
	int width = src.getWidth();
	int i = 0;
        int j = 0;
	for (; i <= height; ++i){//goes through all rows
                for(j = 0; j <= width; ++j){// goes through all columns
                	if ((std::abs((i-crow)) + std::abs(j-ccolumn)) <= size){
				src.setPixel(i,j,red,green,blue);
						
                        }
                }
        }
}

void drawCircle(std::istream& is, std::ostream& os, PPM& src){
        int crow=0 ,ccolumn=0 ,radius=0 ,red=0 ,green=0 ,blue=0;
        crow = getInteger(is,os, "Center Row? ");
        ccolumn = getInteger(is,os, "Center Column? ");
        radius = getInteger(is,os, "Radius? ");
        red = getInteger(is,os, "Red? ");
        green = getInteger(is,os, "Green? ");
        blue = getInteger(is,os, "Blue? ");
        int height = src.getHeight();
        int width = src.getWidth();
        int i = 0;
        int j = 0;
        for (; i < height; ++i){//goes through all rows
                for(j = 0; j < width; ++j){// goes through all columns
                	if (std::sqrt((i-crow)*(i-crow)+(j-ccolumn)*(j-ccolumn)) <= radius){
                        	src.setPixel(i,j,red,green,blue);
                                        
                                }
                        }
                }
        }


void drawBox(std::istream& is, std::ostream& os, PPM& src){
        int trow=0 ,brow=0 ,lcolumn=0 ,rcolumn=0 ,red=0 ,green=0 ,blue=0;
        trow = getInteger(is,os, "Top Row? ");
        lcolumn = getInteger(is,os, "Left Column? ");
        brow = getInteger(is,os, "Bottom Row? ");
	rcolumn = getInteger(is,os, "Right Column? ");
        red = getInteger(is,os, "Red? ");
        green = getInteger(is,os, "Green? ");
        blue = getInteger(is,os, "Blue? ");
        int i = 0;
        int j = 0;
	for(i=trow; i <= brow; ++i){
		for(j=lcolumn; j <= rcolumn; ++j){
			src.setPixel(i,j,red,green,blue);
		}
	}
}

void takeAction( std::istream& is, std::ostream& os, const std::string& choice, PPM& input_image1, PPM& input_image2, PPM& output_image){
	(void) input_image2;
	
	if (choice == "write"){
		writeUserImage(is,os,output_image);
		return;
	}
	else if (choice == "copy"){
		output_image = input_image1;
		return;
	}
 	else if(choice == "size"){
		setSize(is,os,input_image1);
		return;
	}
	else if(choice == "max"){
		setMaxColorValue(is,os,input_image1);
		return;
	}
	else if(choice == "channel"){
		setChannel(is,os,input_image1);
		return;
	}
	else if(choice =="pixel"){
		setPixel(is,os,input_image1);
		return;
	}
	else if(choice == "clear"){
		clearAll(input_image1);
		return;
	}
	else if(choice == "diamond"){
		drawDiamond(is,os,input_image1);
		return;
	}
	else if(choice =="circle"){
		drawCircle(is,os,input_image1);
		return;
	}
	else if(choice == "box"){
		drawBox(is,os,input_image1);
		return;
	}
	else if(choice == "quit"){
		return;
	}
	else if (choice.compare(0,1,"#") == 0){
                	commentLine(is);
                	return;
		}
	else{
		os << "Unknown action '" << choice << "'." << std::endl;
		return;
	     }

}

int imageMenu(std::istream& is, std::ostream& os){
	PPM input_image1;
	PPM input_image2;
	PPM output_image;
	int run = 0;
	std::string choice;
	while (run == 0){
		showMenu(os);
		choice = getChoice(is,os);
		takeAction( is, os, choice, input_image1, input_image2,output_image);
		if (choice == "quit"){
			run = 1;
		}

	}
	return 0;
}

int assignment2(std::istream& is, std::ostream& os){
  	int height;
  	int width;
  	height = getInteger(is, os, "Image height? ");
  	width = getInteger(is, os, "Image width? ");
 	PPM image(height, width);
	image.setMaxColorValue((height+width)/3);
	int m = image.getMaxColorValue();
	int i = 0;
	int j = 0;
	int k = 0;
	int red;
	int green;
	int blue;
	for (; i < height; ++i){//goes through all rows
    		for(j = 0; j < width; ++j){// goes through all columns
      			for (k = 0; k < 3; ++k){// goes through the 3 channels 0,1,2
        			if (i < height/2){
          				red = 0;
        			}else{
          				red = m;
			        }
			        if (j < width/2){
			                blue = 0;
        			}else{
          				blue = m;
        			}
        			green = (i + j)%(m+1);
        			image.setPixel(i,j,red,green,blue);			
                        }
                }
        }
	writeUserImage(is,os,image);
 return 0; 
}

/*
int assignment1( std::istream& is, std::ostream& os ){
  std::string color;
  color = getString(is, os, "What's your favorite color?");
  int integer;
  integer = getInteger(is, os,  "What's your favorite integer?");
  double number;
  number = getDouble(is, os, "What's your favorite number?" );
  int i = 1;
  for(; i < integer; i++ ){
    os << i << ' ' << color << ' ' << number << std::endl;
    }
  return integer;
}
*/
