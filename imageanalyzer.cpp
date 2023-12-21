#include "imageanalyzer.h"
#include <QtDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
using namespace cv;
using namespace std;
ImageAnalyzer::ImageAnalyzer()
{

}

void ImageAnalyzer::analyzeImage(QImage image2)
{
    qDebug() << "Analyzer here ... ";
    cv::Mat image(image2.height(), image2.width(), CV_8UC4, image2.bits());

    Ptr<ml::ANN_MLP> mlp = ml::ANN_MLP::load("/home/ahmed/coding/opencvprojects/handwrittingrecognition/handwrittenDigitsRecognition/data/trained_digit_model.xml");
    cv::cvtColor(image, image, COLOR_RGBA2GRAY);

    cv::resize(image,image,cv::Size(28,28));
    // Flatten the image
    Mat flattenedImage = image.reshape(1, 1);
    Mat input;
    flattenedImage.convertTo(input, CV_32F);

    // Perform prediction
    Mat output;
    mlp->predict(input, output);


    cout<<output<<std::endl;
    // Find the class with the highest probability
    Point classIdPoint;
    double confidence;
    minMaxLoc(output, nullptr, &confidence, nullptr, &classIdPoint);

    int predictedClass = classIdPoint.x;

    cout << "Prediction: " << predictedClass << " Confidence: " << confidence << endl;
    QString result = "Recognized digit is " + QString::number(predictedClass) ;
    setResultStr(result);
}

const QString &ImageAnalyzer::resultStr() const
{
    return m_resultStr;
}

void ImageAnalyzer::setResultStr(const QString &newResultStr)
{
    if (m_resultStr == newResultStr)
        return;
    m_resultStr = newResultStr;
    emit resultStrChanged();
}
