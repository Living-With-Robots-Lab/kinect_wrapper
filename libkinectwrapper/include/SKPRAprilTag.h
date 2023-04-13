#ifndef SKPR_APRIL_TAG_H
#define SKPR_APRIL_TAG_H

#include "SKPRecipient.h"
#include <apriltag/apriltag.h>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

#include <string>

class SKPRAprilTag : public SKPRecipient {
public:
    SKPRAprilTag(std::string image, std::string resultMat, std::string outImage, bool render);
    void receiveFrame(SKPacket &skp);
    void addRecipient(SKPRecipient *skpr);

protected:
    Eigen::MatrixXd detectCorners(const cv::Mat &img);
    
    std::string _image, _resultMat, _outImage;
    bool _render;

    apriltag_detector_t *td;
    apriltag_family_t *tf;

    std::vector<SKPRecipient *> _recipients;
        
};

#endif