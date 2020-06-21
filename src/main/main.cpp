#include <log.h>
#include <curl_cpp_wrapper.h>

int main(int argc, char** argv)
{
	configureDefaultLogger();

	spdlog::debug("{} started", argv[0]);

	const std::string url = "https://postman-echo.com/get?foo1=bar1";

	try {
		curl_cpp::Curl curl(true);
		std::string result = curl.get(url);

		spdlog::debug("result:\n{}", result);

	} catch (const std::exception& e) {
		spdlog::error("exception: {}", e.what());
	} catch (...) {
		spdlog::error("exception: unknown");
	}

	return 0;
}