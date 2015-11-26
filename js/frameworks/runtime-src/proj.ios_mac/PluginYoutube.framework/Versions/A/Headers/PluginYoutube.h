/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/
#ifndef _PLUGIN_YOUTUBE_H_
#define _PLUGIN_YOUTUBE_H_

#include <vector>
#include <map>
#include <string>

namespace sdkbox
{

    class YoutubeListener
    {
    public:
        virtual void onPlayEnds( bool played_ok ) = 0;
    };

    class PluginYoutube
    {

    public:

        static void init();
        static void setListener(YoutubeListener* listener);
        static YoutubeListener* getListener();

        static void removeListener();

        static void playVideo( const std::string& video_id, int startMillis, bool autoplay, bool lightbox );
        static void playPlayList( const std::string& playlist_id, int playListStartIndex, int startMillis, bool autoplay, bool lightbox );
        static void playVideoList( const std::vector<std::string>& video_ids, int playListStartIndex, int startMillis, bool autoplay, bool lightbox );
        
        static void close();
    };
}

#endif
