//RAMIRO - VTM 16.2 - Otimização Inter-Quadros - Extração Features TZS

#ifndef EXTRACAODADOS_H
#define EXTRACAODADOS_H

#include <fstream>
#include <string.h>
#include <map>
#include "EncoderLib/InterSearch.h"

using namespace std;

class extracaoDados {
public:
    

    static ofstream arqTempos;
    static ofstream arqBlocos;
    static ofstream arqblocosEscolidos;

    /*Variáveis EncAppCfg.cpp*/
    static string nameVideo;
    static int numQp;
    static int numFrames;
    static int widthVideo;
    static int heightVideo;
    static float tempoClock;
    static float tempoTime;
    
    /*Variáveis controle*/
    static int flagBDOFInter;
    static int flagBDOFmerge;

#if EXTRA_FEATURES
    static ofstream arqFeatures;
    
    //variáveis features
    static int POC;
    static int QP;
    static int depth;
    static int qtDepth;
    static int mtDepht;
    static int videoWidth;
    static int videoHeight;
    static int cuPosX;
    static int cuPosY;
    static int cuWidth;
    static int cuHeight;
    static int bcwIndex;
    static int IMV;
    static int mvUniL0HorX;
    static int mvUniL0VerY;
    static int mvUniL1HorX;
    static int mvUniL1VerY;
    static int mvPredUniL0HorX;
    static int mvPredUniL0VerY;
    static int mvPredUniL1HorX;
    static int mvPredUniL1VerY;  
    static uint64_t custoMvUniL0;
    static uint64_t custoMvUniL1;
    static uint64_t custoMvUniL0_1;
    static uint64_t custoMvUniL1_1;   
    static int bitsMvUniL0;
    static int bitsMvUniL1;  
    static int mvBiL0HorX;
    static int mvBiL0VerY;
    static int mvBiL1HorX;
    static int mvBiL1VerY;   
    static int mvPredBiL0HorX;
    static int mvPredBiL0VerY;
    static int mvPredBiL1HorX;
    static int mvPredBiL1VerY;   
    static uint64_t custoBi;
    static int bitsMvBi;
    static int SMVD;
    static int interDir;
    static int atualQP;   
    static int affinePai;
    static uint64_t custoPai;
    static int IMV_Pai;   
    static int affineVizEsq;
    static int affineVizEsq_1;
    static uint64_t custoVizEsq;
    static int IMV_VizEsq;  
    static int affineVizAci;
    static int affineVizAci_1;
    static uint64_t custoVizAci;
    static int IMV_VizAci;  
    static int cuAtualAffine;  
    static uint64_t affCustoMvUniL0;
    static uint64_t affCustoMvUniL1;
    static uint64_t affCustoMvUniL0_1;
    static uint64_t affCustoMvUniL1_1;        
    static uint64_t affCustoMvBi;   
    static int affMvUniL0P0HorX;
    static int affMvUniL0P0VerY;
    static int affMvUniL0P1HorX;
    static int affMvUniL0P1VerY;  
    static int affMvUniL1P0HorX;
    static int affMvUniL1P0VerY;
    static int affMvUniL1P1HorX;
    static int affMvUniL1P1VerY;   
    static int affMvPredUniL0P0HorX;
    static int affMvPredUniL0P0VerY;
    static int affMvPredUniL0P1HorX;
    static int affMvPredUniL0P1VerY;   
    static int affMvPredUniL1P0HorX;
    static int affMvPredUniL1P0VerY;
    static int affMvPredUniL1P1HorX;
    static int affMvPredUniL1P1VerY;  
    static int affMvBiL0P0HorX;
    static int affMvBiL0P0VerY;
    static int affMvBiL0P1HorX;
    static int affMvBiL0P1VerY;  
    static int affMvBiL1P0HorX;
    static int affMvBiL1P0VerY;
    static int affMvBiL1P1HorX;
    static int affMvBiL1P1VerY;  
    static int affMvPredBiL0P0HorX;
    static int affMvPredBiL0P0VerY;
    static int affMvPredBiL0P1HorX;
    static int affMvPredBiL0P1VerY;    
    static int affMvPredBiL1P0HorX;
    static int affMvPredBiL1P0VerY;
    static int affMvPredBiL1P1HorX;
    static int affMvPredBiL1P1VerY;  
    static int affbitsMvUniL0;
    static int affBitsMvUniL1;
    static int affBitsMvBi;  
    static int affInterDir;  
    static int affTypePai;  
    static int affTypeVizEsq;   
    static int affTypeVizAci;   
    static int cuAtualAffineType;  
    static int rui_SAD;  
    static int cStruct_iBestX;  
    static int cStruct_iBestY;  
    static int executaTZS;
    static int modoSplit;
    static int modoSplit_temp;
    //fim variáveis features

