#pragma once

#include <nlohmann/json.hpp>

enum class PROTOCOL_STACK_NAME {
    SRSRAN_4G_SRSUE,
    SRSRAN_4G_COTS_UE,
    SRSRAN_4G_DUMMY,
    SRSRAN_5G_SRSUE,
    SRSRAN_5G_COTS_UE,
    SRSRAN_5G_DUMMY,
    DUMMY
};

NLOHMANN_JSON_SERIALIZE_ENUM( PROTOCOL_STACK_NAME, {
    {PROTOCOL_STACK_NAME::SRSRAN_4G_SRSUE, "SRSRAN_4G_SRSUE"},
    {PROTOCOL_STACK_NAME::SRSRAN_4G_COTS_UE, "SRSRAN_4G_COTS_UE"},
    {PROTOCOL_STACK_NAME::SRSRAN_4G_DUMMY, "SRSRAN_4G_DUMMY"},
    {PROTOCOL_STACK_NAME::SRSRAN_5G_SRSUE, "SRSRAN_5G_SRSUE"},
    {PROTOCOL_STACK_NAME::SRSRAN_5G_COTS_UE, "SRSRAN_5G_COTS_UE"},
    {PROTOCOL_STACK_NAME::SRSRAN_5G_DUMMY, "SRSRAN_5G_DUMMY"},
    {PROTOCOL_STACK_NAME::DUMMY, "DUMMY"}
})