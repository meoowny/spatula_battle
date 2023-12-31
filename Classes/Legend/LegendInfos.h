#pragma once
#include "Legend/BaseLegend.h"

//adc
class ApheliosInfo : public LegendInfo
{
public:
    ApheliosInfo()
    : LegendInfo("Aphelios", 580, 2, 70, 26, 30, 4) { }
    virtual const char* getCardPath() { return "Cards/card_hypnoshroom.png"; }
};

// TODO: createInfo 暂未改，仅为复制补贴的 Aphelios 的 createInfo
// 另外所有英雄默认贴图为豌豆射手，待修改
class CaitlynInfo :public LegendInfo
{
public:
    CaitlynInfo()
    : LegendInfo("Caitlyn", 480, 4, 62, 28, 30, 5) { }
    virtual const char* getCardPath() { return "Cards/card_cherrybomb.png"; }
};



class EzrealInfo :public LegendInfo
{
public:
    EzrealInfo()
    : LegendInfo("Ezreal", 600, 2, 60, 24, 30, 4) { }
    virtual const char* getCardPath() { return "Cards/card_iceshroom.png"; }
};

class LucianInfo :public LegendInfo
{
public:
    LucianInfo()
    : LegendInfo("Lucian", 641, 2, 60, 28, 30, 3) { }
    virtual const char* getCardPath() { return "Cards/card_chomper.png"; }
};



class Miss_FortuneInfo :public LegendInfo
{
public:
    Miss_FortuneInfo()
    : LegendInfo("Miss_Fortune", 640, 2, 52, 28, 30, 4) { }
    virtual const char* getCardPath() { return "Cards/card_jalapeno.png"; }
};



class GravesInfo :public LegendInfo
{
public:
    GravesInfo()
    : LegendInfo("Graves", 625, 2, 68, 33, 50, 3) { }
    virtual const char* getCardPath() { return "Cards/card_peashooter.png"; }
};



class VarusInfo :public LegendInfo
{
public:
    VarusInfo()
    : LegendInfo("Varus", 600, 2, 62, 27, 30, 4) { }
    virtual const char* getCardPath() { return "Cards/card_potatomine.png"; }
};



//ap

class KatarinaInfo :public LegendInfo
{
public:
    KatarinaInfo()
    : LegendInfo("Katarina", 672, 2, 58, 28, 10, 1) { }
    virtual const char* getCardPath() { return "Cards/card_puffshroom.png"; }
};



class AkaliInfo :public LegendInfo
{
public:
    AkaliInfo()
    : LegendInfo("Akali", 570, 2, 62, 23, 10, 4) { }
    virtual const char* getCardPath() { return "Cards/card_repeaterpea.png"; }
};



class AnnieInfo :public LegendInfo
{
public:
    AnnieInfo()
    : LegendInfo("Annie", 594, 2, 50, 19, 10, 4) { }
    virtual const char* getCardPath() { return "Cards/card_scaredyshroom.png"; }
};


class ViktorInfo :public LegendInfo
{
public:
    ViktorInfo()
    : LegendInfo("Viktor", 600, 2, 53, 23, 10, 4) { }
    virtual const char* getCardPath() { return "Cards/card_snowpea.png"; }
};


class SonaInfo :public LegendInfo
{
public:
    SonaInfo()
    : LegendInfo("Sona", 550, 2, 49, 26, 10, 4) { }
    virtual const char* getCardPath() { return "Cards/card_spikeweed.png"; }
};


class JhinInfo :public LegendInfo
{
public:
    JhinInfo()
    : LegendInfo("Jhin", 655, 2, 70, 24, 40, 4) { }
    virtual const char* getCardPath() { return "Cards/card_squash.png"; }
};


//打野

class ViegoInfo :public LegendInfo
{
public:
    ViegoInfo()
    : LegendInfo("Viego", 630, 2, 70, 34, 70, 1) { }
    virtual const char* getCardPath() { return "Cards/card_sunflower.png"; }
};


class QiyanaInfo :public LegendInfo
{
public:
    QiyanaInfo()
    : LegendInfo("Qiyana", 590, 2, 66, 28, 10, 1) { }
    virtual const char* getCardPath() { return "Cards/card_sunshroom.png"; }
};


class KaynInfo :public LegendInfo
{
public:
    KaynInfo()
    : LegendInfo("Kayn", 600, 2, 70, 28, 10, 1) { }
    virtual const char* getCardPath() { return "Cards/card_threepeashooter.png"; }
};


class Bel_VethInfo :public LegendInfo
{
public:
    Bel_VethInfo()
    : LegendInfo("Bel_Veth", 610, 2, 60, 32, 20, 1) { }
    virtual const char* getCardPath() { return "Cards/card_wallnut.png"; }
};


class EkkoInfo :public LegendInfo
{
public:
    EkkoInfo()
    : LegendInfo("Ekko", 655, 2, 58, 32, 10, 1) { }
};


//上单

class RivenInfo : public LegendInfo
{
public:
    RivenInfo()
    : LegendInfo("Riven", 630, 2, 64, 33, 10, 1) { }
};


class FioraInfo :public LegendInfo
{
public:
    FioraInfo()
    : LegendInfo("Fiora", 620, 2, 68, 33, 10, 1) { }
};


class CamilleInfo :public LegendInfo
{
public:
    CamilleInfo()
    : LegendInfo("Camille", 646, 2, 68, 33, 5, 1) { }
};


class IreliaInfo :public LegendInfo
{
public:
    IreliaInfo()
    : LegendInfo("Irelia", 590, 2, 65, 36, 10, 1) { }
};

class SettInfo :public LegendInfo
{
public:
    SettInfo()
    : LegendInfo("Sett", 670, 2, 60, 33, 10, 1) { }
};


class GanplankInfo :public LegendInfo
{
public:
    GanplankInfo()
    : LegendInfo("Ganplank", 600, 2, 64, 31, 10, 1) { }
};


//辅助

class ThreshInfo :public LegendInfo
{
public:
    ThreshInfo()
    : LegendInfo("Thresh", 1000, 2, 10, 31, 0, 3) { }
};


class Renata_GlascInfo :public LegendInfo
{
public:
    Renata_GlascInfo()
    : LegendInfo("Renta_Glasc", 700, 2, 10, 28, 20, 4) { }
};


class RakanInfo :public LegendInfo
{
public:
    RakanInfo()
    : LegendInfo("Rakan", 1000, 2, 10, 32, 10, 1) { }
};


class BardInfo :public LegendInfo
{
public:
    BardInfo()
    : LegendInfo("Bard", 1200, 2, 10, 34, 10, 4) { }
};


class NautilusInfo :public LegendInfo
{
public:
    NautilusInfo()
    : LegendInfo("Nautilus", 1600, 2, 5, 39, 10, 1) { }
};


class PykeInfo :public LegendInfo
{
public:
    PykeInfo()
    : LegendInfo("Pyke", 900, 2, 60, 45, 10, 1) { }
};

