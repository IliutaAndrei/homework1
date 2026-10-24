#pragma once
#include <iostream>
#include <vector>
#include "file_info.h"

class Exporter
{
public:
	virtual ~Exporter() = default;

	virtual void export_report(const std::string& filename, const std::vector<file_info>& files) = 0;

	static std::unique_ptr<Exporter> create_exporter(const std::string& format);
};


