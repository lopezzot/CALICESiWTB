
void myGraphSetUp(TGraph *graph, Color_t color, int style){
  graph->SetMarkerStyle(20);
  graph->SetMarkerColor(color);
  graph->SetLineColor(color);
  graph->SetLineWidth(1);
  graph->SetLineStyle(style);
  return;
}

void myTopPadSetUp(TPad *currentPad, float currentLeft=0.15, float currentTop=0.05/0.6, float currentRight=0.05, float currentBottom=0.00){
  currentPad->SetLeftMargin(currentLeft);
  currentPad->SetTopMargin(currentTop);
  currentPad->SetRightMargin(currentRight);
  currentPad->SetBottomMargin(currentBottom);
  currentPad->SetFillColor(10);
  return;
}

void myBottomPadSetUp(TPad *currentPad, float currentLeft=0.15, float currentTop=0.00, float currentRight=0.05, float currentBottom=0.14/0.4){
  currentPad->SetLeftMargin(currentLeft);
  currentPad->SetTopMargin(currentTop);
  currentPad->SetRightMargin(currentRight);
  currentPad->SetBottomMargin(currentBottom);
  currentPad->SetFillColor(10);
  return;
}

void myPadSetUp(TPad *currentPad, float currentLeft=0.15, float currentTop=0.05, float currentRight=0.05, float currentBottom=0.14){
  currentPad->SetLeftMargin(currentLeft);
  currentPad->SetTopMargin(currentTop);
  currentPad->SetRightMargin(currentRight);
  currentPad->SetBottomMargin(currentBottom);
  currentPad->SetFillColor(10);
  return;
}
