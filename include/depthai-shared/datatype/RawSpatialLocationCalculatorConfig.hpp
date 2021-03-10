#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "DatatypeEnum.hpp"
#include "RawBuffer.hpp"
#include "RawImgFrame.hpp"
#include "depthai-shared/common/Rect.hpp"

namespace dai {

struct SpatialLocationCalculatorConfigThresholds {
    uint32_t lowerThreshold = 0;
    uint32_t upperThreshold = 65000;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SpatialLocationCalculatorConfigThresholds, lowerThreshold, upperThreshold);

struct SpatialLocationCalculatorConfigData {
    // Normalized range 0-1
    Rect roi;
    SpatialLocationCalculatorConfigThresholds depthThresholds;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SpatialLocationCalculatorConfigData, roi, depthThresholds);

struct RawSpatialLocationCalculatorConfig : public RawBuffer {
    std::vector<SpatialLocationCalculatorConfigData> config;

    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) override {
        nlohmann::json j = *this;
        metadata = nlohmann::json::to_msgpack(j);
        datatype = DatatypeEnum::SpatialLocationCalculatorConfig;
    };

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RawSpatialLocationCalculatorConfig, config);
};

}  // namespace dai