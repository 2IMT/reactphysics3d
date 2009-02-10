/****************************************************************************
 * Copyright (C) 2009      Daniel Chappuis                                  *
 ****************************************************************************
 * This file is part of ReactPhysics3D.                                     *
 *                                                                          *
 * ReactPhysics3D is free software: you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by     *
 * the Free Software Foundation, either version 3 of the License, or        *
 * (at your option) any later version.                                      *
 *                                                                          *
 * ReactPhysics3D is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
 * GNU General Public License for more details.                             *
 *                                                                          *
 * You should have received a copy of the GNU General Public License        *
 * along with ReactPhysics3D. If not, see <http://www.gnu.org/licenses/>.   *
 ***************************************************************************/

 // Libraries
 #include "Body.h"

// We want to use the ReactPhysics3D namespace
using namespace reactphysics3d;

// Constructor
Body::Body(Kilogram mass) throw(std::invalid_argument) : mass(mass)  {
    // Check if the mass is different from zero
    if (mass.getValue() == 0) {
        // We throw an exception
        throw std::invalid_argument("Exception in Body constructor : the mass has to be different from zero");
    }
}

// Copy-constructor
Body::Body(const Body& body) : mass(body.mass) {

}

// Destructor
Body::~Body() {

}