/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *     Defines an interface for objects associated with wielding skills.
 *
 *     [SkillStorage]
 *     - SkillUsers have some means of storing ("owning") skills
 *     - SkillUsers are able to learn and forget skills (add/remove them).
 *     - SkillUsers are able to "equip" skills as distinct, active storage.
 *         o equipped skills must be a subset of owned skills
 *     [EffectStorage]
 *     - SkillUsers are able to sustain instantaneous effects from skills
 *              AND are able to sustain effects from skills over a duration
 *     [ItemStorage]
 *     - SkillUsers may have stored Items that can be added or removed
 *         o Some Items may be Equipment that grant access to Skills
 *     [SkillUserStats]
 *     - SkillUsers have stats that can influence and be influenced by skills
 *     [LocationData]
 *     - SkillUsers have a place in the world (a location of some sort)
 */
#pragma once

#include "SkillInterface.h"
#define SKILLUSERPARTS typename SkillStorage, typename EffectStorage, typename SkillUserStats, typename LocationData

namespace robustskills {

    namespace core {
        /*
         * Responsible for managing memory storage associated with the Skills
         * mapped to a given Skill.
         */
        template <typename Skill>
        class SkillStorage {
        public:
            virtual bool addSkill(const Skill*);
            virtual bool removeSkill(const Skill*);
            virtual bool equipSkill(const Skill*);
            virtual bool unequipSkill(const Skill*);
        private:
        };

        /*
         * Responsible for providing services regarding persistent effects on
         * the SkillUser.
         */
        class EffectStorage {
        public:

        private:
        };

        class SkillUserStats {
        public:


        private:
        };

        class LocationData {
        public:

        private:
        };

        template <SKILLUSERPARTS>
        class SkillUser {
        public:
            SkillUser();
            ~SkillUser();

            SkillStorage* getSkillStorage();
            void setSkillStorage(const SkillStorage* skillStorage);

            EffectStorage* getEffectStorage();
            void setEffectStorage(const EffectStorage*
                effectStorage);

            SkillUserStats* getSkillUserStats();
            void setSkillUserStats(const SkillUserStats*
                skillUserData);

            LocationData* getLocationData();
            void setLocationData(const LocationData* locationData);

        private:
            SkillStorage
        };
    }
}
