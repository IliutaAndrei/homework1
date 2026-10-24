#include <iostream>
#include "file_info.h"
#include "functions.h"
#include "Exporter.h"


const std::string csv_filename = "11apriorit.csv";
const std::string json_filename = "11apriorit.json";

int main()
{
	try
	{
		std::string path;
		std::cout << "Path: ";
		std::getline(std::cin, path);
		std::vector<file_info> files = get_files_from_path(path);

		Exporter::create_exporter("csv")->export_report(csv_filename, files);
		Exporter::create_exporter("json")->export_report(json_filename, files);
	}
	catch (const std::exception& e)
	{
		std::cerr << "error: " << e.what() << "\n";
		return 1;
	}



}


