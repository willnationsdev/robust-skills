#include "SkillUser.h"

namespace robustskills {

    namespace core {
#pragma region SkillStorage
        template <typename Skill>
        bool SkillStorage<Skill>::addSkill(const Skill*) {

        }

        template <typename Skill>
        bool SkillStorage<Skill>::removeSkill(const Skill*) {

        }

        template <typename Skill>
        bool SkillStorage<Skill>::equipSkill(const Skill*) {

        }

        template <typename Skill>
        bool SkillStorage<Skill>::unequipSkill(const Skill*) {

        }
#pragma endregion

#pragma region SkillUser
        template <SKILLUSERPARTS>
        SkillUser<SKILLUSERPARTS>::SkillUser() {

        }

        template <SKILLUSERPARTS>
        SkillUser<SKILLUSERPARTS>::~SkillUser() {

        }

        template <SKILLUSERPARTS>
        SkillStorage* SkillUser<SKILLUSERPARTS>::getSkillStorage() {

        }

        template <SKILLUSERPARTS>
        void SkillUser<SKILLUSERPARTS>::setSkillStorage(const SkillStorage* skillStorage) {

        }

        template <SKILLUSERPARTS>
        EffectStorage* SkillUser<SKILLUSERPARTS>::getEffectStorage() {

        }

        template <SKILLUSERPARTS>
        void SkillUser<SKILLUSERPARTS>::setEffectStorage(const EffectStorage*
            effectStorage) {

        }

        template <SKILLUSERPARTS>
        SkillUserStats* SkillUser<SKILLUSERPARTS>::getSkillUserStats() {

        }

        template <SKILLUSERPARTS>
        void SkillUser<SKILLUSERPARTS>::setSkillUserStats(const SkillUserStats*
            skillUserData) {

        }

        template <SKILLUSERPARTS>
        LocationData* SkillUser<SKILLUSERPARTS>::getLocationData() {

        }

        template <SKILLUSERPARTS>
        void SkillUser<SKILLUSERPARTS>::setLocationData(const LocationData* locationData) {

        }
#pragma endregion

    }
}
