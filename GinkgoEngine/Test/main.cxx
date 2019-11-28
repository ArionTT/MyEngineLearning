#include<iostream>
#include<GinkgoEngineConfig.h>

#ifdef USE_MYMATH
#include "mysqrt.h"
#else
#include<math.h>
#endif

int main(int argc, char *argv[])
{
	if (argc < 2) {
		// report version
		std::cout << argv[0] << " Version " << GinkgoEngine_VERSION_MAJOR << "."
			<< GinkgoEngine_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}

	float  inputValue = 10;
#ifdef USE_MYMATH
	const double outputValue = mysqrt(inputValue);
#else
	const double outputValue = sqrt(inputValue);
#endif

	std::cout << "Srqt:" << outputValue << std::endl;

	std::cout << "Argv:" << argv[1] << std::endl;

	std::cout << "Hello World: CMAKE \n" << std::endl;
	return 0;
}