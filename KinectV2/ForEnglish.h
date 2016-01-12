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

