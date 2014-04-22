#ifndef __MainWORLD_SCENE_H__
#define __MainWORLD_SCENE_H__

#include "cocos2d.h"

class MainWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCallback(CCObject* pSender);
    void menuGeorge(CCObject* pSender);
    void menuMatty(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(MainWorld);
};

#endif // __MainWORLD_SCENE_H__
