#
# Copyright 2013-2023 Software Radio Systems Limited
#
# This file is part of srsRAN
#
# srsRAN is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# srsRAN is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# A copy of the GNU Affero General Public License can be found in
# the LICENSE file in the top-level directory of this distribution
# and at http://www.gnu.org/licenses/.
#

find_package(LibConfig REQUIRED)
find_package(SCTP REQUIRED)

if(BUILD_STATIC)
  set(LIBCONFIGPP_LIBRARIES "${LIBCONFIGPP_STATIC_LIBRARY_PATH}")
endif(BUILD_STATIC)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost required to compile srsENB")
endif()

########################################################################
# Setup the include and linker paths
########################################################################
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${SEC_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}
)

link_directories(
    ${Boost_LIBRARY_DIRS}
    ${SEC_LIBRARY_DIRS}
)

########################################################################
# Add subdirectories
########################################################################
add_subdirectory(src)
#add_subdirectory(test)

########################################################################
# Default configuration files
########################################################################
install(FILES enb.conf.example DESTINATION ${DATA_DIR})
install(FILES rb.conf.example  DESTINATION ${DATA_DIR})
install(FILES rr.conf.example  DESTINATION ${DATA_DIR})
install(FILES sib.conf.example DESTINATION ${DATA_DIR})
