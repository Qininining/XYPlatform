#include "Stage.h"
#include <QCoreApplication>

Stage::Stage(const char* stageID)
    : threadSta_(true)
{
    platformX_ = new MotionPlatform(stageID, 1);
    platformY_ = new MotionPlatform(stageID, 0);
    updateTimer_ = new QTimer(this);
    connect(updateTimer_, &QTimer::timeout, this, &Stage::update);
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
    // Destructor implementation
}

void Stage::initialize()
{
    platformX_->connect();
    platformY_->connect();
    updateTimer_->start(1000); // Update every second
}

void Stage::shutdown()
{
    stop();
    platformX_->disConnect();
    platformY_->disConnect();
}

void Stage::run()
{
    // updateTimer_->start(1000); // Update every second
    while (threadSta_)
    {
//                 QCoreApplication::processEvents();
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

StageData Stage::getStageData() const
{
    return stageData_;
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
