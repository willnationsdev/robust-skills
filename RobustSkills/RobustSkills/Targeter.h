#pragma once
/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *     Specifies classes responsible for acquiring pointers to Targetables.
 */

#include "Targetable.h"

namespace robustskills {
    namespace interfaces {

        class TargetStorage {
            // Get the next target
            virtual Targetable* nextTarget() = 0;

            // Get the previous target
            virtual Targetable* previousTarget() = 0;

            // Checks whether a particular Targetable object can be targeted
            virtual bool canTarget(Targetable* target) = 0;
        };

        /*
         * Classes that have the power to gather collections of Targetables.
         */
        class TargetAcquirer {

        public:
            virtual ~TargetAcquirer() = 0;

            // Acquire a fresh set of targets. Assumed to reset next/previous
            virtual void updateTargets() = 0;

            // Returns a storage mechanism for processing the Targetables
            virtual TargetStorage* getTargetStorage() = 0;
        };


        /*
         * Manages a targeting system composed of TargetAcquirers. The 
         * targeting system collects an aggregate selection of targets and then
         * processes the entire group.
         */
        class Targeter {

        public:
            Targeter() {};
            ~Targeter() {};

            struct TargetReport {
                TargetReport(bool r, bool p, bool t) : inRange(r), 
                    permission(p), targetable(t) {}

                // Is it within the valid targeting area?
                bool inRange : 1;
                // Do your permissions match?
                bool permission : 1;
                // Targetable.getData().getPermissions().
                //     canTarget(myTargetPermissions) == true
                bool targetable : 1;
            };

#pragma region Permissions
            // Getter for the Targeter's Permissions
            virtual TargetPermissions getPermissions() = 0;

            // Setter for the Targeter's Permissions
            virtual void setPermissions(const TargetPermissions& permissions) 
                = 0;
#pragma endregion

#pragma region Add/Remove Acquirers
            // Adds a new TargetAcquirer to the targeting system
            virtual void addTargetAcquirer(const TargetAcquirer*
                acquirer) = 0;

            // Removes the given TargetAcquirer from the targeting system
            virtual void removeTargetAcquirer(const TargetAcquirer*
                acquirer) = 0;
#pragma endregion


#pragma region Target Operations
            // updates the targets of all TargetAcquirers
            virtual void updateTargets() = 0;

            // Get the next target from aggregate Targetable collection
            virtual Targetable* nextTarget() = 0;

            // Get the previous target from aggregate Targetable collection
            virtual Targetable* previousTarget() = 0;

            // Checks whether a particular Targetable object can be targeted
            virtual TargetReport canTarget(Targetable* target) = 0;
#pragma endregion
        };
    }
}