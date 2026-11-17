#pragma once



class Texture
{
private:
	int width, height, nrChannels;
	unsigned char* data;
	unsigned int texture;
public:
	void Load(const char* imgPath);
	void Initilize();
	void Bind();
	void Activate(unsigned int texNum);

};