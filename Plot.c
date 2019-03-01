#include "TCanvas.h"
#include "TH1.h"
#include <stdio.h>
#include <stdlib.h>
#include "TGraph.h"
#include "TFrame.h"

void Plot() {
   TCanvas *c1 = new TCanvas("c1","Plot",200,10,600,400);
   c1->SetGrid();
   c1->SetFillColor(kWhite);

   const Int_t n = 36; //maximum number of lines, starts from second line!
   Double_t x1[n], y1[n];
   for(Int_t i = 0; i < n; i++){ //instead of using EOF
	x1[i] = 0;
        y1[i] = 0;
   }
   FILE* data;
   data = fopen("Odporvoda.txt","r"); //source name
   fscanf(data, "%lf	%lf", &x1[0], &y1[0]);
   for(Int_t i = 1; i < n; i++){
   	fscanf(data, "%lf	%lf", &x1[i], &y1[i]);
	}
   fclose(data);
/*   for(Int_t i = 0; i < n; i++){
	printf("%lf  %lf\n",x1[i],y1[i]);
   } diagnostic loop */
   TGraph *gr1 = new TGraph(n,x1,y1);
   gr1->SetTitle("");
   gr1->GetXaxis()->SetTitle("#tau [s]");//using latex features
   gr1->GetYaxis()->SetTitle("R [#Omega]");
   gr1->GetXaxis()->CenterTitle(1);
   gr1->GetYaxis()->CenterTitle(1);
   gr1->SetFillColor(kWhite);
   gr1->SetLineColor(2);
   gr1->SetLineWidth(1);
   gr1->Draw("AC*");
   
   
   c1->Update();
   c1->GetFrame()->SetFillColor(0);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
   c1->SaveAs("Plot.png");
}
