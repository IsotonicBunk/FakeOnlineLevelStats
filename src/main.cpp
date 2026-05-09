// i hate c++

#include <Geode/ui/GeodeUI.hpp>
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/cocos/support/CCPointExtension.h"
#include <Geode/Geode.hpp>
#include <Geode/binding/ButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <string>
#include <windef.h>
using namespace geode::prelude;

#include <Geode/modify/LevelInfoLayer.hpp>




class $modify(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod, LevelInfoLayer) {
	
	public:
		void openSettings(CCObject* sender) {
			openSettingsPopup(Mod::get());
		};
	
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;
		auto enabled = Mod::get()->getSettingValue<bool>("enabled");
		

		// settings button
		auto fakeStat = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod::openSettings)
		);
		auto leftMenu = this->getChildByID("left-side-menu");
		auto show_btn = Mod::get()->getSettingValue<bool>("show-btn");
		if (show_btn) {
			leftMenu->addChild(fakeStat);
			fakeStat->setID("fake-stats-button"_spr);
			fakeStat->setOpacity(99);
		}
		
		// if enabled
		if (!enabled) return true;

		// getting some vars from settings
		auto downloads = Mod::get()->getSettingValue<std::string>("downloads");
		auto likes = Mod::get()->getSettingValue<std::string>("likes");
		auto length = Mod::get()->getSettingValue<std::string>("length");
		auto is_dislike = Mod::get()->getSettingValue<bool>("is-dislike");
		auto fix_length_pos = Mod::get()->getSettingValue<bool>("fix-length-pos");
		
		// downloads
		auto orig_downloads = this->getChildByID("downloads-label");
		auto fake_downloads = CCLabelBMFont::create(downloads.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		orig_downloads->setVisible(false);
		this->addChild(fake_downloads);
		fake_downloads->setID("fake-downloads"_spr);
		auto downloads_pos = orig_downloads->getPosition();
		auto downloads_scale = orig_downloads->getScale();
		auto downloads_anchor = orig_downloads->getAnchorPoint();
		fake_downloads->setPosition(downloads_pos);
		fake_downloads->setScale(downloads_scale);
		fake_downloads->setAnchorPoint(downloads_anchor);

		// likes
		auto orig_likes = this->getChildByID("likes-label");
		auto fake_likes = CCLabelBMFont::create(likes.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		orig_likes->setVisible(false);
		this->addChild(fake_likes);
		fake_likes->setID("fake-likes"_spr);
		auto likes_pos = orig_likes->getPosition();
		auto likes_scale = orig_likes->getScale();
		auto likes_anchor = orig_likes->getAnchorPoint();
		fake_likes->setPosition(likes_pos);
		fake_likes->setScale(likes_scale);
		fake_likes->setAnchorPoint(likes_anchor);
		this->updateLayout();

		// length
		auto orig_length = this->getChildByID("length-label");
		auto fake_length = CCLabelBMFont::create(length.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		orig_length->setVisible(false);
		this->addChild(fake_length);
		fake_length->setID("fake-length"_spr);
		auto length_pos = orig_length->getPosition();
		auto length_scale = orig_length->getScale();
		auto length_anchor = orig_length->getAnchorPoint();
		fake_length->setPosition(length_pos);
		fake_length->setScale(length_scale);
		fake_length->setAnchorPoint(length_anchor);
		if (fix_length_pos) fake_length->setAnchorPoint(ccp(0, 0.25));

		//set (dis)like icon
		auto orig_like_icon = this->getChildByID("likes-icon");
		auto fake_like_icon = CCSprite::createWithSpriteFrameName("GJ_likesIcon_001.png");
		if (is_dislike) fake_like_icon = CCSprite::createWithSpriteFrameName("GJ_dislikesIcon_001.png");
		orig_like_icon->setVisible(false);
		this->addChild(fake_like_icon);
		auto like_icon_pos = orig_like_icon->getPosition();
		auto like_icon_scale = orig_like_icon->getScale();
		auto like_icon_anchor = orig_like_icon->getAnchorPoint();
		fake_like_icon->setPosition(like_icon_pos);
		fake_like_icon->setScale(like_icon_scale);
		fake_like_icon->setAnchorPoint(like_icon_anchor);

		
		this->updateLayout();
		return true;
	}
	
};