#ifndef XMLFILE_H_INCLUDED
#define XMLFILE_H_INCLUDED

#include <vector>
#include "Markup.h"

using namespace std;

class XMLFile
{
    void isXMLFileExist();
    void createXMLFile();

protected:
    const string FILE_NAME;
    CMarkup xmlFile;

public:
    XMLFile( string fileName );
};

#endif // XMLFILE_H_INCLUDED
