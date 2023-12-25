/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "SetupScene.h"
#include"ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Setup::createScene()
{
    return Setup::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//  ʼ      
bool Setup::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //设置背景
    auto background = Sprite::create("setupSceneBackground.png");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.1);
    this->addChild(background);

    auto backLabel = Label::createWithTTF("Click here to goBack", "fonts/Marker Felt.ttf", 40);
    backLabel->setPosition(Vec2(origin.x + visibleSize.width * 0.1, origin.y + visibleSize.height * 0.95));
    backLabel->setTextColor(Color4B::YELLOW);
    this->addChild(backLabel);

    //音量大小提示
    auto volumeLabel = Label::createWithTTF("当前音量大小", "fonts/STHUPO.TTF", 30);
    volumeLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.8));
    volumeLabel->setTextColor(Color4B::YELLOW);
    volumeLabel->enableShadow();
    this->addChild(volumeLabel);

    //帧数大小提示
    // 中文支持暂时有问题，实验性质的 stringstream 暂时使用英文进行提示
    stringstream fpsPrompt;
    fpsPrompt << "Current FPS: "
        << static_cast<int>(1 / Director::getInstance()->getAnimationInterval() + 0.5f);
    auto fpsLabel = Label::createWithTTF(fpsPrompt.str(), "fonts/LXGWWenKaiGBScreenR.ttf", 30);
    //auto fpsLabel = Label::createWithTTF("֡当前帧数大小", "fonts/STHUPO.TTF", 30);
    fpsLabel->setName("fpsLabel");
    fpsLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.6));
    fpsLabel->setTextColor(Color4B::YELLOW);
    fpsLabel->enableShadow();
    this->addChild(fpsLabel);

    // 音量滑块
    auto volumeSlider = ui::Slider::create();
    volumeSlider->setName("volumeSlider");
    volumeSlider->loadBarTexture("slider_Back.png");
    volumeSlider->loadSlidBallTextures("sliderNode_Normal.png", "sliderNode_Press.png", "sliderNode_Disable.png");
    volumeSlider->loadProgressBarTexture("slider_PressBar.png");
    volumeSlider->setScale(3);
    volumeSlider->setPercent(static_cast<int>(CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume() * 50)); // Initial volume value
    volumeSlider->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.7));
    //volumeSlider->addEventListener(CC_CALLBACK_2(Setup::onVolumeChange, this));
    volumeSlider->addEventListener([&](Ref* sender, ui::Slider::EventType type) {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
            auto volumeSlider = dynamic_cast<ui::Slider*>(this->getChildByName("volumeSlider"));
            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
            int volume = volumeSlider->getPercent();
            audio->setEffectsVolume(volume / 100.0f);
            audio->setBackgroundMusicVolume(volume / 100.0f);
        }
        });
    this->addChild(volumeSlider);

    // 帧数滑块
    auto fpsSlider = ui::Slider::create();
    fpsSlider->setName("fpsSlider");
    fpsSlider->loadBarTexture("slider_Back.png");
    fpsSlider->loadSlidBallTextures("sliderNode_Normal.png", "sliderNode_Press.png", "sliderNode_Disable.png");
    fpsSlider->loadProgressBarTexture("slider_PressBar.png");
    fpsSlider->setScale(3);
    fpsSlider->setPercent(1.0f / Director::getInstance()->getAnimationInterval());  // 依据当前 FPS 值初始化滑块的显示值
    fpsSlider->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.5));
    //fpsSlider->addEventListener(CC_CALLBACK_2(Setup::onFpsChange, this));
    fpsSlider->addEventListener([&](Ref* sender, ui::Slider::EventType type) {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
			auto dir = Director::getInstance();
			auto visibleSize = Director::getInstance()->getVisibleSize();
			Vec2 origin = Director::getInstance()->getVisibleOrigin();

			auto fpsSlider = dynamic_cast<ui::Slider*>(this->getChildByName("fpsSlider"));
            int fpsValue = fpsSlider->getPercent();
            dir->setAnimationInterval(1.0 / fpsValue);

            auto originFpsLabel = dynamic_cast<Label*>(this->getChildByName("fpsLabel"));
            if (originFpsLabel != NULL) {
                auto dirs = dir->getRunningScene();
				dirs->removeChildByName("fpsLabel");
				stringstream fpsPrompt;
				fpsPrompt << "Current FPS: " << fpsValue;
				auto fpsLabel = Label::createWithTTF(fpsPrompt.str(), "fonts/LXGWWenKaiGBScreenR.ttf", 30);
				fpsLabel->setName("fpsLabel");
				fpsLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.6));
				fpsLabel->setTextColor(Color4B::YELLOW);
				dirs->addChild(fpsLabel);
			}
		}
		});
	this->addChild(fpsSlider);

	// 返回按钮
	auto backButton = ui::Button::create("backButton_Normal.png", "backButton_Selected.png");
	//backButton->setTitleText("Back");
    //backButton->setTitleColor(Color3B::BLACK);
    //backButton->setTitleFontSize(15);
    //backButton->setTitleFontName("fonts/LXGWWenKaiGBScreenR.ttf");
    //backButton->setTitleAlignment(TextHAlignment::LEFT, TextVAlignment::BOTTOM);
	backButton->setPosition(Vec2(origin.x + visibleSize.width * 0.1, origin.y + visibleSize.height * 0.9));
	backButton->addClickEventListener([&](Ref* sender) {
		Director::getInstance()->popScene();
		});
	backButton->setVisible(true);
	backButton->setScale(1.5);
	this->addChild(backButton);

	return true;
}

