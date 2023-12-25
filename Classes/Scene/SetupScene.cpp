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
    auto background = Sprite::create("StartupSceneBackground.jpg");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.5);
    this->addChild(background);

    auto backLabel = Label::createWithTTF("Click here to goBack", "fonts/Marker Felt.ttf", 40);
    backLabel->setPosition(Vec2(origin.x + visibleSize.width * 0.1, origin.y + visibleSize.height * 0.95));
    backLabel->setTextColor(Color4B::YELLOW);
    this->addChild(backLabel);

    //音量大小提示
    auto volumeLabel = Label::createWithTTF("当前音量大小", "fonts/STHUPO.TTF", 30);
    volumeLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.8));
    volumeLabel->setTextColor(Color4B::YELLOW);
    this->addChild(volumeLabel);

    //帧数大小提示
    auto fpsLabel = Label::createWithTTF("֡当前帧数大小", "fonts/STHUPO.TTF", 30);
    fpsLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.6));
    fpsLabel->setTextColor(Color4B::YELLOW);
    this->addChild(fpsLabel);

    // 音量滑块
    auto volumeSlider = ui::Slider::create();
    volumeSlider->setName("volumeSlider");
    volumeSlider->loadBarTexture("sliderTrack.png");
    volumeSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    volumeSlider->loadProgressBarTexture("sliderProgress.png");
    volumeSlider->setPercent(static_cast<int>(CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume() * 50)); // Initial volume value
    volumeSlider->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.7));
    volumeSlider->addEventListener(CC_CALLBACK_2(Setup::onVolumeChange, this));
    this->addChild(volumeSlider);

    // 帧数滑块
    auto fpsSlider = ui::Slider::create();
    fpsSlider->setName("fpsSlider");
    fpsSlider->loadBarTexture("sliderTrack.png");
    fpsSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    fpsSlider->loadProgressBarTexture("sliderProgress.png");
	fpsSlider->setPercent(1.0f / Director::getInstance()->getAnimationInterval());  // 依据当前 FPS 值初始化滑块的显示值
    fpsSlider->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.5));
    fpsSlider->addEventListener(CC_CALLBACK_2(Setup::onFpsChange, this));
    this->addChild(fpsSlider);

    // 返回按钮
    auto backButton = ui::Button::create("backButton.png");
    backButton->setPosition(Vec2(origin.x + visibleSize.width * 0.1, origin.y + visibleSize.height * 0.9));
    backButton->addClickEventListener(CC_CALLBACK_1(Setup::onBackButtonClicked, this));
    backButton->setScale(1.5);
    this->addChild(backButton);

    return true;
}

void Setup::onVolumeChange(Ref* sender, ui::Slider::EventType type) {
    if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
        auto volumeSlider = dynamic_cast<ui::Slider*>(this->getChildByName("volumeSlider"));
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        int volume = volumeSlider->getPercent();
        audio->setEffectsVolume(volume / 100.0f);
        audio->setBackgroundMusicVolume(volume / 100.0f);
	}
}

void Setup::onFpsChange(Ref* sender, ui::Slider::EventType type) {
	if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
		auto fpsSlider = dynamic_cast<ui::Slider*>(this->getChildByName("fpsSlider"));
		int fpsValue = fpsSlider->getPercent();
		Director::getInstance()->setAnimationInterval(1.0 / fpsValue);
	}
}

void Setup::onBackButtonClicked(Ref* sender) {
	// Return to the previous scene
	Director::getInstance()->popScene();
}
