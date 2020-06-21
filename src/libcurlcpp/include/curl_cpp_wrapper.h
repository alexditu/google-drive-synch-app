#ifndef __CURL_CPP_WRAPPER_H_INCLUDED__
#define __CURL_CPP_WRAPPER_H_INCLUDED__

#include <string>
#include <vector>

#include <curl/curl.h>

#define DLL_PUBLIC __attribute__ ((visibility ("default")))

namespace curl_cpp {

class DLL_PUBLIC Curl {
public:
	Curl(bool verbose = false);
	~Curl();

	Curl(const Curl&) = delete;
	Curl& operator=(const Curl&) = delete;

	std::string get(const std::string& url);

	void appendData(std::string data);
	void addHeader(std::string header);

private:
	CURL *curl_ {nullptr};

	std::string data_;
	char curlErrorStr_[CURL_ERROR_SIZE] {0};
	std::vector<std::string> headers_;
};

} // namespace curl_cpp

#endif // __CURL_CPP_WRAPPER_H_INCLUDED__
