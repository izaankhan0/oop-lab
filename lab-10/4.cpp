#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

const string activeLog = "activity.txt";
const size_t fileLimit = 1024 * 1024; // 1MB in bytes

// Rolls over the log file if it exceeds the size threshold
void rolloverLog() {
    if (fs::exists(activeLog) && fs::file_size(activeLog) >= fileLimit) {
        int count = 1;
        string archiveName;

        do {
            archiveName = "activity" + to_string(count++) + ".txt";
        } while (fs::exists(archiveName));

        fs::rename(activeLog, archiveName);
    }
}

// Appends a single line to the active log
void appendLog(const string& entry) {
    rolloverLog();

    ofstream writer(activeLog, ios::app);
    if (!writer) {
        cerr << "Error: Unable to open log file.\n";
        return;
    }

    writer << entry << endl;
    writer.close();
}

int main() {
    for (int i = 0; i < 200000; ++i) {
        appendLog("Event log number: " + to_string(i));
    }

    cout << "All entries logged successfully.\n";
    return 0;
}
