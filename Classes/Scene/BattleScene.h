#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "BaseRoundScene.h"

class BattleScene : public BaseRoundScene
{
public:
    static Scene* createScene();
    virtual bool init();

 

    CREATE_FUNC(BattleScene);
};

#endif // __BATTLE_SCENE_H__