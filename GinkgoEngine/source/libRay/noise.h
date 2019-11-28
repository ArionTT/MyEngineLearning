#pragma once


#include<Vector.h>
#include"drand48.h"

namespace External
{
	static float *perlin_generate();

	// �ı����к���
	void permute(int *p, int n);

	static int *perlin_generate_perm();


	class perlin
	{
	public:
		float noise(const External::Vector3 &p) const;

		static float *ranfloat;
		static int *perm_x;
		static int *perm_y;
		static int *perm_z;
	};
}





