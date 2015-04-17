#include "ControlLayer.h"
#include "Global.h"
USING_NS_CC;
bool ControlLayer::init()
{
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//建立
	is_lftBtnPressed = false;													//初始化方向键按下状态
	is_rgtBtnPressed = false;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UIPacked.plist","UIPacked.png");
	LeftBtn = CCSprite::createWithSpriteFrameName("DirectBtn.png");
	RightBtn = CCSprite::createWithSpriteFrameName("DirectBtn.png");
	LeftBtn->setFlipX(true);
	//两者的位置
	LeftBtn->setPosition(ccp(LftBtnPsnX,LftBtnPsnY));			//The position is from the header,Global
	RightBtn->setPosition(ccp(RgtBtnPsnX,RgtBtnPsnY));
	this->addChild(LeftBtn);
	this->addChild(RightBtn);
	//建立两个按钮
	CCMenuItemImage* JmpBtn = CCMenuItemImage::create(
		"JmpBtn.png","JmpBtn_P.png",this,
		menu_selector(ControlLayer::JmpBtnCallBack));
	CCMenuItemImage* AtkBtn = CCMenuItemImage::create(
		"AtkBtn.png","AtkBtn_P.png",this,
		menu_selector(ControlLayer::AtkBtnCallBack));
	//建立另外三个按钮
	CCMenuItemImage* ShieldBtn = CCMenuItemImage::create(
		"ShieldBtn.png","ShieldBtn_P.png",this,
		menu_selector(ControlLayer::ShieldBtnCallBack));
	CCMenuItemImage* ClockUPBtn = CCMenuItemImage::create(
		"ClockUPBtn.png","ClockUPBtn_P.png",this,
		menu_selector(ControlLayer::ClockUPBtnCallBack));
	CCMenuItemImage* CloakBtn = CCMenuItemImage::create(
		"CloakBtn.png","CloakBtn_P.png",this,
		menu_selector(ControlLayer::CloakBtnCallBack));
	CCMenuItemImage* BladeBtn = CCMenuItemImage::create(
		"BladeBtn.png","BladeBtn_P.png",this,
		menu_selector(ControlLayer::BladeBtnCallBack));
	JmpBtn->setPosition(ccp(JmpBtnPsnX,JmpBtnPsnY));
	AtkBtn->setPosition(ccp(AtkBtnPsnX,AtkBtnPsnY));

	ShieldBtn->setPosition(ccp(BladeBtnPsnX - 32,BladeBtnPsnY));
	ClockUPBtn->setPosition(ccp(BladeBtnPsnX + 32,BladeBtnPsnY));
	CloakBtn->setPosition(ccp(BladeBtnPsnX + 96,BladeBtnPsnY));
	BladeBtn->setPosition(ccp(BladeBtnPsnX + 128 + 32,BladeBtnPsnY));

	imageItemSide = CCSprite::createWithSpriteFrameName("ImageItemSide.png");
	imageItem = CCSprite::createWithSpriteFrameName("ImageNormal.png");
	hp_Bar = CCSprite::createWithSpriteFrameName("HP_Bar.png");
	sp_Bar = CCSprite::createWithSpriteFrameName("SP_Bar.png");
	tp_Bar = CCSprite::createWithSpriteFrameName("TP_Bar.png");
	imageItemSide->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	imageItem->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	hp_Bar->setAnchorPoint(ccp(0,0));
	sp_Bar->setAnchorPoint(ccp(0,0));
	tp_Bar->setAnchorPoint(ccp(0,0));
	hp_Bar->setPosition(ccp(64,360 - 30));
	sp_Bar->setPosition(ccp(64,360 - 41));
	tp_Bar->setPosition(ccp(64,360 - 53));
	this->addChild(imageItemSide,20);
	this->addChild(imageItem,15);
	this->addChild(hp_Bar,25);
	this->addChild(sp_Bar,25);
	this->addChild(tp_Bar,25);

	CCMenuItemImage* pauseBtn = CCMenuItemImage::create("PauseBtn.png","PauseBtn_P.png",this,menu_selector(ControlLayer::pauseBtnCallBack));
	pauseBtn->setPosition(ccp(590,360 - 43));

	CCMenu* pMenu = CCMenu::create(JmpBtn,AtkBtn,BladeBtn,ShieldBtn,CloakBtn,ClockUPBtn,pauseBtn,NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu);
	this->setTouchEnabled(true);		//开启触摸
	this->scheduleUpdate();

	return true;
}

