#include <iostream>
#include <vector>

class GreyScale{
  int width;
  int height;
  public:
    std::vector<float> pixels;

    GreyScale(int height_=0, int width_=0): width(width_), height(height_){
      pixels.resize(width*height); 
    }
    
    void resize(int height_, int width_){
      width = width_;
      height = height_;
    }

    int getWidth(){
      return width;
    }

    int getHeight(){
      return height;
    }

    float operator()(int x, int y){
      if(x>=height || y>=width){
        std::cout<<"Error! Trying to access a wrong index!"<<std::endl;
        exit(1);
      }

      return pixels[(width*x) + y];
    }

    void operator =(GreyScale &other){
      resize(other.height, other.width);
      pixels = other.pixels;
    }

    void operator =(float a){
      for(int i=0; i<width*height; i++){
        pixels[i] = a;
      } 
    }

    void operator +=(GreyScale &other){
      if(height != other.height || width != other.width){
        std::cout<<"Error! Dimensions don't match for addtion!"<<std::endl;
        exit(1);
      }

      for(int i=0; i<width*height; i++){
        pixels[i]+=other.pixels[i];
      }
    }

    void operator -=(GreyScale &other){
      if(height != other.height || width != other.width){
        std::cout<<"Error! Dimensions don't match for subtraction!"<<std::endl;
        exit(1);
      }

      for(int i=0; i<width*height; i++){
        pixels[i]-=other.pixels[i];
      }
    }


    void operator+=(float a){
      for(int i=0; i<width*height; i++){
        pixels[i]+=a;
      }
    }

    void operator-=(float a){
      for(int i=0; i<width*height; i++){
        pixels[i]-=a;
      }
    }

    void operator *=(float a){
      for(int i=0; i<width*height; i++){
        pixels[i]*=a;
      } 
    }

    void linTrans(float a, float b){
      *this*=a;
      *this+=b;
    }

    void invert(){
      linTrans(-1, 1);
    }

    void clamp(){
      for(int i=0; i<width*height; i++){
        if(pixels[i]>1){
          pixels[i] = 1;
        }
        else if(pixels[i]<0){
          pixels[i] = 0;
        }
      }
    }
};
