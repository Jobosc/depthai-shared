#pragma once

#include <cstdint>

namespace dai {

enum class DatatypeEnum : std::int32_t { Buffer, ImgFrame, NNData, ImageManipConfig };
bool isDatatypeSubclassOf(DatatypeEnum parent, DatatypeEnum children);

}  // namespace dai
