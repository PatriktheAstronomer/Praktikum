#include "TCanvas.h"
#include "TH1.h"
#include <stdio.h>
#include <stdlib.h>
#include "TGraph.h"
#include "TFrame.h"

void MultiPlot() {
   TCanvas *c1 = new TCanvas("c1","Plot",200,10,600,400);
   c1->SetGrid();
   c1->SetFillColor(kWhite);

   const Int_t n = 77; //maximum number of lines
   const Int_t m = 3864;
   Double_t x1[n], y1[n], ex[n], ey[n], empty[n], empty2[m];
   Double_t x2[m], y2[m];
   for(Int_t i = 0; i < n; i++){ //instead of using EOF
	x1[i] = 0;
        y1[i] = 0.;
        ey[i] = 0;
   }
   for(Int_t i = 0; i < m; i++){ //instead of using EOF
	x2[i] = 0;
        y2[i] = 0;
   }
   FILE* data;
   data = fopen("teplota1SERR.txt","r"); //source name
   for(Int_t i = 0; i < n; i++){
   	fscanf(data, "%lf	%lf	%lf	%lf", &x1[i], &empty[i] , &y1[i], &ey[i]);
	}
   fclose(data);

   TGraphErrors *gr1 = new TGraphErrors(n,x1,y1,0,ey);
   gr1->SetTitle("");
   gr1->GetXaxis()->CenterTitle(1);
   gr1->GetYaxis()->CenterTitle(1);
   gr1->SetFillColor(kWhite);
   gr1->SetLineColor(2);
   gr1->SetMarkerStyle(3);
   gr1->SetLineWidth(1);


   FILE* data2;
   data2 = fopen("Prub1.txt","r"); //2nd source name
   for(Int_t i = 0; i < m; i++){
   	fscanf(data2, "%lf	%lf	%lf", &x2[i], &empty2[i], &y2[i]);
	}
   fclose(data2);
   TGraphErrors *gr2 = new TGraphErrors(m,x2,y2,0,0);

   auto g = new TMultiGraph();
   g ->Add(gr1,"P*");
   g ->Add(gr2,"AC");
   g ->Draw("A");
   
   c1->Update();
   c1->GetFrame()->SetFillColor(0);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
   c1->SaveAs("Plot.png");
}
