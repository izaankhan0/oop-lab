#include<iostream>
#include<vector>
using namespace std;

class MediaFile{
    protected:
        string path;
        int size;
    public:
        MediaFile(string path, int size): path(path), size(size){}
        virtual void play() = 0;
        virtual void stop() = 0;
        virtual ~MediaFile(){}

};

class VisualMedia : virtual public MediaFile{
    public:
        VisualMedia(string path, int size): MediaFile(path, size){}
        void play() override{
            cout << "Displaying Visual Media..." << endl;
        }
        void stop() override{
            cout << "Stopping Display of Visual Media..." << endl;
        }
};

class AudioMedia : virtual public MediaFile{
    public:
        AudioMedia(string path, int size): MediaFile(path, size){}
        void play() override{
            cout << "Displaying Audio Media..." << endl;
        }
        void stop() override{
            cout << "Stopping Display of Audio Media..." << endl;
        }
};

class VideoFile: public VisualMedia, public AudioMedia{
    public:
        VideoFile(string path, int size):VisualMedia(path, size), AudioMedia(path, size), MediaFile(path, size){}
        void play() override{
            cout << "Playing Video File..." << endl;
        }
        void stop() override{
            cout << "Stopping Video File..." << endl;
        }
};

class ImageFile: public VisualMedia{
    public:
        ImageFile(string path, int size):VisualMedia(path, size), MediaFile(path, size){}
        void play() override{
            cout << "Playing Image File..." << endl;
        }
        void stop() override{
            cout << "Stopping Image File..." << endl;
        }
};

class AudioFile: public AudioMedia{
    public:
        AudioFile(string path, int size): AudioMedia(path, size), MediaFile(path, size){}
        void play() override{
            cout << "Playing Audio File..." << endl;
        }
        void stop() override{
            cout << "Stopping Audio File..." << endl;
        }
};

int main() {
    MediaFile* media1 = new VideoFile("movie.mp4", 700);
    MediaFile* media2 = new ImageFile("picture.jpg", 400);
    MediaFile* media3 = new AudioFile("song.mp3", 300);

    media1->play();
    media1->stop();
    media2->play();
    media2->stop();
    media3->play();
    media3->stop();

    delete media1;
    delete media2;
    delete media3;
    
    return 0;
}