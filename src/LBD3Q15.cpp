
#include <arrayfire.h>
#include <LBD3Q15.h>
#include <vector>

// Modelo 3d para lattice bolztman utlizando el metodo entrpico 
using namespace af;
LatticeBolztmannD3Q15::LatticeBolztmannD3Q15(int lx,int ly, int lz){
  //constructor
  this->q = 15;
  this->Lx=lx; // tamaño del lattice
  this->Ly=ly;
  this->Lz=lz;
  fs = std::vector<array>(q);
  
  for( int i = 0 ; i < q ; i++){
    this->fs[i] = af::constant(0,Lx,Ly,Lz , f32);
  }
  w = af::constant( 0 , q , f32);

  this->ConditionsU = af::constant(1, Lx,Ly,Lz,f32);

  w(0) = 16; w(1)=w(2)=w(3)=w(4)=w(5)=w(6) = 8;
  w(7)=w(8)=w(9)=w(10)=w(11)=w(12)=w(13)=w(14)=1;
  w = 1/72.0*w;
  W[0] = 16.0/72;
  W[1] = W[2] = W[3] =   W[4] = W[5] = W[6] = 8.0/72;
  W[7] = W[8] = W[9] =   W[10] = W[11] = W[12] = W[13] = W[14] = 1.0/72; 
  
  V[0][0] = 0; V[0][1] = 1; V[0][2] = 0; V[0][3] = 0 ; V[0][4] = -1;
  V[0][5] = 0; V[0][6] = 0; V[0][7] = 1; V[0][8] = -1 ; V[0][9] = 1;
  V[0][10] = 1; V[0][11] = -1; V[0][12] = 1; V[0][13] = -1 ; V[0][14] = -1;
  
  V[1][0] = 0; V[1][1] = 0; V[1][2] = 1; V[1][3] = 0 ; V[1][4] = 0;
  V[1][5] = -1; V[1][6] = 0; V[1][7] = 1; V[1][8] = 1 ; V[1][9] = -1;
  V[1][10] = 1; V[1][11] = -1; V[1][12] = -1; V[1][13] = 1 ; V[1][14] = -1;

  V[2][0] = 0; V[2][1] = 0; V[2][2] = 0; V[2][3] = 1 ; V[2][4] = 0;
  V[2][5] = 0; V[2][6] = -1; V[2][7] = 1; V[2][8] = 1 ; V[2][9] = 1;
  V[2][10] = -1; V[2][11] = 1; V[2][12] = -1; V[2][13] = -1 ; V[2][14] = -1;
  
  int vx[] = {0,1,0,0,-1,0,0,1,-1,1,1,-1,1,-1,-1  }; 
  int vy[] = {0,0,1,0,0,-1,0,1,1,-1,1,-1,-1,1,-1  };
  int vz[] = {0,0,0,1,0,0,-1,1,1,1,-1,1,-1,-1,-1 };
  
  vel_x = array( q , vx);
  vel_y = array (q , vy);
  vel_z = array(q , vz);
  
  rhos = array(Lx, Ly ,Lz , 1);
  Ux = array(Lx, Ly ,Lz , 1);
  Uy = array(Lx, Ly ,Lz , 1);
  Uz = array(Lx, Ly ,Lz , 1);
}
