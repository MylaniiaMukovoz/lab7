#include <iostream>
#include <string>

using namespace std;

class PrinterManager {
    private:
        bool hasPages;
        bool hasInk;
        static PrinterManager *instance;

        PrinterManager() = default;

    public:
        PrinterManager(const PrinterManager &) = delete;
        ~PrinterManager() {
            instance = NULL;
        }

        static PrinterManager *get_instance() {
            if(instance == NULL) {
                instance = new PrinterManager;
            }
            return instance;
        }

        void setHasPages(bool hasPages){
            this->hasPages = hasPages;
        }

        void setHasInk(bool hasInk){
            this->hasInk = hasInk;
        }

        string getHasPages(){
            if(hasPages) {
                return "yes.";
            } 
            else {
                return "no.";
            }
        }

        string getHasInk(){
            if(hasInk) {
                return "yes.";
            } 
            else {
                return "no.";
            }
        }
};

PrinterManager *PrinterManager::instance = NULL;

int main() {

    PrinterManager *ptr = PrinterManager::get_instance();
    ptr->setHasPages(true);
    ptr->setHasInk(true);

    cout << "Has pages: " << ptr->getHasPages() << endl;
    cout << "Has ink: " << ptr->getHasInk() << endl;
    cout << "PrinterManager: " << ptr->get_instance() << endl;

    PrinterManager *ptr2 = PrinterManager::get_instance();
    ptr2->setHasPages(false);
    ptr2->setHasInk(true);

    cout << "Has pages: " << ptr2->getHasPages() << endl;
    cout << "Has ink: " << ptr2->getHasInk() << endl;
    cout << "PrinterManager2: " << ptr2->get_instance() << endl;

    delete ptr;
    delete ptr2;

    return 0;
}