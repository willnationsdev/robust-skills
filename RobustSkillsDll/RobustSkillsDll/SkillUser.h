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

namespace robustskills {

    namespace interfaces {

        class SkillStorage {
        public:
            virtual bool addSkill(const SkillInterface*) = 0;
            virtual bool removeSkill(const SkillInterface*) = 0;
            virtual bool equipSkill(const SkillInterface*) = 0;
            virtual bool unequipSkill(const SkillInterface*) = 0;
        private:
        };

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

        class SkillUser {

        public:
            SkillUser() {};
            virtual ~SkillUser() = 0;

            virtual SkillStorage* getSkillStorage() = 0;
            virtual void setSkillStorage(const SkillStorage* skillStorage) = 0;

            virtual EffectStorage* getEffectStorage() = 0;
            virtual void setEffectStorage(const EffectStorage* 
                effectStorage) = 0;

            virtual SkillUserStats* getSkillUserStats() = 0;
            virtual void setSkillUserStats(const SkillUserStats*
                skillUserData) = 0;

            virtual LocationData* getLocationData() = 0;
            virtual void setLocationData(const LocationData* locationData) = 0;
        };

    }

}
