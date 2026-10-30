#include "Photo.h"

#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<utility>

Photo::Photo(const std::string& name, int width, int height, const int* pixels)
    :   name(name),
        width(width),
        height(height),
        pixels(nullptr)
{   
    this->pixels = new int[width * height];

    std::copy(pixels, pixels+width*height, this->pixels);

    std::cout<<"constructor called for: " << name << '\n';
}


//copyconstrutcor
Photo::Photo(const Photo& other)
    : name(other.name),
      width(other.width),
      height(other.height),
      pixels(new int[other.width * other.height])
{
    std::copy(other.pixels, other.pixels + width * height, pixels);

    std::cout << "copy constructor called for: " << name << '\n';
}

//moveconstructor
Photo::Photo(Photo&& other) noexcept
    : name(std::move(other.name)),
      width(other.width),
      height(other.height),
      pixels(other.pixels)
{
    other.pixels = nullptr;
    other.width = 0;
    other.height = 0;

    std::cout << "move constructor called for: " << name << '\n';
}

//copy assignment operator
Photo& Photo::operator=(const Photo& other)
{
    if (this != &other) {
        Photo temp(other);

        std::swap(name, temp.name);
        std::swap(width, temp.width);
        std::swap(height, temp.height);
        std::swap(pixels, temp.pixels);
    }

    return *this;
}

// Move assignment operator
Photo& Photo::operator=(Photo&& other) noexcept
{
    if (this != &other) {
        delete[] pixels;

        name = std::move(other.name);
        width = other.width;
        height = other.height;
        pixels = other.pixels;

        other.pixels = nullptr;
        other.width = 0;
        other.height = 0;
    }

    return *this;
}

// destructor
Photo::~Photo()
{
    delete[] pixels;

    std::cout << "destructor called for: " << name << '\n';
}

//show a photo
void Photo::print() const
{
    std::cout << "\nphoto: " << name << '\n';

    std::cout << "resolution: " << width << "x" << height << '\n';

    std::cout << "pixels:\n";

    for (int i = 0; i < width * height; i++) {
        std::cout << pixels[i] << " ";

        if ((i + 1) % width == 0) {
            std::cout << '\n';
        }
    }
}

//modify a pixel
void Photo::modifyPixel(int pos, int val)
{
    if (pos < 0 || pos >= getNrPixels()) {
        std::cout << "invalid position\n";
        return;
    }

    if (val < 0 || val> 255) {
        std::cout << "invalid value\n";
        return;
    }

    pixels[pos] = val;
}

//value of a pixel
int Photo::showPixel(int pos) const
{
    return pixels[pos];
}

//total nr of pixels
int Photo::getNrPixels() const
{
    return width* height;
}