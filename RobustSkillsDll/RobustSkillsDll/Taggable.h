#pragma once

namespace robustskills {
    namespace core {

        class Taggable {
        public:
            Taggable() {};
            virtual ~Taggable() = 0;

            typedef const char* Tag;

            virtual void addTag(Tag&&) = 0;
            virtual void removeTag(Tag&&) = 0;
            virtual void hasTag(Tag&&) = 0;
        };
    }
}