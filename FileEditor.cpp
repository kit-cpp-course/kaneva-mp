
#include "FileEditor.hpp"
#include "Triangulations.hpp"
using namespace std;
const string name = "trig";

fileEditor::fileEditor(const std::string & path) {
    writeFile.open(path + name, ios::app);
}

void fileEditor::writing(Triangulations & triangles) {
    vector<triangle> tringls = triangles.triangulate();
    for (int i = 0; i < tringls.size(); i++) {
        writeFile << tringls[i].printPoints() << endl;
    }
}

fileEditor::~fileEditor() {
    writeFile.close();
}
