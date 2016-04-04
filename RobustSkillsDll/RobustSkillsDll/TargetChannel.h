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

namespace robustskills {

    /*
     * Describes the attribute of a given "channel" state.
     */
    class TargetChannel {

    public:
        typedef char* TargetChannelName;

        const TargetChannelName getName() const { return name; }
        void setName(const TargetChannelName n = "") { name = n; }

        // Channels would then be specified in the following manner
        //static TargetChannelName Hackable;

    private:
        TargetChannelName name;
    };

    class TargetChannelPermissions : TargetPermissions {
    public:

        enum class TargetPermissionsExclusivity : bool { ANY, ALL };
        using TPE = TargetPermissionsExclusivity;

        const TargetChannel* getChannels() const { return channels; }
        const int getNumChannels() const { return numChannels; }

        virtual bool canTarget(const TargetPermissions* otherPermissions) const override;

        virtual bool canTarget(
            const TargetChannelPermissions* otherPermissions = nullptr);

        virtual bool canTarget(
            const TargetChannelPermissions* otherPermissions = nullptr,
            const TPE exclusivity = TPE::ALL);

    private:
        // To be overridden for better efficiency if desired
        virtual bool findChannel(const TargetChannelPermissions* permissions,
            const TargetChannel::TargetChannelName name) const;

        TargetChannel* channels;
        int numChannels;
        TPE nativeExclusivity;
    };
}