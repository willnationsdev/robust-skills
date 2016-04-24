#pragma once
#include <map>
#include <typeinfo>
#define quote(T) #T

namespace robustskills {
    namespace core {

        template <typename T>
        class Taggable {
        public:
            Taggable() {};
            virtual ~Taggable() = 0;

            typedef const char* Tag;

            virtual void addTag(Tag&& tag);
            virtual void removeTag(Tag&& tag);
            virtual bool hasTag(Tag&& tag);

        private:
            unsigned int id;
            static std::map<Tag,Tag> tags;
            static unsigned int id;
        };
    }
}