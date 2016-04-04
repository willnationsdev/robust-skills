#pragma once

class Taggable {
public:
    Taggable() {};
    virtual ~Taggable() = 0;

    typedef char* Tag;

    virtual void addTag(const Tag) = 0;
    virtual void removeTag(const Tag) = 0;
    virtual void hasTag(const Tag) = 0;
};