#ifndef __GROUPLAYER_H_
#define __GROUPLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class GroupLayer : public CCLayer
{
public:
	bool init();

	void menuReturnCall(CCObject* pSender);
	CREATE_FUNC(GroupLayer);
};
#endif