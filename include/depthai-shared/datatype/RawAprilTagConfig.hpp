#pragma once
#include <cstdint>
#include "depthai-shared/utility/Serialization.hpp"
#include <vector>

#include "DatatypeEnum.hpp"
#include "RawBuffer.hpp"

namespace dai {

/// AprilTagType configuration data structure
struct AprilTagType {
    enum class Type : std::int32_t { TAG_36H11 = 0, TAG_25H9, TAG_16H5, TAG_CIR21H7, TAG_CIR49H12, TAG_CUST48H12, TAG_STAND41H12, TAG_STAND52H13 };

    Type t = Type::TAG_36H11;
};
DEPTHAI_SERIALIZE_EXT(AprilTagType, t);

/// RawAprilTags configuration structure
struct RawAprilTagConfig : public RawBuffer {
    AprilTagType config;

    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) const override {
        nlohmann::json j = *this;
        metadata = nlohmann::json::to_msgpack(j);
        datatype = DatatypeEnum::AprilTagConfig;
    };

    DEPTHAI_SERIALIZE(RawAprilTagConfig, config);
};

}  // namespace dai
