#include <iostream>
#include <string>

using namespace std;

class Medic;
class Accounts;

class PatientFile {
private:
    string fullName;
    string patientID;
    string birthDate;

    string healthNotes;
    string currentPlan;
    string invoiceDetails;

    void updateHealthNotes(const string& notes, const string& plan) {
        healthNotes = notes;
        currentPlan = plan;
    }

    void addInvoice(const string& invoice) {
        invoiceDetails = invoice;
    }

public:
    friend class Medic;
    friend class Accounts;

    PatientFile(string name, string id, string dob)
        : fullName(name), patientID(id), birthDate(dob),
          healthNotes("None"), currentPlan("None"), invoiceDetails("None") {}

    string showBasicInfo() const {
        return "Patient: " + fullName + ", ID: " + patientID + ", DOB: " + birthDate;
    }

    string showHealthData() const {
        return "Health Notes: " + healthNotes + ", Plan: " + currentPlan;
    }

    string showInvoice() const {
        return "Invoice: " + invoiceDetails;
    }
};

// Class for Doctors
class Medic {
public:
    void viewHealthInfo(const PatientFile& pf) const {
        cout << "[Medic] Viewing Patient Health Info:\n" << pf.showHealthData() << endl;
    }

    void updateHealthInfo(PatientFile& pf, const string& notes, const string& plan) {
        cout << "\n[Medic] Updating health record...\n";
        pf.updateHealthNotes(notes, plan);
    }
};

// Class for Billing Dept
class Accounts {
public:
    void viewInvoiceDetails(const PatientFile& pf) const {
        cout << "[Accounts] Viewing Billing Info:\n" << pf.showInvoice() << endl;
    }

    void modifyInvoice(PatientFile& pf, const string& newInvoice) {
        cout << "\n[Accounts] Adding billing record...\n";
        pf.addInvoice(newInvoice);
    }
};

// Receptionist — should only have public access
class FrontDesk {
public:
    void seePatientOverview(const PatientFile& pf) const {
        cout << "[FrontDesk] Viewing Basic Info:\n" << pf.showBasicInfo() << endl;
    }

    /*
    // These are blocked from compilation to prevent sensitive access

    void tryToPeekMedical(const PatientFile& pf) { cout << pf.showHealthData(); }        // ❌ Not allowed
    void tryToChangeTreatment(PatientFile& pf) { pf.updateHealthNotes("LOL", "Fake"); }  // ❌ Not allowed
    void tryToCheckBill(const PatientFile& pf) { cout << pf.showInvoice(); }             // ❌ Not allowed
    */
};

int main() {
    PatientFile pf("Liam Winchester", "PX-9001", "March 3, 1999");

    Medic doctor;
    Accounts accountant;
    FrontDesk receptionist;

    cout << "\n=== Receptionist viewing public info ===\n";
    receptionist.seePatientOverview(pf);

    cout << "\n=== Doctor checking & updating medical info ===\n";
    doctor.viewHealthInfo(pf);
    doctor.updateHealthInfo(pf, "Migraine & fatigue", "Prescribed rest + hydration");
    doctor.viewHealthInfo(pf);

    cout << "\n=== Billing team accessing invoice ===\n";
    accountant.viewInvoiceDetails(pf);
    accountant.modifyInvoice(pf, "Receipt #007: 3 platinum coins");
    accountant.viewInvoiceDetails(pf);

    cout << "\n=== Receptionist trying illegal access (won't compile if uncommented) ===\n";
    // receptionist.tryToPeekMedical(pf);
    // receptionist.tryToChangeTreatment(pf);
    // receptionist.tryToCheckBill(pf);

    return 0;
}
