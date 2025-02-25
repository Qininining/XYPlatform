#ifndef STAGE_H
#define STAGE_H

#include <QThread>
#include <QTimer>
#include <Eigen/Dense>
#include "MotionPlatform.h"

struct StageData {
    double positionX;
    double positionY;
    double speedX;
    double speedY;
    int statusX;
    int statusY;

    // Constructor to initialize all values to zero
    StageData()
        : positionX(0), positionY(0), speedX(0), speedY(0), statusX(0), statusY(0) {}
};

class Stage : public QThread
{
    Q_OBJECT

public:
    Stage(const char* stageID);
    ~Stage();

    void initialize();
    void shutdown();
    void stop();

    StageData getStageData() const;

    // Motion control functions
    bool gotoPositionAbsolute(int positionX, int positionY);
    bool gotoPositionRelative(int diffX, int diffY);
    bool setVelocity(int velocityX, int velocityY);
    bool stopMotion();
    bool moveJointPosition(const Eigen::Vector2d& jointPosition);

protected:
    void run() override;

private slots:
    void update();

private:
    MotionPlatform* platformX_;
    MotionPlatform* platformY_;
    bool threadSta_;
    QTimer* updateTimer_;
    QThread* platformThread_; // New thread for platformX_ and platformY_

    StageData stageData_;
};

#endif // STAGE_H
