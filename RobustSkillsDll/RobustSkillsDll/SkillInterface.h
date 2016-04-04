/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *     Defines interfaces for objects associated with applying effects.
 *
 *     This necessarily involves Skills, the Effects they apply, and the
 *     Mods (Modifications) that influence the Skills and their Effects.
 *
 *     [Effect]
 *     - Has a Source SkillUser
 *     - Has a Target SkillUser (may or may not have been explicitly targeted
 *           by the Source SkillUser)
 *     - Applies a singular alteration to the Target SkillUser's...
 *         o SkillStorage
 *         o EffectStorage
 *         o SkillUserStats
 *         o LocationData
 *     - Has EffectAttributes that details the data associated with the
 *           Effect's application.

 *     [EffectMods]
 *     - Has a Target Effect
 *     - Applies a single ALTERATION to an EffectAttribute's
 *     - Has a specific power of modification (intensity)
 *     - Has a specific duration
 *
 *     [EffectStorage]
 *     - Skills have a set of Effects they can apply.
 *     - Skills can add or remove Effects.
 *     - Skills can report what Effects they will have on a Target SkillUser
 *
 *     [SkillAttributeData]
 *     - Skills have attributes that influence Effects.
 *
 *     [SkillUsagePermissions]
 *     - Skills have permissions that allow them to be used.
 *
 *     [Mod]
 *     - Mods may exist which affect both skills and their effects
 *         o Mods may influence ONLY 1 attribute
 *     - Mods will be...
 *         o internal, conditionally active (level?)
 *         o external, temporary exceptions
 *     - SkillMods modify SkillAttributes.
 *     - EffectMods modify 1 or more Effects
 *         o A specific Effect
 *         o Effects matching a certain Tag
 *         o All Effects
 *
 *     [ModStorage]
 *     - SkillMods & EffectMods are added/removed from storage
 *
 *     [SkillLevel]
 *     - Skills can have levels.
 *         o A level may influence the application of certain effects.
 *         o A level may influence the value of skill attributes.
 */
#pragma once

namespace robustskills {
    namespace interfaces {
        class SkillInterface
        {
        public:
            SkillInterface() {};
            virtual ~SkillInterface() = 0;
        };
    }
}
