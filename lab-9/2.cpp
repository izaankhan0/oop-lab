#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LogSystem {
private:
    vector<string> entries;
    const int MAX_LOGS = 100;

    void appendLog(const string& level, const string& source, const string& note) {
        string entry = "[" + level + "] [" + source + "] " + note;
        if (entries.size() >= MAX_LOGS) {
            entries.erase(entries.begin()); // maintain size
        }
        entries.push_back(entry);
    }

public:
    void logDebug(const string& source, const string& note) {
        appendLog("DEBUG", source, note);
    }

    void logNotice(const string& source, const string& note) {
        appendLog("NOTICE", source, note);
    }

    void logCritical(const string& source, const string& note) {
        appendLog("CRITICAL", source, note);
    }

    // allow Inspector to access logs
    friend class Inspector;
};

class Inspector {
private:
    string name;
    string key;

    bool validateAccess() const {
        return key == "TopSecret321"; // pretend validation
    }

public:
    Inspector(const string& n, const string& k) : name(n), key(k) {}

    vector<string> fetchLogs(const LogSystem& systemRef) {
        if (validateAccess()) {
            return systemRef.entries;
        } else {
            cout << "Unauthorized: Access key incorrect.\n";
            return {};
        }
    }
};

// Simulated subsystems
void NetworkSim(LogSystem& logger) {
    logger.logDebug("NetCore", "Handshake successful.");
    logger.logNotice("NetCore", "Lag spikes noticed.");
    logger.logCritical("NetCore", "DNS lookup failed.");
}

void DatabaseSim(LogSystem& logger) {
    logger.logDebug("DataOps", "Data fetched cleanly.");
    logger.logNotice("DataOps", "Query took too long.");
    logger.logCritical("DataOps", "Connection lost.");
}

void AuthSim(LogSystem& logger) {
    logger.logDebug("AuthLayer", "Session initiated.");
    logger.logNotice("AuthLayer", "Suspicious login pattern.");
    logger.logCritical("AuthLayer", "Login bypass attempt.");
}

int main() {
    LogSystem coreLogger;

    // Simulate modules generating logs
    NetworkSim(coreLogger);
    DatabaseSim(coreLogger);
    AuthSim(coreLogger);

    // Attempt log viewing
    Inspector legitInspector("AgentX", "TopSecret321");   // Should work
    Inspector fakeInspector("NoobIntruder", "badkey123"); // Should fail

    cout << "\n--- Valid Inspector's Logs ---\n";
    vector<string> logs = legitInspector.fetchLogs(coreLogger);
    for (const string& logEntry : logs) {
        cout << logEntry << endl;
    }

    cout << "\n--- Invalid Inspector Attempt ---\n";
    fakeInspector.fetchLogs(coreLogger);

    return 0;
}
