/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2013 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

#ifndef REACTPHYSICS3D_AABB_H
#define REACTPHYSICS3D_AABB_H

// Libraries
#include "../../mathematics/mathematics.h"

/// ReactPhysics3D namespace
namespace reactphysics3d {

// Declaration
class Body;
    
// Class AABB
/**
 * This class represents a bounding volume of type "Axis Aligned
 * Bounding Box". It's a box where all the edges are always aligned
 * with the world coordinate system. The AABB is defined by the
 * minimum and maximum world coordinates of the three axis.
 */
class AABB {

    private :

        // -------------------- Attributes -------------------- //

        /// Minimum world coordinates of the AABB on the x,y and z axis
        Vector3 mMinCoordinates;

        /// Maximum world coordinates of the AABB on the x,y and z axis
        Vector3 mMaxCoordinates;

        // -------------------- Methods -------------------- //

        /// Private copy-constructor
        AABB(const AABB& aabb);

        /// Private assignment operator
        AABB& operator=(const AABB& aabb);

        /// Constructor
        AABB(const Transform& transform, const Vector3& extents);

    public :

        // -------------------- Methods -------------------- //

        /// Constructor
        AABB();

        /// Constructor
        AABB(const Vector3& minCoordinates, const Vector3& maxCoordinates);



        /// Destructor
        virtual ~AABB();

        /// Return the center point
        Vector3 getCenter() const;

        /// Return the minimum coordinates of the AABB
        const Vector3& getMin() const;

        /// Set the minimum coordinates of the AABB
        void setMin(const Vector3& min);

        /// Return the maximum coordinates of the AABB
        const Vector3& getMax() const;

        /// Set the maximum coordinates of the AABB
        void setMax(const Vector3& max);

        /// Return true if the current AABB is overlapping with the AABB in argument
        bool testCollision(const AABB& aabb) const;
};

// Return the center point of the AABB in world coordinates
inline Vector3 AABB::getCenter() const {
    return (mMinCoordinates + mMaxCoordinates) * 0.5;
}

// Return the minimum coordinates of the AABB
inline const Vector3& AABB::getMin() const {
    return mMinCoordinates;
}

// Set the minimum coordinates of the AABB
inline void AABB::setMin(const Vector3& min) {
    mMinCoordinates = min;
}

// Return the maximum coordinates of the AABB
inline const Vector3& AABB::getMax() const {
    return mMaxCoordinates;
}

/// Set the maximum coordinates of the AABB
inline void AABB::setMax(const Vector3& max) {
    mMaxCoordinates = max;
}

// Return true if the current AABB is overlapping with the AABB in argument.
/// Two AABBs overlap if they overlap in the three x, y and z axis at the same time
inline bool AABB::testCollision(const AABB& aabb) const {
    if (mMaxCoordinates.x < aabb.mMinCoordinates.x ||
        aabb.mMaxCoordinates.x < mMinCoordinates.x) return false;
    if (mMaxCoordinates.y < aabb.mMinCoordinates.y ||
        aabb.mMaxCoordinates.y < mMinCoordinates.y) return false;
    if (mMaxCoordinates.z < aabb.mMinCoordinates.z||
        aabb.mMaxCoordinates.z < mMinCoordinates.z) return false;
    return true;
}

}

#endif