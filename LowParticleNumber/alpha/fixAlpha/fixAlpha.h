// author luigisbailo


void fixAlpha (double L ) {


    double D_A=0.01;
	double D_B=0.01;
	const double R_A = 2.5;
	const double R_B = 2.5;
	double tau_bm=0.1;
	int POWsteps = 5;
	const int N = 10;
	const int N_A = 5;
	const int N_B = 5;

	int nAlphas = 6;
	double alphaValues[nAlphas];
	alphaValues[0]=6;
	alphaValues[1]=8;
	alphaValues[2]=10;
	alphaValues[3]=12;
	alphaValues[4]=16;

	int Nsamples[nAlphas];
	Nsamples[0]=100000;
	Nsamples[1]=10000;
	Nsamples[2]=1000;
	Nsamples[3]=100;
	Nsamples[4]=10;
	Nsamples[5]=1;

	int stat [3];
	double diffStat [N];


	int nINTsteps = (int)(pow (10,POWsteps));
	const double Tsim = nINTsteps*tau_bm;


	double arrStat [3][nAlphas];	
	double arrT [nAlphas];	
	// double arrT [nAlphas][Nsamples];	
	// double avTs[nAlphas], varTs[nAlphas];

	for ( int count=0; count<nAlphas; count++){
		arrT [count] = 0;
		// avTs [count] = 0;
		// varTs [count] = 0;
	}
	for (int d=0; d<3; d++) {
		for (int count=0; count<nAlphas; count++) {
			arrStat[d][count]=0;
		}
	}

    clock_t start_t, end_t, total_t;
	double avT;

		for ( int  n=0; n<nAlphas; n++ ){

			for ( int count=0; count < Nsamples[n]; count ++){

			double alpha = alphaValues[n];

 			for (int d=0; d<3; d++) 
 				stat [d] = 0;

 			for (int n=0; n<N; n++)
 				diffStat [n] = 0;

            start_t = clock();

		    run_aGF2 ( N_A, N_B, R_A, R_B, D_A, D_B, tau_bm, alpha, Tsim, L, stat, diffStat );

            end_t = clock();

            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

		    arrT [n] += total_t;
		    arrStat [0][n] += stat[0]; 
		    arrStat [1][n] += stat[1]; 
		    arrStat [2][n] += stat[2]; 
		    // stat[0] is the number of domains burst
		    // stat[1] is the number of domains constructed
		    // stat[2] is the number of brute-force stepsls
		}
	}

	for (int count=0; count<nAlphas; count++)
        printf("%lf\t%lf\t%lf\t%lf\t%lf\n", alphaValues[count],arrT[count]/Nsamples[count],
               arrStat[0][count]/Nsamples[count],arrStat[1][count]/Nsamples[count], arrStat[2][count]/Nsamples[count]);

 
}
