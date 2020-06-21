#include "curl_cpp_wrapper.h"

#include <spdlog/spdlog.h>

namespace {

std::size_t appendData(void *buffer, std::size_t size, std::size_t nMemb, void *context)
{
	curl_cpp::Curl* c = reinterpret_cast<curl_cpp::Curl*>(context);

	const std::size_t realSize = size * nMemb;

	c->appendData({reinterpret_cast<char*>(buffer), reinterpret_cast<char*>(buffer) + realSize});

	return realSize;
}

size_t addHeader(char *buffer, size_t size, size_t nItems, void *context)
{
	curl_cpp::Curl* c = reinterpret_cast<curl_cpp::Curl*>(context);

	const std::size_t realSize = size * nItems;

	c->addHeader({reinterpret_cast<char*>(buffer), reinterpret_cast<char*>(buffer) + realSize});

	return realSize;
}

} // anonymous namespace

namespace curl_cpp {

Curl::Curl(bool verbose)
{
	curl_ = curl_easy_init();
	if (!curl_) {
		throw std::runtime_error("[curl] curl_easy_init failed");
	}

	curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, ::appendData);
	curl_easy_setopt(curl_, CURLOPT_WRITEDATA, this);
	curl_easy_setopt(curl_, CURLOPT_ERRORBUFFER, curlErrorStr_);
	curl_easy_setopt(curl_, CURLOPT_HEADERFUNCTION, ::addHeader);
	curl_easy_setopt(curl_, CURLOPT_HEADERDATA, this);
	curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYPEER, 0L);

	if (verbose) {
		curl_easy_setopt(curl_, CURLOPT_VERBOSE, 1L);
	}
}

Curl::~Curl()
{
	curl_easy_cleanup(curl_);
}


std::string Curl::get(const std::string& url)
{
	curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());

	CURLcode res = curl_easy_perform(curl_);
	if (res != CURLE_OK) {
		throw std::runtime_error("[curl] curl_easy_perform returned " + std::to_string(res)
			+ " (" + curlErrorStr_ + ")");
	}

	return data_;
}

void Curl::appendData(std::string data)
{
	data_ += std::move(data);
}

void Curl::addHeader(std::string header)
{
	headers_.emplace_back(std::move(header));
}

} // namespace curl_cpp