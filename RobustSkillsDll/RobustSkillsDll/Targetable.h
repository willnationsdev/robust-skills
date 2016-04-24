/*
 * Author: Will Nations
 * Date Created: 04/03/2016
 * Description:
 *     An interface for specifying a given object as a viable target for the
 *     sister interface Targeter.
 */
#pragma once

namespace robustskills {
    namespace targeting {

        class TargetData;

        /*
         * A lightweight 2D location object
         */
        template <typename T>
        struct vec2 {
            T x;
            T y;
        };

        /*
         * A lightweight 3D location object
         */
        template <typename T>
        struct vec3 {
            T x;
            T y;
            T z;
        };

        /*
         * An interface for representing an object that can be targeted by 
         * other objects.
         *
         * - Can be queried to determine whether it is in a targetable state.
         * - Can be queried for its location.
         * - Can be queried for general information about the target itself.
         *     o Users may designate the exact class they would like to use
         *       to represent the Targetable class's data
         *     o Assuming "data" could be...
         *         ::Whether the object can be "attacked"
         *         ::What targeting "channels" the object is in
         *         ::The allowed range with which this object can be targeted
         *
         *  It's up to you what type of object you would like to use for
         *  targeting data.
         */
        class Targetable
        {
        public:
            Targetable() {};
            ~Targetable() {};

            // A "master lock" on whether it can be targeted
            virtual bool isTargetable() = 0;

            // Location of the Target. Selectively override as needed
            virtual const vec2<int>& getLocation2D() {};
            virtual const vec2<float>& getLocation2Df() {};
            virtual const vec3<int>& getLocation3D() {};
            virtual const vec3<float>& getLocation3Df() {};

            // Information about the Target
            virtual const TargetData* getData() = 0;

            // Update the Targetable object's information
            virtual void setData(TargetData* data) = 0;
        };

        /*
         * Provides an interface between targeting assets to enforce a 
         * relation. Thereby allows for things to be conditionally targeted.
         */
        class TargetPermissions {
        public:
            TargetPermissions() {};
            ~TargetPermissions() {};

            /*
             * Can a Targeter with *this* TargetPermissions be allowed to 
             * target a Targetable with "otherPermissions"?
             */
            virtual bool canTarget(const TargetPermissions* otherPermissions) 
                const = 0;
        };

        /*
         * Provides information about the target, including targeting 
         * permissions
         */
        class TargetData {
        public:
            virtual ~TargetData() = 0;

            virtual const char* getName() = 0;
            virtual const char* getDescription() = 0;
            virtual TargetPermissions* getPermissions() = 0;
        };
    }
}

