#include "TableViewTestScene.h"
#include "Scene.h"
USING_NS_CC;
USING_NS_CC_EXT;

// on "init" you need to initialize your instance
bool TableViewTestLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCTableView* tableView = CCTableView::create(this, winSize);
    tableView->setDirection(kCCScrollViewDirectionHorizontal);
    tableView->setPosition(ccp(0,winSize.height/2-50));
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();

    return true;
}

void TableViewTestLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLOG("cell touched at index: %i", cell->getIdx());
	switch (cell->getIdx())
	{
	case 0:
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.0f,Scene::lv01GameScene()));
		break;
	case 1:
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.0f,Scene::lv02GameScene()));
		break;
	case 2:
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.0f,Scene::lv03GameScene()));
		break;
	case 3:
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.0f,Scene::lv04GameScene()));
		break;
	default:
		CCDirector::sharedDirector()->replaceScene(Scene::storyEnd());
		break;
	}
}

CCSize TableViewTestLayer::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    //if (idx == 2) {
    //    return CCSizeMake(100, 100);
    //}
    return CCSizeMake(120, 120);
}

CCTableViewCell* TableViewTestLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCString *string = CCString::createWithFormat("%d", idx);
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        CCSprite *sprite = CCSprite::create("HelloWorld.png");
		sprite->setScale(0.2f);
        sprite->setPosition(ccp(60, 60));
		sprite->setTag(123);
        cell->addChild(sprite);
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Arial", 20.0);
        label->setPosition(ccp(60,10));
        label->setTag(456);
        cell->addChild(label);
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(456);
        label->setString(string->getCString());
    }
    return cell;
}

unsigned int TableViewTestLayer::numberOfCellsInTableView(CCTableView *table)
{
    return 4;
}