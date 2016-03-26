#include <LBD3Q15.h>


int main(int argc , char * argv[] ){
  
  int device = argc > 1 ? atoi(argv[1]) : 0 ;
  af::setDevice(device);
  af::info();
  LatticeBolztmannD3Q15 fluid( 50 , 50 ,50);

}
