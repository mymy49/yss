#include <hal/ResistiveTouch.h>

ResistiveTouch::ResistiveTouch()
{
	mCalibrationData.topLeftX = 0;
	mCalibrationData.topLeftY = 0;
	mCalibrationData.botRightX = 4095;
	mCalibrationData.botRightY = 4095;
	mCalibrationData.width = 320;
	mCalibrationData.height = 240;
	update();
}

void ResistiveTouch::setCalibrationData(calibration_t data)
{
	mCalibrationData = data;	
	update();
}

ResistiveTouch::calibration_t ResistiveTouch::getCalibrationData()
{
	return mCalibrationData;
}

Position ResistiveTouch::calculate(uint16_t x, uint16_t y)
{
	mLastConvertedAdcX = x;
	mLastConvertedAdcY = y;
	x = ((int32_t)x - mCalibrationData.topLeftX) * mCalibrationData.width / mXDivider;
	y = ((int32_t)y - mCalibrationData.topLeftY) * mCalibrationData.height / mYDivider;

	if(x < 0)
		x = 0;
	else if(x > mCalibrationData.width)
		x = x > mCalibrationData.width;
	if(y < 0)
		y = 0;
	else if(y > mCalibrationData.height)
		y = y > mCalibrationData.height;

	mPosition.setPosition(x, y);
	return mPosition;
}

uint16_t ResistiveTouch::calculateX(uint16_t x)
{
	mLastConvertedAdcX = x;
	x = ((int32_t)x - mCalibrationData.topLeftX) * mCalibrationData.width / mXDivider;
	mPosition.setX(x);
	if(x < 0)
		x = 0;
	else if(x > mCalibrationData.width)
		x = x > mCalibrationData.width;
	return x;
}

uint16_t ResistiveTouch::calculateY(uint16_t y)
{
	mLastConvertedAdcY = y;
	y = ((int32_t)y - mCalibrationData.topLeftY) * mCalibrationData.height / mYDivider;
	mPosition.setY(y);
	if(y < 0)
		y = 0;
	else if(y > mCalibrationData.height)
		y = y > mCalibrationData.height;
	return y;
}

uint16_t ResistiveTouch::getLastConvertedAdcX()
{
	return mLastConvertedAdcX;
}

uint16_t ResistiveTouch::getLastConvertedAdcY()
{
	return mLastConvertedAdcY;
}

void ResistiveTouch::update()
{
	mXDivider = (int32_t)(mCalibrationData.botRightX - mCalibrationData.topLeftX);
	mYDivider = (int32_t)(mCalibrationData.botRightY - mCalibrationData.topLeftY);
	mPosition.setMaxPosition(mCalibrationData.width, mCalibrationData.height);
}

