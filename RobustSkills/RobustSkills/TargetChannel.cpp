/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *    Implementation of TargetChannel-related class methods
 */
#include "TargetChannel.h"
#include <assert.h>

namespace robustskills {

    namespace targeting {
        // Target Channels example
        //TargetChannel::TargetChannelName TargetChannel::Hackable = "HACKABLE";

        /*
         * If the given TargetPermissions can be interpreted as having channels,
         * then calls the corresponding function. Otherwise, assumes they cannot
         * be targeted.
         */
        bool TargetChannelPermissions::canTarget(const TargetPermissions*
            otherPermissions) const {

            // Were the permissions we were given convertible to channel 
            // permissions? If so, call the channel version. Else return false.
            try {
                const TargetChannelPermissions* p =
                    static_cast<const TargetChannelPermissions*>(otherPermissions);
                return p ? canTarget(p) : false;
            }
            catch (std::exception e) {
                return false;
            }
        }

        /*
         * Determines targetability using the default native exclusivity
         */
        bool TargetChannelPermissions::canTarget(
            const TargetChannelPermissions* otherPermissions = nullptr) {

            return canTarget(otherPermissions, nativeExclusivity);
        }

        /*
         * Reports whether, in comparing the TargetPermissions, one is able to
         * match the requisite set of TargetChannels to approve of targeting.
         * Allows for a specific exclusivity to be provided
         */
        bool TargetChannelPermissions::canTarget(const TargetChannelPermissions*
            otherPermissions, const Exclusivity&& exclusivity) {

            // Require that we are given a valid reference
            assert(otherPermissions != nullptr);

            // Cycle through each TargetChannel we have
            for (int i = 0; i < getNumChannels(); ++i) {

                // Get the current channel's name
                TargetChannel::TargetChannelName name =
                    getChannels()[i].getName();

                // Check whether the other permissions have a match
                bool didFind = findChannel(otherPermissions, name);

                if (didFind) {
                    // If you did find it, and just need one, return success
                    if (exclusivity == TPE::ANY) {
                        return true;
                    }
                }
                // If you didn't find it, and you need all, return failure
                else if (exclusivity == TPE::ALL) {
                    return false;
                }
            }
            // Searched them all and never exited with failure. Return success
            if (exclusivity == TPE::ALL) {
                return true;
            }
            // Searched them all and never exited with success. Return failure
            else if (exclusivity == TPE::ANY) {
                return false;
            }
        }

        /*
         * Simple brute force algorithm. Searches through the Permissions list
         * to detect whether it has the desired TargetChannel.
         *
         * TODO: Could be improved by adding more direct access to the name.
         * Recommend adding a std::set for name identification
         */
        bool TargetChannelPermissions::findChannel(const TargetChannelPermissions* permissions,
            const TargetChannel::TargetChannelName name) const
        {
            for (int i = 0; i < permissions->getNumChannels(); ++i) {
                if (permissions->getChannels()[i].getName() == name) {
                    return true;
                }
            }
            return false;
        }
    }
}
