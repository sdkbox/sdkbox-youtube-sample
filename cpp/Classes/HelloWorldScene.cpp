#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto size = Director::getInstance()->getWinSize();
    MenuItemFont::setFontName("Arial");
    // ui
    {
        Menu* menu = Menu::create(
              MenuItemFont::create("Play Video", [](Ref*) {
                    log("click play video");
                    sdkbox::PluginYoutube::playVideo("cdgQpa1pUUE", 0, true, true);
                }),
              MenuItemFont::create("Play Play List", [](Ref*) {
                    log("click play play list");
                    sdkbox::PluginYoutube::playPlayList("7E952A67F31C58A3", 0, 0, true, true);
              }),
              MenuItemFont::create("Play Video List", [](Ref*) {
                    log("click play video list");
                    std::vector<std::string> v;
                    v.push_back( "cdgQpa1pUUE" );
                    v.push_back( "8aCYZ3gXfy8" );
                    v.push_back( "cdgQpa1pUUE" );
                  
                    sdkbox::PluginYoutube::playVideoList(v, 0, 0, true, true);
              }),
              NULL);
        menu->alignItemsVerticallyWithPadding(20);
        menu->setPosition(size.width/2, size.height/2);
        addChild(menu);

    }
    sdkbox::PluginYoutube::setListener(this);
    sdkbox::PluginYoutube::init();
    
    return true;
}

void HelloWorld::onPlayEnds( bool ok )
{
    CCLOG("Youtube play video: %s ", ok ? "ok" : "error");
}