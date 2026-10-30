#ifndef PHOTO_H
#define PHOTO_H

#include <string>


class Photo{
private:
    std::string name;
    int width;
    int height;
    int* pixels;

public:
//constructor
    Photo(const std::string& name, int width, int height, const int* pixels);
//copyconstructor
    Photo(const Photo& other);
//moveconstructor
    Photo(Photo&& other) noexcept;
//copy assignment op
    Photo& operator=(const Photo& other);
//move assignment op
    Photo& operator=(Photo&& other) noexcept;
//destructor
    ~Photo();

    void print() const;
    void modifyPixel(int pos, int val);
    int showPixel(int pos) const;
    int getNrPixels() const;

};

#endif