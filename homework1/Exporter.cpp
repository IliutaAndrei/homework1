#include "Exporter.h"
#include "functions.h"
#include <memory>
#include <string>

class CsvExporter : public Exporter {
public:
	void export_report(const std::string& filename, const std::vector<file_info>& files) override
	{
		create_csv(filename, files);
	}
};


class JsonExporter : public Exporter {
public:
	void export_report(const std::string& filename, const std::vector<file_info>& files) override
	{
		create_json(filename, files);
	}
};

std::unique_ptr<Exporter> Exporter::create_exporter(const std::string& format) {
	if (format == "csv") return std::make_unique<CsvExporter>();
	if (format == "json") return std::make_unique<JsonExporter>();

	throw std::runtime_error("Unsupported format: " + format);
}
