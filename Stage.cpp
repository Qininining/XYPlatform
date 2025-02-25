#include "Stage.h"
// #include <QCoreApplication>

Stage::Stage(const char* stageID)
    : threadSta_(true)
{
    platformX_ = new MotionPlatform(stageID, 0);
    platformY_ = new MotionPlatform(stageID, 1);
    updateTimer_ = new QTimer();
    connect(updateTimer_, &QTimer::timeout, this, &Stage::update);
    platformThread_ = new QThread();
    // Move platformX_ and platformY_ to the new thread
    platformX_->moveToThread(platformThread_);
    platformY_->moveToThread(platformThread_);
    platformThread_->start();
    // Initialize StageData
    stageData_ = StageData();
    // Constructor implementation
}

Stage::~Stage()
{
    shutdown();
    delete platformX_;
    delete platformY_;
    delete updateTimer_;
    delete platformThread_;
    // Destructor implementation
}

void Stage::initialize()
{
    platformX_->connect();
    platformY_->connect();
    updateTimer_->start(50); // Update every second
}

void Stage::shutdown()
{
    stop();
    platformX_->disConnect();
    platformY_->disConnect();
    platformThread_->quit();
    platformThread_->wait();
}

void Stage::run()
{
    // updateTimer_->start(1000); // Update every second
    while (threadSta_)
    {
        // QCoreApplication::processEvents();
        // Infinite loop implementation
    }
}

void Stage::stop()
{
    threadSta_ = false;
    updateTimer_->stop();
}

void Stage::update()
{
    // Update position, speed, and status from MotionPlatform
    int posX, posY;
    signed int velX, velY;
    NT_STATUS staX, staY;

    platformX_->getPosition(posX);
    platformY_->getPosition(posY);
    platformX_->getVelocity(velX);
    platformY_->getVelocity(velY);
    platformX_->getsta(staX);
    platformY_->getsta(staY);

    stageData_.positionX = posX;
    stageData_.positionY = posY;
    stageData_.speedX = velX;
    stageData_.speedY = velY;
    stageData_.statusX = staX;
    stageData_.statusY = staY;
}

bool Stage::getStageData(StageData &stageData) const
{
    stageData = stageData_;
    return true;
}

// Motion control functions
bool Stage::gotoPositionAbsolute(int positionX, int positionY)
{
    bool resultX = platformX_->gotoPositionAbsolute(positionX);
    bool resultY = platformY_->gotoPositionAbsolute(positionY);
    return resultX && resultY;
}

bool Stage::gotoPositionRelative(int diffX, int diffY)
{
    bool resultX = platformX_->gotoPositionRelative(diffX);
    bool resultY = platformY_->gotoPositionRelative(diffY);
    return resultX && resultY;
}

bool Stage::setVelocity(int velocityX, int velocityY)
{
    bool resultX = platformX_->setVelocity(velocityX);
    bool resultY = platformY_->setVelocity(velocityY);
    return resultX && resultY;
}

bool Stage::stopMotion()
{
    bool resultX = platformX_->stop();
    bool resultY = platformY_->stop();
    return resultX && resultY;
}

bool Stage::moveJointPosition(const Eigen::Vector2d& jointPosition)
{
    int positionX = static_cast<int>(jointPosition(0));
    int positionY = static_cast<int>(jointPosition(1));
    return gotoPositionAbsolute(positionX, positionY);
}
