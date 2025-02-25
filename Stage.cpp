#include "Stage.h"
#include <QCoreApplication>

Stage::Stage(const char* stageID)
    : threadSta_(true), positionX_(0), positionY_(0), speedX_(0), speedY_(0), statusX_(0), statusY_(0)
{
    platformX_ = new MotionPlatform(stageID, 1);
    platformY_ = new MotionPlatform(stageID, 0);
    updateTimer_ = new QTimer(this);
    connect(updateTimer_, &QTimer::timeout, this, &Stage::update);
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
    updateTimer_->start(1000); // Update every second
    platformX_->connect();
    platformY_->connect();
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
//         QCoreApplication::processEvents();
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

    positionX_ = posX;
    positionY_ = posY;
    speedX_ = velX;
    speedY_ = velY;
    statusX_ = staX;
    statusY_ = staY;
}
