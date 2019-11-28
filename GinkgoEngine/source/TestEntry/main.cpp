

#define TEST_RAYTRACE

#if defined(TEST_IMAGE)

#include<libImage.h>
using namespace External;

#include<iostream>

int main()
{
	//const char* path = "123.png";
	//const char* path = "456.jpg";
	const char* path = "palermo_square_4k.hdr";
	//const char* path = "789.tga";
	//const char* path = "1023.dds";
	ImageFileType fileType = ImageFileType::IMG_HDR;
	texture_data* tex_data = loadTexture(path, fileType);

	if (tex_data == nullptr)
		return -1;

	//printf("=================\n");
	//printf("Size: %d  %d  channel: %d \n", tex_data->width, tex_data->height, tex_data->channel);
	//printf("=================\n");

	return 0;
}

#endif//TEST_IMAGE

#if defined(TEST_RAYTRACE)

#include<Math.h>
#include<Vector.h>
#include<Ray.h>
#include<RayCamera.h>
#include<Hitable.h>
#include<RayTrace.h>
#include<RayTexture.h>
#include<Sphere.h>

#include<libImage.h>
using namespace External;

#include<stdio.h>
#include<stdlib.h>
#include <time.h>		// MILO

//#include<iostream>


int main()
{
	int w = 800, h = 600;
	int sample = 100;

	Vector3* colors = new Vector3[w*h];
	unsigned char* color_data = new unsigned char[w*h*3];

	Vector3 lookfrom(3.0f, 3.0f, 3.0f);
	Vector3 lookat(0, 0.0f, -1.0f);
	Vector3 dir = Vector3::Normalize(lookat - lookfrom);
	Vector3 world_up(0, 1, 0);
	Vector3 left = Vector3::Cross(world_up, dir);
	Vector3 up = Vector3::Cross( dir, left);

	RayCamera cam(lookfrom, lookat, up, 60.0f, (float)w / (float)h);

	Hitable* list[4];
	// ÆåÅÌÎÆÀí
	ray_texture *checker = new checker_texture(new constant_texture(Vector3(0.8, 0.1, 0.1)), new constant_texture(Vector3(0.9, 0.9, 0.9)));
	ray_texture* nosier = new noise_texture();

	list[0] = new Sphere(Vector3(0, 0, -1), 0.5f, new LambertianMat(checker));// new constant_texture(vec3(0.5f, 0.2f, 0.2f))));
	list[1] = new Sphere(Vector3(0, -300.5f, -1), 300.0f, new LambertianMat(nosier));// new constant_texture(vec3(0.4f, 0.4f, 0.4f))));//new metal(vec3(0.9f, 0.9f, 0.9f), 0.02f));//
	//list[2] = new Sphere(Vector3(1.0f, 0.0f, -1), 0.5f, new MetalMat(Vector3(0.9f, 0.9f, 0.9f), 0.2f));
	list[2] = new Sphere(Vector3(1.0f, 0.0f, -1), 0.5f, new DielectricMat(1.4f, 0.001f));
	list[3] = new Sphere(Vector3(-1.0f, 0.0f, -1), 0.5f, new MetalMat(Vector3(0.9f, 0.9f, 0.9f), 0.05f));

	Hitable_list* world = new Hitable_list(list, 4);

	printf("[Start]\n");
	clock_t start = clock(); // MILO

	for (int j = h - 1; j > 0; j--)
	{
		for (int i = 0; i < w; i++)
		{
			Vector3 col = Vector3();

			for (int z = 0; z < sample; z++)
			{
				float rd = drand48();

				float u = (float)(i + rd) / (float)w;
				float v = (float)(j + rd) / (float)h;

				int depth = 0;

				Ray r = RayTracer::generateRay(cam, u, v);
				col += RayTracer::rayTrace(r, world, depth);
			}


			float time_s = (h - j - 1)*w + i;
			float progress = 100.0f * (float)time_s / (float)(w*h);
			printf("[Progress] %f % \r ",progress );

			col /= sample;
			col = Vector3(External::sqrt(col.x), External::sqrt(col.y), External::sqrt(col.z));

			colors[(h - j - 1)*w + i] = col;

			color_data[((h - j - 1)*w + i) * 3 + 0] = (unsigned char)(int)(col.x*255.0f);
			color_data[((h - j - 1)*w + i) * 3 + 1] = (unsigned char)(int)(col.y*255.0f);
			color_data[((h - j - 1)*w + i) * 3 + 2] = (unsigned char)(int)(col.z*255.0f);
		}
	}
	printf("[End]\n");

	printf("[ Saving Texture ]\n");
	const char* path = "raytrace.png";
	ImageFileType fileType = ImageFileType::IMG_PNG;
	texture_data td;
	td.channel = 3;
	td.width = w;
	td.height = h;
	td.data_byte = color_data;
	td.depth = 0;
	td.texture_type = ImageType::IMG_2D;
	td.date_type = ImageDateType::IMG_BYTE;
	ImageError error = writeTexture(path, &td , fileType);
	if (error != ImageError::IMG_NONE)
	{
		printf("[Error] %d \n", error);
	}


	system("PAUSE");

	return 0;
}

#endif//TEST_RAYTRACE
