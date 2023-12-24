//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include <cstdlib>

#ifndef NESTING_COMMON_TESTUTIL_H_
#define NESTING_COMMON_TESTUTIL_H_

#include <iostream>
#include <cstdlib>

// Useful macros for writing tests. Not intended to be used in regular NESTING components.

#define ASSERT_EQUAL(value, expectedValue) \
({ \
    if ((value) != (expectedValue)) { \
        std::cout << "Expected " << #value << " == " << #expectedValue << std::endl; \
        exit(1); \
    } \
})

#define ASSERT_NOT_EQUAL(value, expectedValue) \
({ \
    if ((value) == (expectedValue)) { \
        std::cout << "Expected " << #value << " != " << #expectedValue << std::endl; \
        exit(1); \
    } \
})

#endif
