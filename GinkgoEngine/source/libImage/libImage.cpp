#include "libImage.h"

#include"stb/stb_image.h"
#include"stb/stb_image_write.h"

namespace External {

	unsigned char* loadPng(const char* _path, unsigned int& _width, unsigned int& _height, unsigned int& _ch) {
		unsigned char* data = stbi_load(_path, (int*)&_width, (int*)&_height, (int*)&_ch, 4);
		return data;
	}

	unsigned char* loadJpg(const char* _path, unsigned int& _width, unsigned int& _height, unsigned int& _ch) {
		unsigned char* data = stbi_load(_path, (int*)&_width, (int*)&_height, (int*)&_ch, 3);
		return data;
	}

	unsigned char* loadDds(const char* _path, unsigned int& _width, unsigned int& _height, unsigned int& _ch) {
		return nullptr;
	}

	void writeDds(const char* _path,unsigned char* data , unsigned int _width, unsigned int _height, unsigned int _ch) {

	}

	unsigned char* loadTga(const char* _path, unsigned int& _width, unsigned int& _height, unsigned int& _ch) {
		unsigned char* data = stbi_load(_path, (int*)&_width, (int*)&_height, (int*)&_ch, 4);
		return data;
	}

	float* loadHdr(const char* _path, unsigned int& _width, unsigned int& _height, unsigned int& _ch) {
		float* data = stbi_loadf(_path, (int*)&_width, (int*)&_height, (int*)&_ch, 4);
		return data;
	}

	tex_ptr loadTexture(const char * _path, ImageFileType _fileType) {
		unsigned int w = 0, h = 0,d = 0, c = 0;
		unsigned char* data_byte = nullptr;
		float* data_float = nullptr;
		ImageDateType data_type = ImageDateType::IMG_BYTE;
		ImageType texture_type = ImageType::IMG_2D;
		switch (_fileType) {
		case External::IMG_JPEG:
			texture_type = ImageType::IMG_2D;
			data_type = ImageDateType::IMG_BYTE;
			data_byte = loadJpg(_path, w, h, c);
			break;
		case External::IMG_PNG:
			texture_type = ImageType::IMG_2D;
			data_type = ImageDateType::IMG_BYTE;
			data_byte = loadPng(_path, w, h, c);
			break;
		case External::IMG_HDR:
			texture_type = ImageType::IMG_2D;
			data_type = ImageDateType::IMG_FLOAT;
			data_float = loadHdr(_path, w, h, c);
			break;
		case External::IMG_DDS:
			break;
		case External::IMG_TGA:
			break;
		case External::IMG_BMP:
			break;
		default:
			break;
		}
		texture_data* tData = new texture_data();
		tData->data_byte = data_byte;
		tData->date_float = data_float;
		tData->width = w;
		tData->height = h;
		tData->channel = c;
		tData->depth = d;
		tData->date_type = data_type;
		tData->texture_type = texture_type;

		return tData;
	}

	ImageError writeTexture(const char * _path, tex_ptr _tex2d, ImageFileType _fileType) {
		ImageError error = ImageError::IMG_NONE;
		int w = _tex2d->width, 
			h = _tex2d->height, 
			d = _tex2d->depth, 
			c = _tex2d->channel;
		ImageDateType data_type = _tex2d->date_type;
		ImageType texture_type = _tex2d->texture_type;
		unsigned char* data_byte = _tex2d->data_byte;
		float* data_float = _tex2d->date_float;
		switch (_fileType) {
		case External::IMG_JPEG:
			stbi_write_jpg(_path, w, h, c, data_byte, 1);
			break;
		case External::IMG_PNG:
			stbi_write_png(_path, w, h, c, data_byte, w * c);
			break;
		case External::IMG_HDR:
			stbi_write_hdr(_path, w, h, c, data_float);
			break;
		case External::IMG_DDS:
			writeDds(_path, data_byte,w, h, c);
			break;
		case External::IMG_TGA:
			stbi_write_tga(_path, w, h, c, data_byte);
			break;
		case External::IMG_BMP:
			stbi_write_bmp(_path, w, h, c, data_byte);
			break;
		default:
			error = ImageError::IMG_TYPE_ERROR;
			return error;
		}
		return error;
	}

	tex_ptr loadTextureFromStream(const char * _path, ImageFileType _fileType) {
		return tex_ptr();
	}

	ImageError writeTextureFromStream(const char * _path, tex_ptr _tex2d, ImageFileType _fileType) {
		return ImageError();
	}

	//tex_ptr ConvertVector3ArrayToImageData(const Vector3 ** _array, int _w, int _h, int _c, bool _isHDR)
	//{
	//	const Vector3* arr = *_array;

	//	tex_ptr data = new texture_data();
	//	data->width = _w;
	//	data->height = _h;
	//	data->channel = _c;
	//	data->texture_type = ImageType::IMG_2D;
	//	if (_isHDR)
	//	{
	//		data->date_type = ImageDateType::IMG_FLOAT;
	//		data->date_float = new float[_w*_h*_c];
	//		for (int i = 0; i < _w; i++)
	//		{
	//			for (int j = 0; j < _h; j++)
	//			{
	//				data->date_float[(j*_w + i) * 3 + 0] = arr[(j*_w + i)].x;
	//				data->date_float[(j*_w + i) * 3 + 1] = arr[(j*_w + i)].y;
	//				data->date_float[(j*_w + i) * 3 + 2] = arr[(j*_w + i)].z;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		data->date_type = ImageDateType::IMG_BYTE;
	//		data->data_byte = new unsigned char[_w*_h*_c];
	//		for (int i = 0; i < _w; i++)
	//		{
	//			for (int j = 0; j < _h; j++)
	//			{
	//				data->data_byte[(j*_w + i) * 3 + 0] = (unsigned char)((int)(arr[(j*_w + i)].x*255.0f));
	//				data->data_byte[(j*_w + i) * 3 + 1] = (unsigned char)((int)(arr[(j*_w + i)].y*255.0f));
	//				data->data_byte[(j*_w + i) * 3 + 2] =(unsigned char)((int)( arr[(j*_w + i)].z*255.0f));
	//			}
	//		}
	//	}

	//	return data;
	//}

}