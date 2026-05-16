// i hate c++
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

// formats numbers (1234567 to 1,234,567)
std::string getStatText(int num) {
    std::string res = utils::numToString(num);

    int insertPos = res.length() - 3;
    while (insertPos > 0) {
        res.insert(insertPos, ",");
        insertPos -= 3;
    }

    return res;
}

class $modify(MyLevelInfoLayerOrSomethingIReallyDontKnowHowToNameThisLayerOrNodeIDontKnowBruhSorryForModeratorThatVerifyingThisMod, LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) 
			return false;
		
		// settings button
		auto fakeStat = CCMenuItemExt::createSpriteExtra(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			[this](auto) { openSettingsPopup(Mod::get()); }
		);
		
		// add to menu
		auto leftMenu = this->getChildByID("left-side-menu");
		if (leftMenu && Mod::get()->getSettingValue<bool>("show-btn")) {
			leftMenu->addChild(fakeStat);
			fakeStat->setID("fake-stats-button"_spr);
			fakeStat->setOpacity(99);
			leftMenu->updateLayout();
		}
		
		// if enabled	
		auto enabled = Mod::get()->getSettingValue<bool>("enabled");
		if (!enabled) return true;

		// downloads
		if (Mod::get()->getSettingValue<bool>("change-downloads")) {
			auto downloads = getStatText(Mod::get()->getSettingValue<int>("downloads"));
			this->m_downloadsLabel->setString(downloads.c_str());
			this->m_downloadsLabel->limitLabelWidth(50.f, 0.5f, 0.1f);
		}

		// likes
		if (Mod::get()->getSettingValue<bool>("change-likes")) {
			auto likes = getStatText(Mod::get()->getSettingValue<int>("likes"));
			this->m_likesLabel->setString(likes.c_str());
			this->m_likesLabel->limitLabelWidth(50.f, 0.5f, 0.1f);
		}

		// length
		if (Mod::get()->getSettingValue<bool>("change-length")) {
			auto length = Mod::get()->getSettingValue<std::string>("length");
			this->m_lengthLabel->setString(length.c_str());
			this->m_lengthLabel->setAnchorPoint(ccp(0, 0.25));
		}

		//set (dis)like icon
		if (Mod::get()->getSettingValue<bool>("change-is-dislike")) {
			auto is_dislike = Mod::get()->getSettingValue<bool>("is-dislike");
			auto likeSprName = is_dislike ? "GJ_dislikesIcon_001.png" : "GJ_likesIcon_001.png";
			auto likeSpr = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(likeSprName);
			this->m_likesIcon->setDisplayFrame(likeSpr);
		}

		return true;
	}
};