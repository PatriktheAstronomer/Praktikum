TCanvas* FitPartial()
{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","multigraph",700,500);
   c1->SetGrid();
   TMultiGraph *mg = new TMultiGraph();

   const Int_t n = 12; //data to fit
   Double_t x[n], y[n], ey[n], ex[n];
   for(Int_t i = 0; i < n; i++){ //instead of using EOF
	x[i] = 0;
        y[i] = 0;
        ey[i] = 0;
	ex[i] = 0;
   }
   FILE* data;
   data = fopen("trubiceC.txt","r"); 
   for(Int_t i = 0; i < n; i++){
   	fscanf(data, "%lf	%lf	%lf	%lf", &x[i], &ex[i], &y[i], &ey[i]);
   }
   TGraphErrors *gr1 = new TGraphErrors(n,x,y,ex,ey);
   gr1->SetMarkerStyle(21);
   gr1->Fit("pol1","q");
   mg->Add(gr1);

   const Int_t n2 = 30; //rest of data
   Double_t w[n2-n], z[n2-n], ew[n2-n], ez[n2-n];
   for(Int_t i = 0; i < n2-n; i++){ //instead of using EOF
	w[i] = 0;
	ew[i] = 0;
        z[i] = 0;
        ez[i] = 0;
   }
   for(Int_t i = 0; i < n2-n; i++){
   	fscanf(data, "%lf	%lf	%lf	%lf", &w[i], &ew[i], &z[i], &ez[i]);
   }
   fclose(data);
   TGraphErrors *gr2 = new TGraphErrors(n2,w,z,ew,ez);
   gr2->SetMarkerStyle(21);
   mg->Add(gr2);

   mg->Draw("ap");
   mg->GetXaxis()->SetTitle("#Delta p [Pa]");
   mg->GetXaxis()->CenterTitle();
   mg->GetYaxis()->SetTitle("Q [10^{-7} * m^{3} * s^{-1}]");
   mg->GetYaxis()->CenterTitle();
   gPad->Update();

   c1->Update();
   c1->Modified();
   return c1;
}

