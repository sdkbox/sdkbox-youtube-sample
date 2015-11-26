
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        var coinsLabel = cc.Label.createWithSystemFont("Hello Js", "Arial", 64);
        coinsLabel.setPosition(size.width/2, size.height/5);
        this.addChild(coinsLabel);

        cc.MenuItemFont.setFontName('arial');
        cc.MenuItemFont.setFontSize(32);

        var menu = new cc.Menu(
            new cc.MenuItemFont("Play Video", function() {
                console.log("Play Video");
                sdkbox.PluginYoutube.playVideo("cdgQpa1pUUE", 0, true, true);
            }),
            new cc.MenuItemFont("Play Play List", function() {
                console.log("Play Play List");
                sdkbox.PluginYoutube.playPlayList("7E952A67F31C58A3", 0, 0, true, true);
            }),
            new cc.MenuItemFont("Play Video List", function() {
                console.log("Play Video List");
                var v = ["cdgQpa1pUUE", "8aCYZ3gXfy8", "cdgQpa1pUUE"];
                sdkbox.PluginYoutube.playVideoList(v, 0, 0, true, true);
            })

            );
        menu.setPosition(size.width/2, size.height/2);
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);

        sdkbox.PluginYoutube.setListener({
            onPlayEnds: function  (played_ok) {
                console.log("Youtube play video: %s " + played_ok ? "ok" : "error");
            }
        });
        sdkbox.PluginYoutube.init();

        return true;
    },
    onClicked: function() {
        console.log("on click")
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

