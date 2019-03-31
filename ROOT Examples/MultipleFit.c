TCanvas* MultipleFit()
{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","multigraph",700,500);
   c1->SetGrid();
   TMultiGraph *mg = new TMultiGraph();

   Float_t ex[] = {.5,.5,.5,.5,.5,.5,.5,.5,.5,.5,.5,0.5};
   Float_t ey[] = {.005,.005,.005,.005,.005,.005,.005,.005,.005,.005,0.005};

   const Int_t n1 = 11; //ocel
   Float_t x1[]  = {18.5,22.5,26,30.5,35,39.5,44,48,53,56,60};
   Float_t y1[]  = {0,0.02,0.05,0.08,0.11,0.14,0.17,0.2,0.23,0.25,0.28};
   TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex,ey);
   gr1->SetMarkerStyle(21);
   gr1->Fit("pol1","q");
   mg->Add(gr1);

   const Int_t n2 = 11; //mosaz
   Float_t x2[]  = {19,22.5,26,30.5,34.5,39,43,49,51.5,56,60};
   Float_t y2[]  = {0,0.03,0.07,0.12,0.17,0.22,0.27,0.34,0.37,0.42,0.46};
   TGraphErrors *gr2 = new TGraphErrors(n2,x2,y2,ex,ey);
   gr2->SetMarkerStyle(28);
   gr2->Fit("pol1","q");
   mg->Add(gr2);

   const Int_t n3 = 11; //med
   Float_t x3[]  = {19,23,28,32,35,39,43.5,46.5,51,56,60};
   Float_t y3[]  = {0,0.04,0.09,0.13,0.17,0.2,0.24,0.28,0.31,0.35,0.4};
   TGraphErrors *gr3 = new TGraphErrors(n3,x3,y3,ex,ey);
   gr3->SetMarkerStyle(20);
   gr3->Fit("pol1","q");
   mg->Add(gr3);

   const Int_t n4 = 11; //hlinik
   Float_t x4[]  = {18,22,27,31.5,34,37,41,45,50,54.5,59};
   Float_t y4[]  = {0,0.05,0.12,0.18,0.22,0.25,0.31,0.37,0.41,0.46,0.51};
   TGraphErrors *gr4 = new TGraphErrors(n4,x4,y4,ex,ey);
   gr4->SetMarkerStyle(22);
   gr4->Fit("pol1","q");
   mg->Add(gr4);
   mg->Draw("ap");
   mg->GetXaxis()->SetTitle("T [#circ C]");
   mg->GetXaxis()->CenterTitle();
   mg->GetYaxis()->SetTitle("#Delta l [m^{-3}]");
   mg->GetYaxis()->CenterTitle();
   gPad->Update();

   c1->Update();
   c1->Modified();
   return c1;
}

