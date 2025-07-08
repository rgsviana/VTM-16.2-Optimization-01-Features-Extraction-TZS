//RAMIRO - VTM 16.2 - Otimização Inter-Quadros - Extração Features TZS

#include "extracaoDados.h"
#include <stdio.h>
#include <iostream>

using namespace std;

ofstream extracaoDados::arqTempos;
ofstream extracaoDados::arqBlocos;
ofstream extracaoDados::arqblocosEscolidos;

string extracaoDados::nameVideo;
int extracaoDados::numQp;
int extracaoDados::numFrames;
int extracaoDados::widthVideo;
int extracaoDados::heightVideo;

/*Variáveis controle*/
int extracaoDados::flagBDOFInter;
int extracaoDados::flagBDOFmerge;

#if EXTRA_FEATURES
    ofstream extracaoDados::arqFeatures;
    //variáveis features
    int extracaoDados::POC;
    int extracaoDados::QP;
    int extracaoDados::depth;
    int extracaoDados::qtDepth;
    int extracaoDados::mtDepht;
    int extracaoDados::videoWidth;
    int extracaoDados::videoHeight;
    int extracaoDados::cuPosX;
    int extracaoDados::cuPosY;
    int extracaoDados::cuWidth;
    int extracaoDados::cuHeight;
    int extracaoDados::bcwIndex;
    int extracaoDados::IMV;
    int extracaoDados::mvUniL0HorX;
    int extracaoDados::mvUniL0VerY;
    int extracaoDados::mvUniL1HorX;
    int extracaoDados::mvUniL1VerY;
    int extracaoDados::mvPredUniL0HorX;
    int extracaoDados::mvPredUniL0VerY;
    int extracaoDados::mvPredUniL1HorX;
    int extracaoDados::mvPredUniL1VerY;
    uint64_t extracaoDados::custoMvUniL0;
    uint64_t extracaoDados::custoMvUniL1;
    uint64_t extracaoDados::custoMvUniL0_1;
    uint64_t extracaoDados::custoMvUniL1_1;
    int extracaoDados::bitsMvUniL0;
    int extracaoDados::bitsMvUniL1;
    int extracaoDados::mvBiL0HorX;
    int extracaoDados::mvBiL0VerY;
    int extracaoDados::mvBiL1HorX;
    int extracaoDados::mvBiL1VerY;
    int extracaoDados::mvPredBiL0HorX;
    int extracaoDados::mvPredBiL0VerY;
    int extracaoDados::mvPredBiL1HorX;
    int extracaoDados::mvPredBiL1VerY;
    uint64_t extracaoDados::custoBi;
    int extracaoDados::bitsMvBi;
    int extracaoDados::SMVD;
    int extracaoDados::interDir;
    int extracaoDados::atualQP;
    int extracaoDados::affinePai;
    uint64_t extracaoDados::custoPai;
    int extracaoDados::IMV_Pai;
    int extracaoDados::affineVizEsq;
    int extracaoDados::affineVizEsq_1;
    uint64_t extracaoDados::custoVizEsq;
    int extracaoDados::IMV_VizEsq;
    int extracaoDados::affineVizAci;
    int extracaoDados::affineVizAci_1;
    uint64_t extracaoDados::custoVizAci;
    int extracaoDados::IMV_VizAci;
    int extracaoDados::cuAtualAffine;
    uint64_t extracaoDados::affCustoMvUniL0;
    uint64_t extracaoDados::affCustoMvUniL1;
    uint64_t extracaoDados::affCustoMvUniL0_1;
    uint64_t extracaoDados::affCustoMvUniL1_1;
    uint64_t extracaoDados::affCustoMvBi;
    int extracaoDados::affMvUniL0P0HorX;
    int extracaoDados::affMvUniL0P0VerY;
    int extracaoDados::affMvUniL0P1HorX;
    int extracaoDados::affMvUniL0P1VerY;
    int extracaoDados::affMvUniL1P0HorX;
    int extracaoDados::affMvUniL1P0VerY;
    int extracaoDados::affMvUniL1P1HorX;
    int extracaoDados::affMvUniL1P1VerY;
    int extracaoDados::affMvPredUniL0P0HorX;
    int extracaoDados::affMvPredUniL0P0VerY;
    int extracaoDados::affMvPredUniL0P1HorX;
    int extracaoDados::affMvPredUniL0P1VerY; 
    int extracaoDados::affMvPredUniL1P0HorX;
    int extracaoDados::affMvPredUniL1P0VerY;
    int extracaoDados::affMvPredUniL1P1HorX;
    int extracaoDados::affMvPredUniL1P1VerY;
    int extracaoDados::affMvBiL0P0HorX;
    int extracaoDados::affMvBiL0P0VerY;
    int extracaoDados::affMvBiL0P1HorX;
    int extracaoDados::affMvBiL0P1VerY;   
    int extracaoDados::affMvBiL1P0HorX;
    int extracaoDados::affMvBiL1P0VerY;
    int extracaoDados::affMvBiL1P1HorX;
    int extracaoDados::affMvBiL1P1VerY; 
    int extracaoDados::affMvPredBiL0P0HorX;
    int extracaoDados::affMvPredBiL0P0VerY;
    int extracaoDados::affMvPredBiL0P1HorX;
    int extracaoDados::affMvPredBiL0P1VerY;   
    int extracaoDados::affMvPredBiL1P0HorX;
    int extracaoDados::affMvPredBiL1P0VerY;
    int extracaoDados::affMvPredBiL1P1HorX;
    int extracaoDados::affMvPredBiL1P1VerY;
    int extracaoDados::affbitsMvUniL0;
    int extracaoDados::affBitsMvUniL1;
    int extracaoDados::affBitsMvBi;    
    int extracaoDados::affInterDir;
    int extracaoDados::affTypePai;  
    int extracaoDados::affTypeVizEsq;
    int extracaoDados::affTypeVizAci;
    int extracaoDados::cuAtualAffineType;
    int extracaoDados::rui_SAD;
    int extracaoDados::cStruct_iBestX;
    int extracaoDados::cStruct_iBestY;
    int extracaoDados::executaTZS;
    int extracaoDados::modoSplit;
    int extracaoDados::modoSplit_temp;
    //fim variáveis features

    //funções features
    void extracaoDados::setPOC(int _POC){ POC = _POC; }
    void extracaoDados::setQP(int _QP){ QP = _QP;}
    void extracaoDados::setDepth(int _depth){ depth = _depth; }
    void extracaoDados::setQtDepth(int _qtDepth){ qtDepth = _qtDepth; }
    void extracaoDados::setMtDepht(int _mtDepth){ mtDepht = _mtDepth; }
    void extracaoDados::setVideoWidth(int _videoWidth){ videoWidth = _videoWidth; }
    void extracaoDados::setVideoHeight(int _videoHeight){ videoHeight = _videoHeight; }
    void extracaoDados::setCuPosX(int _cuPosX){ cuPosX = _cuPosX; }
    void extracaoDados::setCuPosY(int _cuPosY){ cuPosY = _cuPosY; }
    void extracaoDados::setCuWidth(int _cuWidth){ cuWidth = _cuWidth; }
    void extracaoDados::setCuHeight(int _cuHeight){ cuHeight = _cuHeight; }
    void extracaoDados::setBcwIndex(int _bcwIndex){ bcwIndex = _bcwIndex; }
    void extracaoDados::setIMV(int _imv){ IMV = _imv; }
    void extracaoDados::setMvUniL0HorX(int _mvUniL0HorX){ mvUniL0HorX = _mvUniL0HorX; }
    void extracaoDados::setMvUniL0VerY(int _mvUniL0VerY){ mvUniL0VerY = _mvUniL0VerY; }
    void extracaoDados::setMvUniL1HorX(int _mvUniL1HorX){ mvUniL1HorX = _mvUniL1HorX; }
    void extracaoDados::setMvUniL1VerY(int _mvUniL1VerY){ mvUniL1VerY = _mvUniL1VerY; }
    void extracaoDados::setMvPredUniL0HorX(int _mvPredUniL0HorX){ mvPredUniL0HorX = _mvPredUniL0HorX; }
    void extracaoDados::setMvPredUniL0VerY(int _mvPredUniL0VerY){ mvPredUniL0VerY = _mvPredUniL0VerY; }
    void extracaoDados::setMvPredUniL1HorX(int _mvPredUniL1HorX){ mvPredUniL1HorX = _mvPredUniL1HorX; }
    void extracaoDados::setMvPredUniL1VerY(int _mvPredUniL1VerY){ mvPredUniL1VerY = _mvPredUniL1VerY; }
    void extracaoDados::setCustoMvUniL0(uint64_t _custoMvUniL0){ custoMvUniL0 = _custoMvUniL0; }
    void extracaoDados::setCustoMvUniL1(uint64_t _custoMvUniL1){ custoMvUniL1 = _custoMvUniL1; }
    void extracaoDados::setCustoMvUniL0_1(uint64_t _custoMvUniL0_1){ custoMvUniL0_1 = _custoMvUniL0_1; }
    void extracaoDados::setCustoMvUniL1_1(uint64_t _custoMvUniL1_1){ custoMvUniL1_1 = _custoMvUniL1_1; } 
    void extracaoDados::setBitsMvUniL0(int _bitsMvUniL0){ bitsMvUniL0 = _bitsMvUniL0; }
    void extracaoDados::setBitsMvUniL1(int _bitsMvUniL1){ bitsMvUniL1 = _bitsMvUniL1; }
    void extracaoDados::setMvBiL0HorX(int _mvBiL0HorX){ mvBiL0HorX = _mvBiL0HorX; }
    void extracaoDados::setMvBiL0VerY(int _mvBiL0VerY){ mvBiL0VerY = _mvBiL0VerY; }
    void extracaoDados::setMvBiL1HorX(int _mvBiL1HorX){ mvBiL1HorX = _mvBiL1HorX; }
    void extracaoDados::setMvBiL1VerY(int _mvBiL1VerY){ mvBiL1VerY = _mvBiL1VerY; }
    void extracaoDados::setMvPredBiL0HorX(int _mvPredBiL0HorX){ mvPredBiL0HorX = _mvPredBiL0HorX; }
    void extracaoDados::setMvPredBiL0VerY(int _mvPredBiL0VerY){ mvPredBiL0VerY = _mvPredBiL0VerY; }
    void extracaoDados::setMvPredBiL1HorX(int _mvPredBiL1HorX){ mvPredBiL1HorX = _mvPredBiL1HorX; }
    void extracaoDados::setMvPredBiL1VerY(int _mvPredBiL1VerY){ mvPredBiL1VerY = _mvPredBiL1VerY; }
    void extracaoDados::setCustoBi(uint64_t _custoBi){ custoBi = _custoBi; }
    void extracaoDados::setBitsMvBi(int _bitsMvBi){bitsMvBi = _bitsMvBi; }
    void extracaoDados::setSMVD(int _SMVD){ SMVD = _SMVD; }
    void extracaoDados::setInterDir(int _interDir){ interDir = _interDir; }
    void extracaoDados::setAtualQP(int _atualQP){ atualQP = _atualQP; }
    void extracaoDados::setAffinePai(int _affinePai){ affinePai = _affinePai; }
    void extracaoDados::setCustoPai(uint64_t _custoPai){ custoPai = _custoPai; }
    void extracaoDados::setIMV_Pai(int _IMV_Pai){ IMV_Pai = _IMV_Pai; }
    void extracaoDados::setAffineVizEsq(int _affineVizEsq){ affineVizEsq = _affineVizEsq; }
    void extracaoDados::setAffineVizEsq_1(int _affineVizEsq_1){ affineVizEsq_1 = _affineVizEsq_1; };
    void extracaoDados::setCustoVizEsq(uint64_t _custoVizEsq){ custoVizEsq = _custoVizEsq; }
    void extracaoDados::setIMV_VizEsq(int _IMV_VizEsq){ IMV_VizEsq = _IMV_VizEsq; }
    void extracaoDados::setAffineVizAci(int _affineVizAci){ affineVizAci = _affineVizAci; }
    void extracaoDados::setAffineVizAci_1(int _affineVizAci_1){ affineVizAci_1 = _affineVizAci_1; }
    void extracaoDados::setCustoVizAci(uint64_t _custoVizAci){ custoVizAci = _custoVizAci; }
    void extracaoDados::setIMV_VizAci(int _IMV_VizAci){ IMV_VizAci = _IMV_VizAci; }//novo
    void extracaoDados::setCuAtualAffine(int _cuAtualAffine){ cuAtualAffine = _cuAtualAffine; }
    void extracaoDados::setAffCustoMvUniL0(uint64_t _affCustoMvUniL0){ affCustoMvUniL0 = _affCustoMvUniL0; }
    void extracaoDados::setAffCustoMvUniL1(uint64_t _affCustoMvUniL1){ affCustoMvUniL1 = _affCustoMvUniL1; } 
    void extracaoDados::setAffCustoMvUniL0_1(uint64_t _affCustoMvUniL0_1){ affCustoMvUniL0_1 = _affCustoMvUniL0_1; }
    void extracaoDados::setAffCustoMvUniL1_1(uint64_t _affCustoMvUniL1_1){ affCustoMvUniL1_1 = _affCustoMvUniL1_1; }
    void extracaoDados::setAffCustoMvBi(uint64_t _affCustoMvBi){ affCustoMvBi = _affCustoMvBi; } 
    void extracaoDados::setAffMvUniL0P0HorX(int _affMvUniL0P0HorX){ affMvUniL0P0HorX = _affMvUniL0P0HorX; }
    void extracaoDados::setAffMvUniL0P0VerY(int _affMvUniL0P0VerY){ affMvUniL0P0VerY = _affMvUniL0P0VerY; }
    void extracaoDados::setAffMvUniL0P1HorX(int _affMvUniL0P1HorX){ affMvUniL0P1HorX = _affMvUniL0P1HorX; }
    void extracaoDados::setAffMvUniL0P1VerY(int _affMvUniL0P1VerY){ affMvUniL0P1VerY = _affMvUniL0P1VerY; }
    void extracaoDados::setAffMvUniL1P0HorX(int _affMvUniL1P0HorX){ affMvUniL1P0HorX = _affMvUniL1P0HorX; }
    void extracaoDados::setAffMvUniL1P0VerY(int _affMvUniL1P0VerY){ affMvUniL1P0VerY = _affMvUniL1P0VerY; }
    void extracaoDados::setAffMvUniL1P1HorX(int _affMvUniL1P1HorX){ affMvUniL1P1HorX = _affMvUniL1P1HorX; }
    void extracaoDados::setAffMvUniL1P1VerY(int _affMvUniL1P1VerY){ affMvUniL1P1VerY = _affMvUniL1P1VerY; }
    void extracaoDados::setAffMvPredUniL0P0HorX(int _affMvPredUniL0P0HorX){ affMvPredUniL0P0HorX = _affMvPredUniL0P0HorX; }
    void extracaoDados::setAffMvPredUniL0P0VerY(int _affMvPredUniL0P0VerY){ affMvPredUniL0P0VerY = _affMvPredUniL0P0VerY; }
    void extracaoDados::setAffMvPredUniL0P1HorX(int _affMvPredUniL0P1HorX){ affMvPredUniL0P1HorX = _affMvPredUniL0P1HorX; }
    void extracaoDados::setAffMvPredUniL0P1VerY(int _affMvPredUniL0P1VerY){ affMvPredUniL0P1VerY = _affMvPredUniL0P1VerY; }  
    void extracaoDados::setAffMvPredUniL1P0HorX(int _affMvPredUniL1P0HorX){ affMvPredUniL1P0HorX = _affMvPredUniL1P0HorX; }
    void extracaoDados::setAffMvPredUniL1P0VerY(int _affMvPredUniL1P0VerY){ affMvPredUniL1P0VerY = _affMvPredUniL1P0VerY; }
    void extracaoDados::setAffMvPredUniL1P1HorX(int _affMvPredUniL1P1HorX){ affMvPredUniL1P1HorX = _affMvPredUniL1P1HorX; }
    void extracaoDados::setAffMvPredUniL1P1VerY(int _affMvPredUniL1P1VerY){ affMvPredUniL1P1VerY = _affMvPredUniL1P1VerY; }
    void extracaoDados::setAffMvBiL0P0HorX(int _affMvBiL0P0HorX){ affMvBiL0P0HorX = _affMvBiL0P0HorX; }
    void extracaoDados::setAffMvBiL0P0VerY(int _affMvBiL0P0VerY){ affMvBiL0P0VerY = _affMvBiL0P0VerY; }
    void extracaoDados::setAffMvBiL0P1HorX(int _affMvBiL0P1HorX){ affMvBiL0P1HorX = _affMvBiL0P1HorX; }
    void extracaoDados::setAffMvBiL0P1VerY(int _affMvBiL0P1VerY){ affMvBiL0P1VerY = _affMvBiL0P1VerY; }   
    void extracaoDados::setAffMvBiL1P0HorX(int _affMvBiL1P0HorX){ affMvBiL1P0HorX = _affMvBiL1P0HorX; }
    void extracaoDados::setAffMvBiL1P0VerY(int _affMvBiL1P0VerY){ affMvBiL1P0VerY = _affMvBiL1P0VerY; }
    void extracaoDados::setAffMvBiL1P1HorX(int _affMvBiL1P1HorX){ affMvBiL1P1HorX = _affMvBiL1P1HorX; }
    void extracaoDados::setAffMvBiL1P1VerY(int _affMvBiL1P1VerY){ affMvBiL1P1VerY = _affMvBiL1P1VerY; }
    void extracaoDados::setAffMvPredBiL0P0HorX(int _affMvPredBiL0P0HorX){ affMvPredBiL0P0HorX = _affMvPredBiL0P0HorX; }
    void extracaoDados::setAffMvPredBiL0P0VerY(int _affMvPredBiL0P0VerY){ affMvPredBiL0P0VerY = _affMvPredBiL0P0VerY; }
    void extracaoDados::setAffMvPredBiL0P1HorX(int _affMvPredBiL0P1HorX){ affMvPredBiL0P1HorX = _affMvPredBiL0P1HorX; }
    void extracaoDados::setAffMvPredBiL0P1VerY(int _affMvPredBiL0P1VerY){ affMvPredBiL0P1VerY = _affMvPredBiL0P1VerY; } 
    void extracaoDados::setAffMvPredBiL1P0HorX(int _affMvPredBiL1P0HorX){ affMvPredBiL1P0HorX = _affMvPredBiL1P0HorX; }
    void extracaoDados::setAffMvPredBiL1P0VerY(int _affMvPredBiL1P0VerY){ affMvPredBiL1P0VerY = _affMvPredBiL1P0VerY; }
    void extracaoDados::setAffMvPredBiL1P1HorX(int _affMvPredBiL1P1HorX){ affMvPredBiL1P1HorX = _affMvPredBiL1P1HorX; }
    void extracaoDados::setaffMvPredBiL1P1VerY(int _affMvPredBiL1P1VerY){ affMvPredBiL1P1VerY = _affMvPredBiL1P1VerY; } 
    void extracaoDados::setAffbitsMvUniL0(int _affbitsMvUniL0){ affbitsMvUniL0 = _affbitsMvUniL0; }
    void extracaoDados::setAffBitsMvUniL1(int _affBitsMvUniL1){ affBitsMvUniL1 = _affBitsMvUniL1; }
    void extracaoDados::setAffBitsMvBi(int _affBitsMvBi){ affBitsMvBi = _affBitsMvBi; } 
    void extracaoDados::setAffInterDir(int _affInterDir){ affInterDir = _affInterDir; }
    void extracaoDados::setAffTypePai(int _affTypePai){ affTypePai = _affTypePai; }
    void extracaoDados::setAffTypeVizEsq(int _affTypeVizEsq){ affTypeVizEsq = _affTypeVizEsq; }
    void extracaoDados::setAffTypeVizAci(int _affTypeVizAci){ affTypeVizAci = _affTypeVizAci; };
    void extracaoDados::setCuAtualAffineType(int _cuAtualAffineType){ cuAtualAffineType = _cuAtualAffineType; }
    void extracaoDados::setrui_SAD(int _rui_SAD){ rui_SAD = _rui_SAD; }
    void extracaoDados::setcStruct_iBestX(int _cStruct_iBestX){ cStruct_iBestX = _cStruct_iBestX; }
    void extracaoDados::setcStruct_iBestY(int _cStruct_iBestY){ cStruct_iBestY = _cStruct_iBestY; }
    void extracaoDados::setexecutaTZS(int _executaTZS){ executaTZS = _executaTZS; }
    void extracaoDados::setModoSplit(int _modoSplit){ modoSplit = _modoSplit; }
    void extracaoDados::setModoSplit_temp(){ modoSplit_temp = modoSplit; }
    //fim funções features
    
    void extracaoDados::registraFeatures(){

    arqFeatures  
            //<< POC                  <<";"
            << numQp                <<";"
            << depth                <<";"
            << qtDepth              <<";"
            << mtDepht              <<";"
            << videoWidth           <<";"
            << videoHeight          <<";"
            << cuPosX               <<";"
            << cuPosY               <<";"
            << cuWidth              <<";"
            << cuHeight             <<";"
            //<< modoSplit_temp       <<";"
            << bcwIndex             <<";"
            << IMV                  <<";"       
            << mvUniL0HorX          <<";"
            << mvUniL0VerY          <<";"
            << mvUniL1HorX          <<";"
            << mvUniL1VerY          <<";"          
            //<< mvPredUniL0HorX      <<";"
            //<< mvPredUniL0VerY      <<";"
            //<< mvPredUniL1HorX      <<";"
            //<< mvPredUniL1VerY      <<";"        
            << custoMvUniL0         <<";"
            << custoMvUniL1         <<";"
            //<< custoMvUniL0_1       <<";"
            //<< custoMvUniL1_1       <<";"       
            << bitsMvUniL0          <<";"
            << bitsMvUniL1          <<";"      
            << mvBiL0HorX           <<";"
            << mvBiL0VerY           <<";"
            << mvBiL1HorX           <<";"
            << mvBiL1VerY           <<";"            
            //<< mvPredBiL0HorX       <<";"
            //<< mvPredBiL0VerY       <<";"
            //<< mvPredBiL1HorX       <<";"
            //<< mvPredBiL1VerY       <<";"           
            << custoBi              <<";"           
            << bitsMvBi             <<";"
            << SMVD                 <<";"
            << interDir             <<";"
            << atualQP              <<";"   
            /*
            << affinePai            <<";"
            << custoPai             <<";"
            << IMV_Pai              <<";"             
            << affineVizEsq         <<";"
            << affineVizEsq_1       <<";"
            << custoVizEsq          <<";"
            << IMV_VizEsq           <<";"           
            << affineVizAci         <<";"
            << affineVizAci_1       <<";"
            << custoVizAci          <<";"
            << IMV_VizAci           <<";"            
            << cuAtualAffine        <<";"            
            << affCustoMvUniL0      <<";"
            << affCustoMvUniL1      <<";"
            << affCustoMvUniL0_1    <<";"
            << affCustoMvUniL1_1    <<";"           
            << affCustoMvBi         <<";"            
            << affMvUniL0P0HorX     <<";"
            << affMvUniL0P0VerY     <<";"
            << affMvUniL0P1HorX     <<";"
            << affMvUniL0P1VerY     <<";"            
            << affMvUniL1P0HorX     <<";"
            << affMvUniL1P0VerY     <<";"
            << affMvUniL1P1HorX     <<";"
            << affMvUniL1P1VerY     <<";"            
            << affMvPredUniL0P0HorX <<";"
            << affMvPredUniL0P0VerY <<";"
            << affMvPredUniL0P1HorX <<";"
            << affMvPredUniL0P1VerY <<";"           
            << affMvPredUniL1P0HorX <<";"
            << affMvPredUniL1P0VerY <<";"
            << affMvPredUniL1P1HorX <<";"
            << affMvPredUniL1P1VerY <<";"           
            << affMvBiL0P0HorX      <<";"
            << affMvBiL0P0VerY      <<";"
            << affMvBiL0P1HorX      <<";"
            << affMvBiL0P1VerY      <<";"    
            << affMvBiL1P0HorX      <<";"
            << affMvBiL1P0VerY      <<";"
            << affMvBiL1P1HorX      <<";"
            << affMvBiL1P1VerY      <<";"            
            << affMvPredBiL0P0HorX  <<";"
            << affMvPredBiL0P0VerY  <<";"
            << affMvPredBiL0P1HorX  <<";"
            << affMvPredBiL0P1VerY  <<";"
            << affMvPredBiL1P0HorX  <<";"
            << affMvPredBiL1P0VerY  <<";"
            << affMvPredBiL1P1HorX  <<";"
            << affMvPredBiL1P1VerY  <<";"            
            << affbitsMvUniL0       <<";"
            << affBitsMvUniL1       <<";"
            << affBitsMvBi          <<";"
            << affInterDir          <<";"           
            << affTypePai           <<";"           
            << affTypeVizEsq        <<";"
            << affTypeVizAci        <<";"                      
            << cuAtualAffineType    <<";" 
            */
            << rui_SAD              <<";"        
            << cStruct_iBestX       <<";"        
            << cStruct_iBestY       <<";"
            << executaTZS
            <<endl;
           // inicializaFeatures();
    } 
    
    void extracaoDados::inicializaFeatures(){

        //POC           = 111111;
        depth         = 111111;
        qtDepth       = 111111;
        mtDepht       = 111111;
        videoWidth    = 111111;
        videoHeight   = 111111;
        cuPosX        = 111111;
        cuPosY        = 111111;
        cuWidth       = 111111;
        cuHeight      = 111111;
        //modoSplit_temp= 111111;
        bcwIndex      = 111111;
        IMV           = 111111;   
        mvUniL0HorX   = 111111;
        mvUniL0VerY   = 111111;
        mvUniL1HorX   = 111111;
        mvUniL1VerY   = 111111;   
        //mvPredUniL0HorX  = 111111;
        //mvPredUniL0VerY  = 111111;
        //mvPredUniL1HorX  = 111111;
        //mvPredUniL1VerY  = 111111;   
        custoMvUniL0 = 111111;
        custoMvUniL1 = 111111;
        //custoMvUniL0_1 = 111111;
        //custoMvUniL1_1 = 111111;   
        bitsMvUniL0  = 111111;
        bitsMvUniL1  = 111111;    
        custoMvUniL0  = 111111;
        custoMvUniL1  = 111111;
        bitsMvUniL0   = 111111;
        bitsMvUniL1   = 111111;   
        mvBiL0HorX    = 111111;
        mvBiL0VerY    = 111111;
        mvBiL1HorX    = 111111;
        mvBiL1VerY    = 111111;    
        //mvPredBiL0HorX  = 111111;
        //mvPredBiL0VerY  = 111111;
        //mvPredBiL1HorX  = 111111;
        //mvPredBiL1VerY  = 111111;
        custoBi       = 111111;
        bitsMvBi      = 111111;
        SMVD          = 111111;
        interDir      = 111111;
        atualQP       = 111111; 
        /*
        affinePai     = 111111;
        custoPai    = 111111;
        IMV_Pai = 111111;  
        affineVizEsq  = 111111;
        affineVizEsq_1 = 111111;
        custoVizEsq = 111111;
        IMV_VizEsq= 111111;   
        affineVizAci  = 111111;
        affineVizAci_1 = 111111;
        custoVizAci= 111111;
        IMV_VizAci= 111111;   
        cuAtualAffine = 111111;   
        affCustoMvUniL0 = 111111;
        affCustoMvUniL1 = 111111;
        affCustoMvUniL0_1 = 111111;
        affCustoMvUniL1_1 = 111111;      
        affCustoMvBi = 111111;    
        affMvUniL0P0HorX = 111111;
        affMvUniL0P0VerY = 111111;
        affMvUniL0P1HorX = 111111;
        affMvUniL0P1VerY = 111111;           
        affMvUniL1P0HorX = 111111;
        affMvUniL1P0VerY = 111111;
        affMvUniL1P1HorX = 111111;
        affMvUniL1P1VerY = 111111;    
        affMvPredUniL0P0HorX = 111111;
        affMvPredUniL0P0VerY = 111111;
        affMvPredUniL0P1HorX = 111111;
        affMvPredUniL0P1VerY = 111111;    
        affMvPredUniL1P0HorX = 111111;
        affMvPredUniL1P0VerY = 111111;
        affMvPredUniL1P1HorX = 111111;
        affMvPredUniL1P1VerY = 111111;   
        affMvBiL0P0HorX = 111111;
        affMvBiL0P0VerY = 111111;
        affMvBiL0P1HorX = 111111;
        affMvBiL0P1VerY = 111111;   
        affMvBiL1P0HorX = 111111;
        affMvBiL1P0VerY = 111111;
        affMvBiL1P1HorX = 111111;
        affMvBiL1P1VerY = 111111;    
        affMvPredBiL0P0HorX = 111111;
        affMvPredBiL0P0VerY = 111111;
        affMvPredBiL0P1HorX = 111111;
        affMvPredBiL0P1VerY = 111111;
        affMvPredBiL1P0HorX = 111111;
        affMvPredBiL1P0VerY = 111111;
        affMvPredBiL1P1HorX = 111111;
        affMvPredBiL1P1VerY = 111111;   
        affbitsMvUniL0 = 111111;
        affBitsMvUniL1 = 111111;
        affBitsMvBi = 111111;
        affInterDir = 111111; 
        affTypePai = 111111;
        affTypeVizEsq = 111111;
        affTypeVizAci = 111111;
        cuAtualAffineType = 111111;
        */
        rui_SAD = 111111;
        cStruct_iBestX = 111111;
        cStruct_iBestY = 111111;
        executaTZS = 111111;
    }
