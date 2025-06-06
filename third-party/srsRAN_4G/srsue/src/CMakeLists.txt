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

### FUZZ
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-coverage=edge,no-prune,trace-pc-guard")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-coverage=edge,no-prune,trace-pc-guard")
#
include_directories(${COMMON_INCLUDE_PATH}/Coverage_Instrumentation/include)
link_directories(${COMMON_BUILD_PATH}/Coverage_Instrumentation)
#
include_directories(${COMMON_INCLUDE_PATH}/ZMQ/ZMQ_Server/include)
link_directories(${COMMON_BUILD_PATH}/ZMQ/ZMQ_Server/)
#
include_directories(${COMMON_INCLUDE_PATH}/ZMQ/ZMQ_Client/include)
link_directories(${COMMON_BUILD_PATH}/ZMQ/ZMQ_Client)
#
include_directories(${COMMON_INCLUDE_PATH}/shm)
link_directories(${COMMON_BUILD_PATH}/shm)
#
include_directories(../hdr/coverage_listener)
### FUZZ: END

add_subdirectory(phy)
add_subdirectory(stack)
##add_subdirectory(test)

# Link libstdc++ and libgcc
if(BUILD_STATIC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")
endif(BUILD_STATIC)

if (RPATH)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
endif (RPATH)

# FUZZ: added coverage_listener/zmq_cov.cpp
add_executable(srsue main.cc ue.cc metrics_stdout.cc metrics_csv.cc metrics_json.cc
 coverage_listener/zmq_cov.cpp)
# FUZZ END: added coverage_listener/zmq_cov.cpp

set(SRSUE_SOURCES srsue_phy srsue_stack srsue_upper srsue_mac srsue_rrc srslog system)
set(SRSRAN_SOURCES srsran_common srsran_mac srsran_phy srsran_radio srsran_gtpu srsran_rlc srsran_pdcp rrc_asn1 srslog support system)

set(SRSUE_SOURCES ${SRSUE_SOURCES} srsue_nr_stack srsue_rrc_nr srsue_mac_nr)
set(SRSRAN_SOURCES ${SRSRAN_SOURCES} rrc_nr_asn1 ngap_nr_asn1)

target_link_libraries(srsue   ${SRSUE_SOURCES}
                              ${SRSRAN_SOURCES}
                              instr # FUZZ
                              zmq_server_lib # FUZZ
                              zmq_client_lib # FUZZ
                              shared_memory # FUZZ
                              zmq #FUZZ
                              ${CMAKE_THREAD_LIBS_INIT}
                              ${Boost_LIBRARIES}
                              ${ATOMIC_LIBS})

if (RPATH)
  set_target_properties(srsue PROPERTIES INSTALL_RPATH ".")
endif (RPATH)

########################################################################
# UE initialization test
########################################################################

if(NOT SRSGUI_FOUND)
# Make sure srsue returns 0 and it does not leak
add_test(srsue_version srsue --version)
add_test(srsue_help srsue --help)
endif(NOT SRSGUI_FOUND)

# Checks that ue.conf.example is valid and it does not leak memory if RF fails
if (ZEROMQ_FOUND)
  add_test(ue_rf_failure srsue ${CMAKE_SOURCE_DIR}/srsue/ue.conf.example --rf.device_name=zmq)
  add_test(ue_rf_failure_max_channels srsue ${CMAKE_SOURCE_DIR}/srsue/ue.conf.example --rf.device_name=zmq --rf.nof_antennas=4 --rat.eutra.nof_carriers=5)
  add_test(ue_rf_failure_exceeds_channels srsue ${CMAKE_SOURCE_DIR}/srsue/ue.conf.example --rf.device_name=zmq --rf.nof_antennas=5 --rat.eutra.nof_carriers=5)
endif(ZEROMQ_FOUND)

########################################################################
# Option to run command after build (useful for remote builds)
########################################################################
if (NOT ${BUILDUE_CMD} STREQUAL "")
  message(STATUS "Added custom post-build-UE command: ${BUILDUE_CMD}")
  add_custom_command(TARGET srsue POST_BUILD COMMAND ${BUILDUE_CMD})
else(NOT ${BUILDUE_CMD} STREQUAL "")
  message(STATUS "No post-build-UE command defined")
endif (NOT ${BUILDUE_CMD} STREQUAL "")

install(TARGETS srsue DESTINATION ${RUNTIME_DIR} OPTIONAL)
