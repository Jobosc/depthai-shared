#pragma once

// std
#include <cstdint>
#include <vector>

// libraries
#include "nlohmann/json.hpp"

namespace dai {

struct CameraExtrinsics {
    std::vector<std::vector<double>> rotationMatrix;
    std::vector<double> translation;
    std::shared_ptr<CameraInfo> destCamera; // Does using pointer makes sense while writing to eeprom or should we just use an number index for cameras and link using that ?
};

struct StereoRectification {
    std::vector<std::vector<double>> rectifiedRotationLeft, rectifiedRotationRight;
    std::shared_ptr<CameraInfo> *leftCamera, *rightCamera;
    int baseline;
};


struct CameraInfo {
    std::vector<std::vector<double>> intrinsicMatrix;
    std::vector<double> distortionCoeff;
    CameraExtrinsics extrinsics;
};

struct EepromData {
    bool swapLeftRightCam;
    double monoFovRad, rgbFovRad;
    std::string name, revision;
    std::vector<CameraInfo> cameraData;
    StereoRectification stereoRectificationData;
}


// struct EepromData {
//     // int64_t sec, nsec;
//     bool swapLeftRightCam;
//     // Can we change this to radians? most of the standard api's prefer radian. would make things easier to integrate
//     double monoFovRad, rgbFovRad;
//     // since gen2 is more flexible can we move distance vars to setting during pipeline creation or can be used from calibration
//     double leftRightDistanceMtrs, leftRGBDistanceMtrs;
//     // board name. do we need this ? it might help in debugging which device the user is using.
//     std::string name, revision;
//     /**
//      * While helping OPAL I realized this can also be produced rectification from the other information we get during calibration.
//      * we might need to add that function on the host side if the users want to use rgb camera like OPAL did
//      **/
//     std::vector<std::vector<double>> rectifiedRotationLeft, rectifiedRotationRight;
//     // Intriniscs of the cameras
//     std::vector<std::vector<double>> intrinsicMatrixLeft, intrinsicMatrixRight, intrinsicMatrixRGB;
//     // Relative rotation between cameras
//     std::vector<std::vector<double>> rotationMatrixLeftRight, rotationMatrixRightRGB;  // need to add IMU extrinsics later
//     // Relative translation between cameras
//     std::vector<double> translationLeftRight, translationRightRGB;
//     // Distortion Coefficients
//     std::vector<double> distortionCoeffLeft, distortionCoeffRight, distortionCoeffRGB;



//     NLOHMANN_DEFINE_TYPE_INTRUSIVE(EepromData,
//                                    swapLeftRightCam,
//                                    monoFovRad,
//                                    rgbFovRad,
//                                    leftRightDistanceMtrs,
//                                    leftRGBDistanceMtrs,
//                                    name,
//                                    revision,
//                                    rectifiedRotationLeft,
//                                    rectifiedRotationRight,
//                                    intrinsicMatrixLeft,
//                                    intrinsicMatrixRight,
//                                    intrinsicMatrixRGB,
//                                    rotationMatrixLeftRight,
//                                    rotationMatrixRightRGB,
//                                    translationLeftRight,
//                                    translationRightRGB,
//                                    distortionCoeffLeft,
//                                    distortionCoeffRight,
//                                    distortionCoeffRGB);
// };

}  // namespace dai
