//
//  main.cpp
//  OpenCV-调高图片对比度和亮度
//
//  Created by 陈江林 on 2019/9/11.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string fileName = "/Users/chenjianglin/Documents/C++/OpenCV07/OpenCV-调高图片对比度和亮度/OpenCV-调高图片对比度和亮度/two.jpg";
    Mat input = imread(fileName);
    if (input.empty()) {
        cout << "加载图片失败" << endl;
        return -1;
    }
    Mat out;
    //cvtColor(input, out, COLOR_BGR2GRAY);
    Mat result = Mat::zeros(input.size(), input.type());
    
    float alpha = 1.2;
    float beta = 10;
    
    int width = input.cols;
    int height = input.rows;
    int channels = input.channels();
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (channels == 3) {
                int b = input.at<Vec3b>(row, col)[0];
                int g = input.at<Vec3b>(row, col)[1];
                int r = input.at<Vec3b>(row, col)[2];
                
                result.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(alpha * b + beta);
                result.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(alpha * g + beta);
                result.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(alpha * r + beta);
            }
        }
    }
    
    if (result.empty()) {
        cout << "图像读取失败" << endl;
        return -1;
    }
    
    string outWindow = "outWindow";
    namedWindow(outWindow);
    imshow(outWindow, result);
    
    
    waitKey(0);
    
    return 0;
}
