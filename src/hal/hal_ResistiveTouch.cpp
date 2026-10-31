#include <hal/ResistiveTouch.h>

ResistiveTouch::ResistiveTouch()
{
	mCalibrationData.topLeftX = 819;
	mCalibrationData.topLeftY = 819;
	mCalibrationData.botRightX = 3276;
	mCalibrationData.botRightY = 3276;
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
	x = ((int32_t)x - mCalibrationData.topLeftX) * mCalibrationData.width / mXDivider + mWidthOffset;
	y = ((int32_t)y - mCalibrationData.topLeftY) * mCalibrationData.height / mYDivider + mHeightOffset;
	mPosition.setPosition(x, y);
	return mPosition;
}

uint16_t ResistiveTouch::calculateX(uint16_t x)
{
	mLastConvertedAdcX = x;
	x = ((int32_t)x - mCalibrationData.topLeftX) * mCalibrationData.width / mXDivider + mWidthOffset;
	mPosition.setX(x);
	return x;
}

uint16_t ResistiveTouch::calculateY(uint16_t y)
{
	mLastConvertedAdcY = y;
	y = ((int32_t)y - mCalibrationData.topLeftY) * mCalibrationData.height / mYDivider + mHeightOffset;
	mPosition.setY(y);
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
	mXDivider = (int32_t)(mCalibrationData.botRightX - mCalibrationData.topLeftX) * 10 / 6;
	mYDivider = (int32_t)(mCalibrationData.botRightY - mCalibrationData.topLeftY) * 10 / 6;
	mWidthOffset = (int32_t)mCalibrationData.width * 2 / 10;
	mHeightOffset = (int32_t)mCalibrationData.height * 2 / 10;
	mPosition.setMaxPosition(mCalibrationData.width, mCalibrationData.height);
}

