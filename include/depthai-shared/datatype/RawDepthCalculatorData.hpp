#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <vector>

#include "DatatypeEnum.hpp"
#include "RawBuffer.hpp"
#include "RawImgFrame.hpp"
#include "RawDepthCalculatorConfig.hpp"

namespace dai {

struct DepthCalculatorDataOut {
    DepthCalculatorConfig config;
    float depth_avg;

};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DepthCalculatorDataOut, config, depth_avg);


struct RawDepthCalculatorData : public RawBuffer {

    std::vector<DepthCalculatorDataOut> depth;

    void serialize(std::vector<std::uint8_t>& metadata, DatatypeEnum& datatype) override {
        nlohmann::json j = *this;
        metadata = nlohmann::json::to_msgpack(j);
        datatype = DatatypeEnum::DepthCalculatorData;
    };

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RawDepthCalculatorData, depth);
};

}  // namespace dai