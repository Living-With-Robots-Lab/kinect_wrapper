#ifndef SK_PACKET_H
#define SK_PACKET_H

#include <Eigen/Eigen>
#include <k4a/k4a.h>

#include <opencv2/opencv.hpp>

#include <map>
#include <string>

#include <cstdlib>
#include "SKWrapper.h"

class SKConfig;
class SKWrapper;

class SKPacket {
public:
    SKPacket(SKWrapper *wrapper);
    ~SKPacket();

    SKWrapper *getSKWrapper();

    k4a::capture getCapture();
    void setCapture(k4a::capture capture);

    cv::Mat &getCVMat(std::string name);
    void allocateCVMat(int rows, int cols, int format, std::string name);

    cv::Mat getRGBColor();
    cv::Mat getRGBColorPreviewScale();
    k4a::image getXYZDepth();

    Eigen::MatrixXd getAprilTagMatrix();
    std::vector<Eigen::MatrixXd> getAprilTagVector();

    std::map<std::string, Eigen::MatrixXd> cornerDetections;

protected:
    SKWrapper *_wrapper;
    std::map<std::string, cv::Mat> _namedMats;

private:
    k4a::image getBGRAColorKinect();

    k4a::capture _capture;
    k4a::image _depthImage, _colorImage;
};

#endif