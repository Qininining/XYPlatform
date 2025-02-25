#ifndef STAGE_H
#define STAGE_H

#include <QThread>
#include <QTimer>
#include "MotionPlatform.h"

class Stage : public QThread
{
    Q_OBJECT

public:
    Stage(const char* stageID);
    ~Stage();

    void initialize();
    void shutdown();
    void stop();

protected:
    void run() override;

private slots:
    void update();

private:
    MotionPlatform* platformX_;
    MotionPlatform* platformY_;
    bool threadSta_;
    QTimer* updateTimer_;

    // Member variables to store position, speed, and status
    double positionX_;
    double positionY_;
    double speedX_;
    double speedY_;
    int statusX_;
    int statusY_;
};

#endif // STAGE_H