void ControlLayer::JmpBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL||hero->getState() == WALKING)
	{
		hero->jump();
	}
}
void ControlLayer::AtkBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL||hero->getState() == WALKING)
	{
		hero->attack();
	}
}

void ControlLayer::update(float delta)
{
	if (is_lftBtnPressed == true)
	{
		if (hero->getState() == NORMAL || hero->getState() == WALKING)
		{
			hero->faceto = true;
			hero->setDirection(hero->faceto);												//面向翻转
			hero->run();
			if (hero->getPositionX() <= 0)
				hero->setPositionX(2);
			hero->initBlock();
		}
	}
	else if (is_rgtBtnPressed == true)
	{
		if (hero->getState() == NORMAL || hero->getState() == WALKING)
		{
			hero->faceto = false;
			hero->setDirection(hero->faceto);												//面向翻转
			hero->run();
			hero->initBlock();
		}
	}

	hp_Bar->setScaleX(hero->HP / 100.0f);
	sp_Bar->setScaleX(hero->SP / 100.0f);
	tp_Bar->setScaleX(hero->TP / 100.0f);

}

void ControlLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
	CCPoint	location=touch->getLocationInView();				//设置触控点
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);
	
	if (location.x>LftBtnPsnX - 32 && location.x < LftBtnPsnX + 32 && location.y  > LftBtnPsnY-32 && location.y<LftBtnPsnY +32)			//左按钮触发
	{
		is_lftBtnPressed = true;
		LeftBtn->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DirectBtn_P.png"));
		is_rgtBtnPressed = false;
	}
 	if (location.x>RgtBtnPsnX-32 && location.x<RgtBtnPsnX + 32 && location.y>RgtBtnPsnY-32 && location.y < RgtBtnPsnY + 32)			//右按钮触发
 	{
 		is_rgtBtnPressed = true;
		RightBtn->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DirectBtn_P.png"));
 		is_lftBtnPressed = false;
 	}
}
void ControlLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{}
void ControlLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
	CCPoint	location=touch->getLocationInView();				//设置触控点
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);

	if (((is_lftBtnPressed == true) || (is_rgtBtnPressed == true)) && hero->getState() == WALKING)
	{
		hero->velocityX = 0;
		if (!hero->inTheAir_flag)
		{
			hero->setState(NORMAL);
			if (hero->getMode() == LIGHTBLADE)
			{
				hero->m_sprite->getAnimation()->play("SB_Stand");
			}
			else
				hero->m_sprite->getAnimation()->play("Stand");
		}
		else
		{
			if (hero->getMode() == LIGHTBLADE)
			{
				hero->m_sprite->getAnimation()->play("SB_Stand");
			}
			else
				hero->m_sprite->getAnimation()->play("Stand");
		}
	}
	is_lftBtnPressed = false;
	is_rgtBtnPressed = false;
	LeftBtn->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DirectBtn.png"));
	RightBtn->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("DirectBtn.png"));
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
}
void ControlLayer::BladeBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL || hero->getState() == WALKING)
	{
		hero->handBlade();
		imageItem->setDisplayFrame(
			CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ImageNormal.png"));
		//hero->modeClockUp();
		//hero->modeIvisible();
	}
}
void ControlLayer::ShieldBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL || hero->getState() == WALKING)
	{
		//hero->handBlade();
		imageItem->setDisplayFrame(
			CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ImageNormal.png"));
		hero->modeShield();
		//hero->modeIvisible();
	}
}
void ControlLayer::CloakBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL || hero->getState() == WALKING)
	{
		//hero->handBlade();
		//hero->modeClockUp();
		imageItem->setDisplayFrame(
			CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ImageCloak.png"));
		hero->modeIvisible();
	}
}
void ControlLayer::ClockUPBtnCallBack(CCObject* pSender)
{
	if (hero->getState() == NORMAL || hero->getState() == WALKING)
	{
		//hero->handBlade();
		hero->modeClockUp();
		imageItem->setDisplayFrame(
			CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ImageSpeed.png"));
		//hero->modeIvisible();
	}
}
void ControlLayer::pauseBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(Scene::pauseLayer());
}