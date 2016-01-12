#include "ImgClass.h"

int GETFRAMENUMBER = 5;

std::vector<UINT16> PixelReverce(std::vector<UINT16> depthBuffer, int Height, int Width)
{
	std::vector<UINT16> AfterBuffer;
	AfterBuffer.resize(Height * Width);
	int i = 0;
	for (i = 0; i < Height*Width; i++){
		AfterBuffer[i] = 8000 - depthBuffer[i];
	}
	return AfterBuffer;


}

std::vector<UINT16> HollFilling(std::vector<UINT16> depthBuffer, std::vector<UINT16> PreviousFrame, int Height, int Width)
{
	std::vector<UINT16> AfterBuffer;
	AfterBuffer.resize(Height * Width);
	int i = 0;
	AfterBuffer[0] = depthBuffer[0];
	for (i = 1; i < Height * Width - 1; i++)
	{
		if (depthBuffer[i] == 0){
			AfterBuffer[i] = PreviousFrame[i];

		}
		else
		{
			AfterBuffer[i] = depthBuffer[i];
		}
	}
	
	AfterBuffer[Height * Width - 1] = depthBuffer[Height * Width - 1];

	return AfterBuffer;
}

std::vector<ImgVector<UINT16>> PushBuffer(std::vector<ImgVector<UINT16>> Buffer)
{
	for (int i = 0; i < GETFRAMENUMBER - 1 ; i++)
	{
		Buffer[i].copy(Buffer[i + 1]);
	}
	return Buffer;

}

std::vector<UINT16> HollFillingMultipleFrame(std::vector < ImgVector<UINT16> > depthBuffer, int Height, int Width)
{
	//depthBuffer[FrameNumber][PixelIndex]
	
	std::vector<UINT16> AfterBuffer;
	AfterBuffer.resize(Height * Width);
	int i = 0, j = 0;
	AfterBuffer[0] = depthBuffer[GETFRAMENUMBER].at(0,0);
	for (j = 1; j < Height * Width - 1; j++)
	{
		for (int y = 1; y < Height; y++){
			for (int x = 1; x < Width; x++){
				
			}
		}
	}

	AfterBuffer[Height * Width - 1] = depthBuffer[GETFRAMENUMBER].at(Width - 1,Height - 1);

	return AfterBuffer;
}