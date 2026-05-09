// this is old code. i tried to make menu for changing lvl stats but then i realised that i dont know how to do it
// so i make new version when you change lvl stats in mod settings
// yes, old idea was better

/*
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/menu_nodes/CCMenu.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include <Geode/Geode.hpp>
#include <Geode/binding/ButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelInfoLayer.hpp>




class $modify(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod, LevelInfoLayer) {
	
	public:
		void openFkStatMenu(CCObject* sender) {
			auto fkStatMenu = CCMenu::create();
			this->addChild(fkStatMenu);
			fkStatMenu->setID("fake-stats-menu"_spr);
			auto test_btn = CCMenuItemSpriteExtra::create(
				ButtonSprite::create("Hello World!"),
				this,
				nullptr
			);
			fkStatMenu->addChild(test_btn);
			//log::info("menu addedddd");
			
		} 

	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;
		
		

		auto fakeStat = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod::openFkStatMenu)
		);
		auto leftMenu = this->getChildByID("left-side-menu");
		leftMenu->addChild(fakeStat);
		fakeStat->setID("fake-stats-button"_spr);
		fakeStat->setOpacity(99);
		auto orig_downloads = this->getChildByID("downloads-label");
		auto fake_downloads = CCLabelBMFont::create("1337bruh", "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		orig_downloads->setVisible(false);
		this->addChild(fake_downloads);
		fake_downloads->setID("fake-downloads"_spr);
		auto downloads_pos = orig_downloads->getPosition();
		auto downloads_scale = orig_downloads->getScale();
		auto downloads_anchor = orig_downloads->getAnchorPoint();
		fake_downloads->setPosition(downloads_pos);
		fake_downloads->setScale(downloads_scale);
		fake_downloads->setAnchorPoint(downloads_anchor);
		this->updateLayout();
		return true;
	}
	
};*/