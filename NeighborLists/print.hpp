void printPos_nl ( particle_nl *particles, int *partList, int N){

  std::cout <<"Part.\t"<<"Time\t"<<"Tau\t"<<"Shell\t"
       <<"x\t"<<"y\t"<<"z\t"
       <<"x_ex\t"<<"y_ex\t"<<"z_ex\t"
       <<"Radius\t" <<"BURST\n";

  for (int count=0; count<N; count++){
      std::cout <<particles[partList[count]].label << "\t"
	 <<particles[partList[count]].time << "\t"
	 <<particles[partList[count]].tau_exit<<"\t"
	 <<particles[partList[count]].shell<<"\t"
	 <<particles[partList[count]].pos[0]<<"\t"
	 <<particles[partList[count]].pos[1]<<"\t"
	 <<particles[partList[count]].pos[2] <<"\t"
	 <<particles[partList[count]].pos_exit[0]<<"\t"
	 <<particles[partList[count]].pos_exit[1]<<"\t"
	 <<particles[partList[count]].pos_exit[2] <<"\t"
	 <<particles[partList[count]].radius <<"\t"
	 <<particles[partList[count]].burst <<"\n";
  }
}

void printPos_per_nl (particle_nl *particles, int *partList, int N){

    std::cout <<"Part.\t"<<"Time\t\t"<<"Tau\t\t"<<"Shell\t"
       <<"x\t"<<"y\t"<<"z\t"
       <<"x_ex\t"<<"y_ex\t"<<"z_ex\t"
       <<"x_per\t"<<"y_per\t"<<"z_per\t"
       <<"Radius\t" <<"BURST\t"<<"GF\n";

  for (int count=0; count<N; count++){
      std::cout <<particles[partList[count]].label << "\t"
	 <<particles[partList[count]].time << "\t\t"
	 <<particles[partList[count]].tau_exit<<"\t\t"
	 <<particles[partList[count]].shell<<"\t"
	 <<particles[partList[count]].pos[0]<<"\t"
	 <<particles[partList[count]].pos[1]<<"\t"
	 <<particles[partList[count]].pos[2] <<"\t"
	 <<particles[partList[count]].pos_exit[0]<<"\t"
	 <<particles[partList[count]].pos_exit[1]<<"\t"
	 <<particles[partList[count]].pos_exit[2] <<"\t"
	 <<particles[partList[count]].pos_period[0]<<"\t"
	 <<particles[partList[count]].pos_period[1]<<"\t"
	 <<particles[partList[count]].pos_period[2] <<"\t"
	 <<particles[partList[count]].radius <<"\t"
	 <<particles[partList[count]].burst <<"\t"
	 <<particles[partList[count]].gf<<"\n";
  }
}


//void printDist_per_nl (particle_nl *particles, int *partList, int N, double L ) {
//
//  for (int n=1; n<N; n++){
//	double dist = sqrt(dist2_per_nl(&particles[partList[0]],&particles[partList[n]],L));
//	double distNext = sqrt(dist2next_per(&particles[partList[0]],&particles[partList[n]],L));
//	double ishell = particles[partList[0]].shell;
//	double jshell = particles[partList[n]].shell;
//      std::cout << "R "<<particles[partList[0]].label<< "-" <<particles[partList[n]].label<<" = "<< dist << "\t"
//	     << "R - shells -inter = "<<dist - (ishell+jshell+particles[partList[n]].radius+particles[partList[0]].radius) << "\t"
//	     << "Rnext -inter = "<<distNext - (particles[partList[n]].radius+particles[partList[0]].radius)
//	     << "\n";
//
//  }
//
//}
//

//
//void print_shell ( particle *particles, int N){
//
//  for (int i=0; i<N; i++){
//      std::cout << "Particle " << i << "\tDiff = " << particles[i].Diff
//	 << "\tR_bm = " << particles[i].R_bd
//	 << "\tShell = " << particles[i].shell
//	 << "\tTau = " << particles[i].tau_exit << "\n";
//
//  }
//}


void print_neighb (particle_nl *particles, std::vector<std::vector<int>> *grid, int N, int Nboxes ){

	for ( int n=0; n<N; n++){
		int i = particles[n].idxBox[0];
		int j = particles[n].idxBox[1];
		int k = particles[n].idxBox[2];
        std::cout << n << ":\t" << i << "\t" << j << "\t" << k << std::endl;
        std::cout << "Boxcheck:\t";
		for ( int count=1; count<(*grid)[i*Nboxes*Nboxes + j*Nboxes + k][0]+2; count++  ){
            std::cout << (*grid)[i*Nboxes*Nboxes + j*Nboxes + k][count] << "\t";
		}
        std::cout << std::endl;
	}

    std::cout << std::endl;


}