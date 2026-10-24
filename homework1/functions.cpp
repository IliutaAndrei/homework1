#include <iostream>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include "file_info.h"
#include "functions.h"

namespace fs = std::filesystem;
using json = nlohmann::json;



void create_json(const std::string& filename, const std::vector<file_info>& files) {
	json result;
	result["files"] = json::array();

	for (const auto& file : files)
	{
		result["files"].push_back({
			{ "name", file.name },
			{ "size", file.size },
			{ "last_write", std::format("{}", file.last_write) },
			{ "extension", file.extension },
			});
	}

	std::ofstream fout(filename);
	if (!fout)
	{
		throw std::runtime_error("Cannot open file for writing: " + filename);
	}
	fout << result.dump(2);
	std::cout << "Json created!\n";
}

std::vector<file_info> get_files_from_path(const std::string& path)
{
	if (!fs::is_directory(path))
	{
		throw std::runtime_error("Not a valid directory: " + path);
	}

	std::vector<file_info> files;

	for (const auto& entry : fs::recursive_directory_iterator(path))
	{
		if (entry.is_regular_file())
		{
			files.push_back({
				entry.path().filename().string(),
				entry.file_size(),
				entry.last_write_time(),
				entry.path().extension().string()
				});
		}
	}

	return files;
}

void create_csv(const std::string& filename, const std::vector<file_info>& files)
{
	std::ofstream fout(filename);
	if (!fout)
	{
		throw std::runtime_error("Cannot open file for writing: " + filename);
	}

	fout << "name,size,last_write,extension\n";
	for (const auto& file : files)
	{
		fout << file.name << ", "
			<< file.size << " bytes , "
			<< file.last_write << ", "
			<< file.extension
			<< "\n";
	}
	std::cout << "Csv created!\n";

}