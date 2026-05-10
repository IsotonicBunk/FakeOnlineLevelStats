// i hate c++

#include <Geode/ui/GeodeUI.hpp>
#include "Geode/cocos/cocoa/CCGeometry.h"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/label_nodes/CCLabelBMFont.h"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/cocos/support/CCPointExtension.h"
#include "Geode/loader/Log.hpp"
#include "Geode/ui/Notification.hpp"
#include <Geode/Geode.hpp>
#include <Geode/binding/ButtonSprite.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <string>
using namespace geode::prelude;

#include <Geode/modify/LevelInfoLayer.hpp>




class $modify(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod, LevelInfoLayer) {
	
	public:
		void openSettings(CCObject* sender) {
			openSettingsPopup(Mod::get());
		};
		auto replaceLabel(auto origLabel, auto newLabel) {
		this->addChild(newLabel);
		newLabel->setID(origLabel->getID());
		auto pos = origLabel->getPosition();
		auto scale = origLabel->getScale();
		auto anchor = origLabel->getAnchorPoint();
		newLabel->setPosition(pos);
		newLabel->setScale(scale);
		newLabel->setAnchorPoint(anchor);
		this->removeChildByID(origLabel->getID());
	}
	
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
			leftMenu->updateLayout();
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
		if (!orig_downloads) {
			log::error("Failed to get downloads label");
			Notification::create("Failed to get downloads label!", NotificationIcon::Error, 3);
			return true;
		}
		auto fake_downloads = CCLabelBMFont::create(downloads.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		replaceLabel(orig_downloads, fake_downloads);

		// likes
		auto orig_likes = this->getChildByID("likes-label");
		if (!orig_likes) {
			log::error("Failed to get likes label!");
			Notification::create("Failed to get likes label!", NotificationIcon::Error, 3);
			return true;
		}
		auto fake_likes = CCLabelBMFont::create(likes.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		replaceLabel(orig_likes, fake_likes);

		// length
		auto orig_length = this->getChildByID("length-label");
		if (!orig_length) {
			log::error("Failed to get length label!");
			Notification::create("Failed to get length label!", NotificationIcon::Error, 3);
			return true;
		}
		auto fake_length = CCLabelBMFont::create(length.c_str(), "bigFont.fnt", 999, CCTextAlignment::kCCTextAlignmentLeft);
		replaceLabel(orig_length, fake_length);
		if (fix_length_pos) fake_length->setAnchorPoint(ccp(0, 0.25));

		//set (dis)like icon
		auto orig_like_icon = this->getChildByID("likes-icon");
		if (!orig_like_icon) {
			log::error("Failed to get (dis)like icon!");
			Notification::create("Failed to get (dis)like icon!", NotificationIcon::Error, 3);
			return true;
		}
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

		
		return true;
	}
	
};