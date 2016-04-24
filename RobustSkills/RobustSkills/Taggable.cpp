#include "Taggable.h"

namespace robustskills {
    namespace core {

        template <typename T>
        void Taggable<T>::addTag(Tag&& tag) {
            tags.insert(std::make_pair(quote(T),tag));
        }

        template <typename T>
        void Taggable<T>::removeTag(Tag&& tag) {
            tags.erase(tag);
        }

        template <typename T>
        bool Taggable<T>::hasTag(Tag&& tag) {
            return tags.find(std::make_pair(quote(T),tag)) != tags.end();
        }
    }
}
