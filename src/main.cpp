// i hate c++
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod, LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;
		auto enabled = Mod::get()->getSettingValue<bool>("enabled");
		
		// settings button
		auto fakeStat = CCMenuItemExt::createSpriteExtra(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			[this](auto) { openSettingsPopup(Mod::get()); }
		);
		auto leftMenu = this->getChildByID("left-side-menu");
		if (auto show_btn = Mod::get()->getSettingValue<bool>("show-btn")) {
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
		auto downloads_scale_mod = Mod::get()->getSettingValue<float>("downloads-scale-mod");
		auto likes_scale_mod = Mod::get()->getSettingValue<float>("likes-scale-mod");

		// downloads
		m_downloadsLabel->setString(downloads.c_str());
		m_downloadsLabel->setScale(m_downloadsLabel->getScale() * downloads_scale_mod);

		// likes
		m_likesLabel->setString(likes.c_str());
		m_likesLabel->setScale(m_likesLabel->getScale() * likes_scale_mod);

		// length
		m_lengthLabel->setString(length.c_str());
		if (fix_length_pos) m_lengthLabel->setAnchorPoint(ccp(0, 0.25));

		//set (dis)like icon
		auto new_likes_icon = CCSpriteFrameCache::sharedSpriteFrameCache()
    		->spriteFrameByName(is_dislike ? "GJ_dislikesIcon_001.png" : "GJ_likesIcon_001.png");
		m_likesIcon->setDisplayFrame(new_likes_icon);
		
		return true;
	}
};