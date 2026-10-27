#include <iostream>
using namespace std;

class Document{
    private:
        string title;
    protected:
        int pages;
    public:
        Document(string name, int count) : title(name), pages(count) {}
        string getTitle() {
            return title;
        }
        int getPages() {
            return pages;
        }
        void setTitle(string name) {
            title = name;
        }
};
class Booklet: public Document {
    private:
        int coverSheets;
    public:
        int getCoverSheets() {
            return coverSheets;
        }
        int sheetsPerCopy() {
            return (pages + 1) / 2 + coverSheets;
        }
        Booklet(string name, int count, int covers): Document(name,count), coverSheets(covers) {}
};
class PrintPlan {
    private:
        string title;
        int printedPages;
        int sheets;
    public:
        PrintPlan(string t, int pp, int s): title(t),printedPages(pp), sheets(s) {}
        void print() {
            cout << title << ": " << printedPages << " " << sheets;
        }
};
bool renameDocument(Document *document, std::string name) {
    if(document == nullptr)
        return false;
    document->setTitle(name);
    return true;
}
PrintPlan plan(Document &document, int copies)
{
    int docPages = document.getPages();
    int totalPages = docPages * copies;
    int totalSheets = docPages * copies;

    return PrintPlan(document.getTitle(), totalPages, totalSheets);
}
PrintPlan plan(Booklet &booklet, int copies)
{
    int totalPages = booklet.getPages() * copies;
    int sheetsPerCopy = booklet.sheetsPerCopy();
    int totalSheets = sheetsPerCopy * copies;

    return PrintPlan(booklet.getTitle(), totalPages, totalSheets);
}
int main() {
    string docTitle, bookletTitle, newTitle;
    int docPeages,bookletPages, coverSheets,copies;
    cin >> docTitle >> docPeages >> bookletTitle >> bookletPages >> coverSheets >> copies >> newTitle;
    Document document(docTitle, docPeages);
    Booklet booklet(bookletTitle, bookletPages, coverSheets);

    Document *common = &booklet;
    renameDocument(common, newTitle);

    cout << "Titles: " << document.getTitle() << " " << booklet.getTitle() << endl;

    PrintPlan plan1 = plan(document, copies);
    PrintPlan plan2 = plan(booklet, copies);
    PrintPlan plan3 = plan(*common, copies);

    cout << "Document plan: ";
    plan1.print();
    cout << endl;
    cout << "Booklet plan: ";
    plan2.print();
    cout << endl;
    cout << "Base plan: ";
    plan3.print();
    cout << endl;

    cout << "Unchanged pages: " << document.getPages()
         << " " << booklet.getPages() << endl;

    return 0;
}