#pragma once

//#include<Vector.h>

namespace External{

	enum ImageError {
		IMG_NONE = 0,
		IMG_EMPTY = 1,
		IMG_CANT_MISMATCH =2,
		IMG_TYPE_ERROR = 3,
	};

	enum ImageDateType {
		IMG_BYTE,
		IMG_FLOAT,
	};

	enum ImageType {
		IMG_2D,
		IMG_CUBE,
		IMG_3D,
	};

	enum ImageFileType {
		IMG_JPEG = 0,
		IMG_PNG =1,
		IMG_HDR=2,
		IMG_DDS=3,
		IMG_TGA=4,
		IMG_BMP=5,
	};

	typedef struct _texture_data {
		ImageDateType date_type;
		ImageType texture_type;
		unsigned char* data_byte;
		float* date_float;
		unsigned int width;
		unsigned int height;
		unsigned int depth;
		unsigned channel;
	} texture_data;
	typedef texture_data* tex_ptr;


	tex_ptr loadTexture(const char* _path, ImageFileType _fileType);

	ImageError writeTexture(const char* _path, tex_ptr _tex2d, ImageFileType _fileType);

	tex_ptr loadTextureFromStream(const char* _path, ImageFileType _fileType);

	ImageError writeTextureFromStream(const char* _path, tex_ptr _tex2d, ImageFileType _fileType);

	//tex_ptr ConvertVector3ArrayToImageData(const Vector3** _array, int _w, int _h, int _c, bool _isHDR = false);

}