    //funções fetures
    static void setPOC(int _POC);
    static void setQP(int _QP);
    static void setDepth(int _depth);
    static void setQtDepth(int _qtDepth);
    static void setMtDepht(int _mtDepth);
    static void setVideoWidth(int _videoWidth);
    static void setVideoHeight(int _videoHeight);
    static void setCuPosX(int _cuPosX);
    static void setCuPosY(int _cuPosY);
    static void setCuWidth(int _cuWidth);
    static void setCuHeight(int _cuHeight);
    static void setBcwIndex(int _bcwIndex);
    static void setIMV(int _imv);   
    static void setMvUniL0HorX(int _mvUniL0HorX);
    static void setMvUniL0VerY(int _mvUniL0VerY);
    static void setMvUniL1HorX(int _mvUniL1HorX);
    static void setMvUniL1VerY(int _mvUniL1VerY);    
    static void setMvPredUniL0HorX(int _mvPredUniL0HorX);
    static void setMvPredUniL0VerY(int _mvPredUniL0VerY);
    static void setMvPredUniL1HorX(int _mvPredUniL1HorX);
    static void setMvPredUniL1VerY(int _mvPredUniL1VerY);       
    static void setCustoMvUniL0(uint64_t _custoMvUniL0);
    static void setCustoMvUniL1(uint64_t _custoMvUniL1);
    static void setCustoMvUniL0_1(uint64_t _custoMvUniL0_1);
    static void setCustoMvUniL1_1(uint64_t _custoMvUniL1_1);      
    static void setBitsMvUniL0(int _bitsMvUniL0);
    static void setBitsMvUniL1(int _bitsMvUniL1);   
    static void setMvBiL0HorX(int _mvBiL0HorX);
    static void setMvBiL0VerY(int _mvBiL0VerY);
    static void setMvBiL1HorX(int _mvBiL1HorX);
    static void setMvBiL1VerY(int _mvBiL1VerY); 
    static void setMvPredBiL0HorX(int _mvPredBiL0HorX);
    static void setMvPredBiL0VerY(int _mvPredBiL0VerY);
    static void setMvPredBiL1HorX(int _mvPredBiL1HorX);
    static void setMvPredBiL1VerY(int _mvPredBiL1VerY);    
    static void setCustoBi(uint64_t _custoBi);
    static void setBitsMvBi(int _bitsMvBi);
    static void setSMVD(int _SMVD);
    static void setInterDir(int _interDir);
    static void setAtualQP(int _atualQP);
    static void setAffinePai(int _affinePai);
    static void setCustoPai(uint64_t custoPai);
    static void setIMV_Pai(int _IMV_Pai);
    static void setAffineVizEsq(int _affineVizEsq);
    static void setAffineVizEsq_1(int _affineVizEsq_1);
    static void setCustoVizEsq(uint64_t _custoVizEsq);
    static void setIMV_VizEsq(int _IMV_VizEsq);   
    static void setAffineVizAci(int _affineVizAci);
    static void setAffineVizAci_1(int _affineVizAci_1);
    static void setCustoVizAci(uint64_t _custoVizAci);
    static void setIMV_VizAci(int _IMV_VizAci);    
    static void setCuAtualAffine(int _cuAtualAffine);   
    static void setAffCustoMvUniL0(uint64_t _affCustoMvUniL0);
    static void setAffCustoMvUniL1(uint64_t _affCustoMvUniL1);
    static void setAffCustoMvUniL0_1(uint64_t _affCustoMvUniL0_1);
    static void setAffCustoMvUniL1_1(uint64_t _affCustoMvUniL1_1);    
    static void setAffCustoMvBi(uint64_t _affCustoMvBi);    
    static void setAffMvUniL0P0HorX(int _affMvUniL0P0HorX);
    static void setAffMvUniL0P0VerY(int _affMvUniL0P0VerY);
    static void setAffMvUniL0P1HorX(int _affMvUniL0P1HorX);
    static void setAffMvUniL0P1VerY(int _affMvUniL0P1VerY);   
    static void setAffMvUniL1P0HorX(int _affMvUniL1P0HorX);
    static void setAffMvUniL1P0VerY(int _affMvUniL1P0VerY);
    static void setAffMvUniL1P1HorX(int _affMvUniL1P1HorX);
    static void setAffMvUniL1P1VerY(int _affMvUniL1P1VerY);     
    static void setAffMvPredUniL0P0HorX(int _affMvPredUniL0P0HorX);
    static void setAffMvPredUniL0P0VerY(int _affMvPredUniL0P0VerY);
    static void setAffMvPredUniL0P1HorX(int _affMvPredUniL0P1HorX);
    static void setAffMvPredUniL0P1VerY(int _affMvPredUniL0P1VerY);   
    static void setAffMvPredUniL1P0HorX(int _affMvPredUniL1P0HorX);
    static void setAffMvPredUniL1P0VerY(int _affMvPredUniL1P0VerY);
    static void setAffMvPredUniL1P1HorX(int _affMvPredUniL1P1HorX);
    static void setAffMvPredUniL1P1VerY(int _affMvPredUniL1P1VerY);     
    static void setAffMvBiL0P0HorX(int _affMvBiL0P0HorX);
    static void setAffMvBiL0P0VerY(int _affMvBiL0P0VerY);
    static void setAffMvBiL0P1HorX(int _affMvBiL0P1HorX);
    static void setAffMvBiL0P1VerY(int _affMvBiL0P1VerY);    
    static void setAffMvBiL1P0HorX(int _affMvBiL1P0HorX);
    static void setAffMvBiL1P0VerY(int _affMvBiL1P0VerY);
    static void setAffMvBiL1P1HorX(int _affMvBiL1P1HorX);
    static void setAffMvBiL1P1VerY(int _affMvBiL1P1VerY);    
    static void setAffMvPredBiL0P0HorX(int _affMvPredBiL0P0HorX);
    static void setAffMvPredBiL0P0VerY(int _affMvPredBiL0P0VerY);
    static void setAffMvPredBiL0P1HorX(int _affMvPredBiL0P1HorX);
    static void setAffMvPredBiL0P1VerY(int _affMvPredBiL0P1VerY);   
    static void setAffMvPredBiL1P0HorX(int _affMvPredBiL1P0HorX);
    static void setAffMvPredBiL1P0VerY(int _affMvPredBiL1P0VerY);
    static void setAffMvPredBiL1P1HorX(int _affMvPredBiL1P1HorX);
    static void setaffMvPredBiL1P1VerY(int _affMvPredBiL1P1VerY);    
    static void setAffbitsMvUniL0(int _affbitsMvUniL0);
    static void setAffBitsMvUniL1(int _affBitsMvUniL1);
    static void setAffBitsMvBi(int _affBitsMvBi);    
    static void setAffInterDir(int _affInterDir);   
    static void setAffTypePai(int _affTypePai);
    static void setAffTypeVizEsq(int _affTypeVizEsq);  
    static void setAffTypeVizAci(int _affTypeVizAci);
    static void setCuAtualAffineType(int _cuAtualAffineType);   
    static void setrui_SAD(int _rui_SAD);   
    static void setcStruct_iBestX(int _cStruct_iBestX);   
    static void setcStruct_iBestY(int _cStruct_iBestY);  
    static void setexecutaTZS(int _executaTZS);
    static void setModoSplit(int _modoSplit);
    static void setModoSplit_temp();  
    static void registraFeatures();
    static void inicializaFeatures();
    //fim funções features    
    
#endif
    
    extracaoDados(string _nameVideo, int _numQP,int _numFrames, int _widthVideo, int _heightVideo);
    static void criarArquivo();

    static void registraTempo(string _funcao, float _tempoClock); 

    static void resgistraDadosBlocos(string _nomeFuncao, map<string,long int>_mapTamBlocos, map<string,long int>_mapTemBlocos, int _totalNumBlocos, float _totalTemBlocos, string _tamanhosCU[], int _tamVetor);
    static string convertePontoVirgula(string _valor);
    static void salvaBlocosEscolhidos(CodingStructure *&bestCS);
    
    virtual ~extracaoDados();
private:

};

#endif /* EXTRACAODADOS_H */

