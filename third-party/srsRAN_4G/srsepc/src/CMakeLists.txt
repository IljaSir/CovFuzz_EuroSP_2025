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

# FUZZ
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-coverage=edge,no-prune,trace-pc-guard")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-coverage=edge,no-prune,trace-pc-guard")
# FUZZ

# FUZZ
# set(COMMON_PATH /home/anonimous/Projects/CovFuzz_EuroSP_2025/common)

include_directories(${COMMON_INCLUDE_PATH}/Coverage_Instrumentation/include)
link_directories(${COMMON_BUILD_PATH}/Coverage_Instrumentation)

include_directories(${COMMON_INCLUDE_PATH}/ZMQ/ZMQ_Server/include)
link_directories(${COMMON_BUILD_PATH}/ZMQ/ZMQ_Server)

include_directories(../hdr/coverage_listener)
# FUZZ

add_subdirectory(mme)
add_subdirectory(hss)
add_subdirectory(spgw)
add_subdirectory(mbms-gw)

# Link libstdc++ and libgcc
if(BUILD_STATIC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")
endif(BUILD_STATIC)


if (RPATH)
  SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif (RPATH)

add_executable(srsepc main.cc
  coverage_listener/zmq_cov.cpp # FUZZ
)
target_link_libraries( srsepc  srsepc_mme
                               srsepc_hss
                               srsepc_sgw
                               s1ap_asn1
                               srsran_gtpu
                               srsran_asn1
                               srsran_common
                               srslog
                               support
                               ${CMAKE_THREAD_LIBS_INIT}
                               ${Boost_LIBRARIES}
                               ${SEC_LIBRARIES}
                               ${LIBCONFIGPP_LIBRARIES}
                               ${SCTP_LIBRARIES}
                               instr # FUZZ
                               zmq_server_lib # FUZZ
                               zmq # FUZZ
)

add_executable(srsmbms mbms-gw/main.cc) 

target_link_libraries(srsmbms   srsepc_mbms_gw
                                srsran_asn1
                                srsran_gtpu
                                srsran_common
                                srslog
                                ${CMAKE_THREAD_LIBS_INIT}
                                ${Boost_LIBRARIES}
                                ${SEC_LIBRARIES}
                                ${LIBCONFIGPP_LIBRARIES}
                                ${SCTP_LIBRARIES})
if (RPATH)
  set_target_properties(srsepc PROPERTIES INSTALL_RPATH ".")
  set_target_properties(srsmbms PROPERTIES INSTALL_RPATH ".")
endif (RPATH)

########################################################################
# Option to run command after build (useful for remote builds)
########################################################################
if (NOT ${BUILDEPC_CMD} STREQUAL "")
  message(STATUS "Added custom post-build-EPC command: ${BUILDENB_CMD}")
  add_custom_command(TARGET srsenb POST_BUILD COMMAND ${BUILDENB_CMD})
else(NOT ${BUILDEPC_CMD} STREQUAL "")
  message(STATUS "No post-build-EPC command defined")
endif (NOT ${BUILDEPC_CMD} STREQUAL "")

install(TARGETS srsepc DESTINATION ${RUNTIME_DIR} OPTIONAL)
install(TARGETS srsmbms DESTINATION ${RUNTIME_DIR} OPTIONAL)