#endif

void extracaoDados::criarArquivo(){

#if EXTRA_TEMPOS
    //arqTempos.open("/home/rgsviana/VTM/ExtracaoDados/" +nameVideo + "_QP_" + to_string(numQp) +"_nFrames_"+ to_string(numFrames) +"_tempos.csv", ios::app);
    arqTempos.open("ExtracaoDados/" +nameVideo + "_QP_" + to_string(numQp) +"_nFrames_"+ to_string(numFrames) +"_tempos.csv", ios::app);
    arqTempos << "Função;TempoClock"<<endl;
#endif    
    
#if EXTRA_FEATURES
    
    //arqFeatures.open("/home/rgsviana/VTM/ExtracaoDados/" +nameVideo + "_QP_" + to_string(numQp) +"_nFrames_"+ to_string(numFrames) +"_features.csv", ios::app);
    arqFeatures.open("ExtracaoDados/" +nameVideo + "_QP_" + to_string(numQp) +"_nFrames_"+ to_string(numFrames) +"_features.csv", ios::app);
    arqFeatures <<
                    //"poc;"
                    "qp;"
                    "depth;"
                    "qt_depht;"
                    "mt_depth;"
                    "video_width;"
                    "video_heigh;"
                    "cu_pos_x;"
                    "cu_pos_y;"
                    "cu_width;"
                    "cu_height;"
                    //"modo_split;"
                    "bcw_index;"
                    "imv;"            
                    "mv_uni_l0_hor_x;"
                    "mv_uni_l0_ver_y;"
                    "mv_uni_l1_hor_x;"
                    "mv_uni_l1_ver_y;"           
                    //"mv_pred_uni_l0_hor_x;"
                    //"mv_pred_uni_l0_ver_y;"
                    //"mv_pred_uni_l1_hor_x;"
                    //"mv_pred_uni_l1_ver_y;"            
                    "cost_mv_uni_l0;"
                    "cost_mv_uni_l1;"
                    //"cost_mv_uni_l0_1;"
                    //"cost_mv_uni_l1_1;"            
                    "bits_mv_uni_l0;"
                    "bits_mv_uni_l1;"            
                    "mv_bi_l0_hor_x;"
                    "mv_bi_l0_ver_y;"
                    "mv_bi_l1_hor_x;"
                    "mv_bi_l1_ver_y;"           
                    //"mv_pred_bi_l0_hor_x;"
                    //"mv_pred_bi_l0_ver_y;"
                    //"mv_pred_bi_l1_hor_x;"
                    //"mv_pred_bi_l1_ver_y;"                       
                    "cost_bi;"
                    "bits_mv_bi;"
                    "smvd;"
                    "inter_dir_normal;"
                    "atual_QP;"         
                    /*
                    "affine_pai;"
                    "custo_pai;"
                    "imv_pai;"           
                    "aff_viz_esq;"
                    "aff_viz_esq_1;"
                    "custo_viz_esq;"
                    "IMV_viz_esq;"            
                    "aff_viz_acima;"
                    "aff_viz_acima_1;"
                    "custo_viz_aci;"
                    "IMV_viz_aci;"            
                    "cu_atual_affine;"            
                    "aff_cost_mv_uni_l0;"
                    "aff_cost_mv_uni_l1;"
                    "aff_cost_mv_uni_l0_1;"
                    "aff_cost_mv_uni_l1_1;"            
                    "aff_cost_mv_bi;"            
                    "aff_mv_uni_l0p0_hor_x;"
                    "aff_mv_uni_l0p0_ver_y;"
                    "aff_mv_uni_l0p1_hor_x;"
                    "aff_mv_uni_l0p1_ver_y;"            
                    "aff_mv_uni_l1p0_hor_x;"
                    "aff_mv_uni_l1p0_ver_y;"
                    "aff_mv_uni_l1p1_hor_x;"
                    "aff_mv_uni_l1p1_ver_y;"           
                    "aff_mv_pred_uni_l0p0_hor_x;"
                    "aff_mv_pred_uni_l0p0_ver_y;"
                    "aff_mv_pred_uni_l0p1_hor_x;"
                    "aff_mv_pred_uni_l0p1_ver_y;"            
                    "aff_mv_pred_uni_l1p0_hor_x;"
                    "aff_mv_pred_uni_l1p0_ver_y;"
                    "aff_mv_pred_uni_l1p1_hor_x;"
                    "aff_mv_pred_uni_l1p1_ver_y;"            
                    "aff_mv_bi_l0p0_hor_x;"
                    "aff_mv_bi_l0p0_ver_y;"
                    "aff_mv_bi_l0p1_hor_x;"
                    "aff_mv_bi_l0p1_ver_y;"            
                    "aff_mv_bi_l1p0_hor_x;"
                    "aff_mv_bi_l1p0_ver_y;"
                    "aff_mv_bi_l1p1_hor_x;"
                    "aff_mv_bi_l1p1_ver_y;"           
                    "aff_mv_pred_bi_l0p0_hor_x;"
                    "aff_mv_pred_bi_l0p0_ver_y;"
                    "aff_mv_pred_bi_l0p1_hor_x;"
                    "aff_mv_pred_bi_l0p1_ver_y;"           
                    "aff_mv_pred_bi_l1p0_hor_x;"
                    "aff_mv_pred_bi_l1p0_ver_y;"
                    "aff_mv_pred_bi_l1p1_hor_x;"
                    "aff_mv_pred_bi_l1p1_ver_y;"            
                    "aff_bits_mv_uni_l0;"
                    "aff_bits_mv_uni_l1;"
                    "aff_bits_mv_bi;"
                    "aff_inter_dir;"            
                    "aff_type_pai;"            
                    "aff_type_viz_esq;"            
                    "aff_type_viz_aci;"                       
                    "cu_atual_aff_type;"
                    */
                    "rui_SAD;"
                    "cStruct_iBestX;"
                    "cStruct_iBestY;"
                    "executaTZS"
                    <<endl;
#endif
    
}    
    
