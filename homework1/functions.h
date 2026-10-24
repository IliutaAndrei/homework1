#pragma once
#include "file_info.h"
#include <vector>
#include <string>

void create_csv(const std::string& filename, const std::vector<file_info>& files);

void create_json(const std::string& filename, const std::vector<file_info>& files);

std::vector<file_info> get_files_from_path(const std::string& path);