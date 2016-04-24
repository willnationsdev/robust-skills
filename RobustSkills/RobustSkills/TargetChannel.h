/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *     Describes a sample TargetPermissions arrangement based on
 *     TargetChannels whereby Targeters can conditionally target
 *     Targetables based on the TargetChannels their TargetChannelPermissions
 *     are associated with.
 */

#pragma once

#include "Targetable.h"
#include "Taggable.h"
#include <exception>

namespace robustskills {

    using Tag = core::Taggable::Tag;

    namespace targeting {
        /*
         * Describes the attribute of a given "channel" state.
         */
        class TargetChannel : public core::Taggable {

        public:

            Tag getName() const { return name; }
            void setName(Tag&& t = "") { name = t; }

            // Channels would then be specified in the following manner
            //static TargetChannelName Hackable;

        private:
            Tag name;
        };

        class TargetChannelPermissions : TargetPermissions {
        public:

            enum class Exclusivity : bool { ANY, ALL };

            const TargetChannel* getChannels() const { return channels; }
            const int getNumChannels() const { return numChannels; }

            virtual bool canTarget(const TargetPermissions&& otherPermissions) const override;

            virtual bool canTarget(
                const TargetChannelPermissions* otherPermissions = nullptr,
                const Exclusivity exclusivity = Exclusivity::ALL);

        private:
            // To be overridden for better efficiency if desired
            virtual bool findChannel(const TargetChannelPermissions* permissions,
                Tag&& name) const;

            TargetChannel* channels;
            int numChannels;
            Exclusivity nativeExclusivity;
        };
    }
}
