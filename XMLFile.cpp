# include "XMLFile.h"

XMLFile::XMLFile( string fileName )
    : FILE_NAME(fileName)
{
    isXMLFileExist();
}

void XMLFile::isXMLFileExist()
{
    if (!xmlFile.Load(FILE_NAME))
        createXMLFile();
}

void XMLFile::createXMLFile()
{
    xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xmlFile.AddElem("BulkData");
    xmlFile.Save(FILE_NAME);
}
