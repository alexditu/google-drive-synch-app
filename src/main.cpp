#include <log.h>

int main(int argc, char** argv)
{
	configureDefaultLogger();

	spdlog::debug("{} started", argv[0]);

	return 0;
}