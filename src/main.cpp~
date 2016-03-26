#include <LBD3Q15.h>
#include <ForceModule.h>
#include <ObstacleLoader.h>
#include <ELB3DQ15.h>
array ensayos1(){
   
} 

void nonEntropicCall() {
 int pasos = 500;
  
   //af::info();
  int Lx, Ly, Lz ;
  
  Lx = 100; 
  Ly = Lz = 100;
  LatticeBolztmannD3Q15 fluid(Lx,Ly, Lz);
  fluid.Inicie( 1 , 0.03 , 0 , 0 );
  //ObstacleLoader obl(Lx,Ly,Lz);
  
  //std::string ruta = "./simulation-runs/objectData/esfera-200.dat" ;
  //std::string rutaFs = "./simulation-runs/Fs/esfera-200-10000/";
  //fluid.setArrayC( obl.loadFile(ruta , Lx, Ly, Lz) );
 
  //fluid.setArrayC( obl.loadFile2(ruta , Lx, Ly, Lz) );
  std::cout << " # Adveccion" << std::endl;
  double T = 0;
  for( int p = 0 ; p < pasos ; p++){
    af::timer timeit = af::timer::start();
     fluid.Colission();
     fluid.Adveccion();
    double t = af::timer::stop( timeit );
    T+=t;
    std::cout << p << " " << t << std::endl ;
  }
  std::cout << "# time:" << T << std::endl;
  double MUPS = (Lx*Ly*Lz)/1e6;
  MUPS = (MUPS*pasos)/T;
  
  std::cout << "#MUPS " << MUPS << std::endl;
   //fluid.saveVTK("./simulation-runs/Fs/steps=500/esfera-Re=50.vtk");
  //fluid.SaveFs(rutaFs);
  // ForceModule  fm(rutaFs);
  // fm.calculateForce();
 
}
void EntropicCall(){
  int pasos = 1; 
  int Lx, Ly, Lz;
  Lx = Ly = Lz = 5;
  ELatticeBolztmannD3Q15 Efluid( Lx , Ly , Lz );
  Efluid.Inicie( 1 , 0.03 , 0 , 0 );
  af::timer timeit = timer::start();
  for ( int i = 0 ; i < pasos ; i++){
    
    Efluid.Adveccion();
    Efluid.Colission();
  }
  double t = af::timer::stop(timeit);
  double MUPS = (Lx*Ly*Lz)/1e6;
  MUPS = (MUPS*pasos)/t;
  std::cout << "#MUPs:" << MUPS << std::endl;
  
  //Efluid.saveVTK("./entropic-lid-driven.vtk");
} 


int main(int argc , char * argv[] ){
  
  int device = argc > 1 ? atoi(argv[1]) : 0 ;
  af::setDevice(device);

  //EntropicCall();
  nonEntropicCall();
}
