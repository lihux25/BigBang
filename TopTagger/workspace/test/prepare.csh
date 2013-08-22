#! /bin/csh -f
#
set releaseDir = ${CMSSW_BASE}

set incDir = ${releaseDir}/src/UserCode/TopTagger/interface
set workDir = ${releaseDir}/src/UserCode/TopTagger/workspace


set auxDir = ${releaseDir}/src/recipeAUX

set combH = ${incDir}/combination.h
set idxSortH = ${incDir}/indexSort.h
set taggerClassH = ${incDir}/Type3TopTagger.h

set rootlogonC = ${workDir}/configs/rootlogon.C

set plot = ${workDir}/configs/plotsType3TopTagger.C

set flatNtupleDir = /eos/uscms/store/user/seema/SusyStopAnalysis2012

set pudata = ${workDir}/configs/PUData_dist.root

set sampleDir = ${workDir}/test/sample_dir
set samplelist = ${sampleDir}/\*.txt

set topheadH = ${workDir}/configs/tophead.h

set tdrstyleC = ${releaseDir}/src/UserCode/DataFormats/aux/tdrstyle.C

ln -s $auxDir .
ln -s $combH .
ln -s $idxSortH .
ln -s $taggerClassH .
ln -s $rootlogonC .
ln -s $topheadH .
ln -s $tdrstyleC .
ln -s $plot .
ln -s $flatNtupleDir .
echo 'This is pu data from RA2 with orignal name DataPileupHistogram_RA2Summer12_190456-203002_ABC.root'
ln -s $pudata .
cp $samplelist .
ln -s ${flatNtupleDir}/tree_T_tW_powheg_tauolo T_tW
ln -s ${flatNtupleDir}/tree_qcd_ht250to500_madgraph QCD_250HT500
ln -s ${flatNtupleDir}/tree_qcd_ht500to1000_madgraph QCD_500HT1000
ln -s ${flatNtupleDir}/tree_qcd_ht1000toinf_madgraph QCD_1000HTinf
ln -s ${flatNtupleDir}/tree_znunu_madgraph_200ht400 Zinv_200HT400
ln -s ${flatNtupleDir}/tree_znunu_madgraph_400htInf Zinv_400HTinf
ln -s ${flatNtupleDir}/tree_wjets_madgraph_250ht300 WJetsToLNu_250HT300
ln -s ${flatNtupleDir}/tree_wjets_madgraph_300ht400 WJetsToLNu_300HT400
ln -s ${flatNtupleDir}/tree_wjets_madgraph_400htInf WJetsToLNu_400HTinf
ln -s ${flatNtupleDir}/tree_ttjets_ct10_powheg TTJets
ln -s ${flatNtupleDir}/tree_t2tt_pythia_frompattuples T2tt

