
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

-- MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()

	cc.MenuItemFont:setFontName("Arial")
    cc.Menu:create(
                   cc.MenuItemFont:create("Play Video"):onClicked(function()
                        print("Play Video")
                        sdkbox.PluginYoutube:playVideo("cdgQpa1pUUE", 0, true, true)
                    end),
                   cc.MenuItemFont:create("Play Play List"):onClicked(function()
                        print("Play Play List")
                        sdkbox.PluginYoutube:playPlayList("7E952A67F31C58A3", 0, 0, true, true)
                    end),
                   cc.MenuItemFont:create("Play Video List"):onClicked(function()
                        print("Play Video List")

                        local v = {"cdgQpa1pUUE", "8aCYZ3gXfy8", "cdgQpa1pUUE"}
                        sdkbox.PluginYoutube:playVideoList(v, 0, 0, true, true)
                    end)
                   )
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

    cc.Label:createWithSystemFont("Hello Lua", "Arial", 64)
    		:move(display.cx, display.height/5)
		    :addTo(self)

    sdkbox.PluginYoutube:setListener(function (event)
        dump(data)
        if event.name == "onPlayEnds" then
            print("Youtube play video: %s ", event.played_ok and "ok" or "error")
        end

    end)
    sdkbox.PluginYoutube:init()

    dump(sdkbox)
end

return MainScene
