void Fit()
{
   gStyle->SetOptFit();
   auto c1 = new TCanvas("fit","",700,500);
   c1->SetGrid();
   c1->SetFillColor(kWhite);



   const Int_t n = 11; //maximum number of lines
   Double_t x[n], y[n], ey[n], ex[n];
   for(Int_t i = 0; i < n; i++){ //instead of using EOF
	x[i] = 0;
        y[i] = 0;
        ey[i] = 0;
	ex[i] = 0;
   }
   FILE* data;
   data = fopen("Logaritmicke.txt","r"); //source name
   fscanf(data, "%lf	%lf	%lf", &y[0] , &x[0], &ey[0]);
   ex[0] = (0.5)/(1/x[0])*x[0];
   for(Int_t i = 1; i < n; i++){
   	fscanf(data, "%lf	%lf	%lf", &y[i], &x[i], &ey[i]);
	ex[i] = (0.5)/(1/x[0])*x[0];
	}
   fclose(data);

   TGraphErrors *gr1 = new TGraphErrors(n,x,y,ex,ey);
   gr1->SetTitle("");
   gr1->GetXaxis()->SetTitle("T^{-1} [K^{-1} ]");//using latex features
   gr1->GetYaxis()->SetTitle("ln(#nu) [m^{2} s^{-1} ]");
   gr1->GetXaxis()->CenterTitle(1);
   gr1->GetYaxis()->CenterTitle(1);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(21);
   gr1->Fit("pol1","ex0","ey0"); // polynom order, allows using TGraphErrors
   gr1->Draw("AP");

   c1->Update();
   auto stats1 = (TPaveStats*)gr1->GetListOfFunctions()->FindObject("stats");
   stats1->SetTextColor(kBlue);
   stats1->SetX1NDC(0.12); stats1->SetX2NDC(0.32); stats1->SetY1NDC(0.75);
   c1->Modified();
}
