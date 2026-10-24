#pragma once
#include <filesystem>
#include <string>


struct file_info {
	std::string name;
	std::uintmax_t size = 0;;
	std::filesystem::file_time_type last_write{};
	std::string extension;
};