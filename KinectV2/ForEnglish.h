std::vector<UINT16> ProcessImage(std::vector<UINT16> depthBuffer , int Height, int Width)
{
	std::vector<UINT16> AfterBuffer;
	AfterBuffer.resize(Height * Width);
	int i = 0;
	for (i = 0; i < Height*Width; i++){
		AfterBuffer[i] = 8000 - depthBuffer[i];
	}
	return AfterBuffer;

}