#ifndef IMAGEANALYZER_H
#define IMAGEANALYZER_H

#include <QObject>
#include <QImage>

class ImageAnalyzer : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString resultStr READ resultStr WRITE setResultStr NOTIFY resultStrChanged FINAL);
      QString m_resultStr = "nan";

public:
    ImageAnalyzer();

    Q_INVOKABLE void analyzeImage(QImage img);
    const QString &resultStr() const;
    void setResultStr(const QString &newResultStr);
Q_SIGNALS:
    void resultStrChanged();
private:

};

#endif // IMAGEANALYZER_H