extracaoDados::extracaoDados(string _nameVideo, int _numQP,int _numFrames, int _widthVideo, int _heightVideo) {
    
    nameVideo    = _nameVideo;
    numQp        = _numQP;
    numFrames    = _numFrames;
    widthVideo   = _widthVideo;
    heightVideo  = _heightVideo;
    criarArquivo();
}


void extracaoDados::registraTempo(string _funcao, float _tempoClock){
    arqTempos << _funcao <<";"<< convertePontoVirgula(to_string(_tempoClock))<<endl;
}

string extracaoDados::convertePontoVirgula(string _valor){  
    string valor=_valor;
    valor.replace(valor.rfind("."),1,",");
    return valor;   
}

void extracaoDados::resgistraDadosBlocos(string _nomeFuncao, map<string,long int>_mapTamBlocos, map<string,long int>_mapTemBlocos, int _totalNumBlocos, float _totalTemBlocos, string _tamanhosCU[], int _tamVetor){
    
    arqBlocos << "Contagem Blocos função:;"<<_nomeFuncao<<endl;
    arqBlocos << "Tam. Bloco;Nº Blocos;Tempo (seg)"<<endl;
    
    for(int i=0;i<_tamVetor;i++){
        arqBlocos << _tamanhosCU[i]<<";"<<_mapTamBlocos[_tamanhosCU[i]]<<";"<<convertePontoVirgula(to_string(_mapTemBlocos[_tamanhosCU[i]] * 1.0 / CLOCKS_PER_SEC)) <<endl;
    }
    
    arqBlocos <<"Total Blocos "<<_nomeFuncao<<";"<< _totalNumBlocos <<";"<<convertePontoVirgula(to_string(_totalTemBlocos * 1.0 / CLOCKS_PER_SEC))<<endl; 
    arqBlocos <<endl<<endl;
}
/*
//RAMIRO
void extracaoDados::salvaBlocosEscolhidos(CodingStructure *&bestCS){
    
    for(int i=0; i<bestCS->cus.size();i++){
        
       arqblocosEscolidos<<bestCS->cus[i]->lx()<<
               ";"<<bestCS->cus[i]->ly()<<
               ";"<<bestCS->cus[i]->lwidth()<<
               ";"<<bestCS->cus[i]->lheight()<<
               ";"<< bestCS->cus[i]->affine<<
               ";"<<bestCS->cus[i]->affineType<<
               ";"<<((int)bestCS->cus[i]->imv)<<
               ";"<<(int)bestCS->cus[i]->BcwIdx<<
               ";"<<(int)bestCS->cus[i]->firstPU->mergeFlag <<
               ";"<<(int)bestCS->cus[i]->firstPU->regularMergeFlag<<
               ";"<<(int)bestCS->cus[i]->geoFlag<<
               ";"<<(int)bestCS->cus[i]->firstPU->ciipFlag <<
               ";"<<(int)bestCS->cus[i]->firstPU->mmvdMergeFlag<<
               ";"<<(int)bestCS->cus[i]->firstPU->interDir<<
               ";"<<(int)bestCS->slice->getPOC()<<
               ";"<<(int)bestCS->cus[i]->predMode<<endl;
    }
}
*/

extracaoDados::~extracaoDados() {
}

