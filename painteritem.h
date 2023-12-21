#ifndef PAINTERITEM_H
#define PAINTERITEM_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>

class PainterItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit PainterItem(QQuickItem* parent = nullptr);
    void paint(QPainter *painter);

    Q_INVOKABLE QImage toImage();
    Q_INVOKABLE void clearImage();

    const QString &resultStr() const;
    void setResultStr(const QString &newResultStr);


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    // QQuickPaintedItem interface
private:
    std::vector<QPointF> m_linePoints;

};

#endif // PAINTERITEM_H
