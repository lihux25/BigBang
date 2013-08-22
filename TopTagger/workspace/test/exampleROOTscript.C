#include "Type3TopTagger.h"
#include "TLorentzVector.h"

#include "recipeAUX/OxbridgeMT2/interface/Basic_Mt2_332_Calculator.h"
#include "recipeAUX/OxbridgeMT2/interface/ChengHanBisect_Mt2_332_Calculator.h"

using namespace std;

topTagger::type3TopTagger * type3Ptr;

const double mTbcut_ = 500, mTtcut_ = 365, MT2cut_ = 300, mTWcut_ = 600;
const double lowTopCut_ = 80, highTopCut_ = 270, lowWCut_ = 50, highWCut_ = 120;

// PDG values (in GeV)
static const double mW_ = 80.385, mTop_ = 173.5;

static const double mWoverTop_ = mW_/mTop_;

static const double lowRatioWoverTop_ = 0.85, highRatioWoverTop_ = 1.25;
static const double lowArcTanm13overm12_ = 0.2, highArcTanm13overm12_ = 1.3, lowm23overm123_ = 0.35;

static const double Rmin_ = lowRatioWoverTop_*mWoverTop_, Rmax_ = highRatioWoverTop_*mWoverTop_;

void exampleROOTscript(){

  type3Ptr = new topTagger::type3TopTagger();

// Change the default settings using the build-in function 
// from the type3TopTagger if you want (ref topTagger::type3TopTagger constructor)

// The following usually is in an event loop

// Keep one-to-one correspondance between inputJetsVec and inputJetsCSVMVec
// CSVM is used!
  std::vector<TLorentzVector> inputJetsVec;
  std::vector<double> inputJetsCSVMVec;
// TLorentzVector of met --> metLVec.SetPtEtaPhiM(met, 0, metphi, 0);
  TLorentzVector metLVec;

// Several functions built together in the topTagger::type3TopTagger::processEvent function.
// One can run them one-by-one or only run part of them for some specific purpose.
  bool pass = type3Ptr->processEvent(inputJetsVec, inputJetsCSVMVec, metLVec);

// Example of acessing the variables after processing the event
  int combSize = type3Ptr->combSize;

  for(int ic=0; ic<combSize; ic++){

     const TLorentzVector fatJet = type3Ptr->buildLVec( inputJetsVec, type3Ptr->finalCombfatJets[ic] );
     const TLorentzVector subJet12 = type3Ptr->buildLVec( inputJetsVec, type3Ptr->finalCombJetSubStruc[ic][0] );
     const TLorentzVector subJet13 = type3Ptr->buildLVec( inputJetsVec, type3Ptr->finalCombJetSubStruc[ic][1] );
     const TLorentzVector subJet23 = type3Ptr->buildLVec( inputJetsVec, type3Ptr->finalCombJetSubStruc[ic][2] );

     const double fatJetm123 = fatJet.M();
     const double fatJetm12  = subJet12.M();
     const double fatJetm13  = subJet13.M();
     const double fatJetm23  = subJet23.M();

     const double fatJetPt = fatJet.Pt();
         
     int isTopJet = 0;
     int statusCat00 = type3Ptr->finalCombfatJetsPassStatusVec[ic][0];
     int statusCat01 = type3Ptr->finalCombfatJetsPassStatusVec[ic][1];
     int statusCat02 = type3Ptr->finalCombfatJetsPassStatusVec[ic][2];
     if( statusCat00 ==1 || statusCat01 ==1 || statusCat02 ==1 ) isTopJet =1;
  }

  if( type3Ptr->bestTopJetIdx == -1 ) continue;
   
  if( ! (type3Ptr->bestTopJetMass > lowTopCut_ && type3Ptr->bestTopJetMass < highTopCut_ ) ) continue;

  if( !type3Ptr->remainPassCSVS ) continue;

  if( type3Ptr->pickedRemainingCombfatJetIdx == -1 && inputJetsVec.size()>=6 ) continue;
   
  if( !(type3TopTaggerPtr->MT2 > MT2cut_ && (type3TopTaggerPtr->mTbJet + 0.5*type3TopTaggerPtr->mTbestTopJet) > mTbcut_) ) continue;
     
}
