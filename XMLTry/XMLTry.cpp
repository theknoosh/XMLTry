
#include <iostream>
#include <sstream>
using namespace std;
#include <stdio.h>
#include "tinyxml.h"


int main(void)
{
	TiXmlDocument doc("sample.xml");
	bool loadOkay = doc.LoadFile();
	if(loadOkay){
		TiXmlNode *ResourceTree = doc.FirstChild("resources");
		if(ResourceTree){
			for(TiXmlNode *child = ResourceTree->FirstChild();child;child = child->NextSibling())
			{
				TiXmlElement *element = child->ToElement();
				if(element)
				{
					for(TiXmlAttribute *elementAttrib = element->FirstAttribute();elementAttrib; elementAttrib = elementAttrib->Next())
					{
						printf("%s = %s\n",elementAttrib->Name(), elementAttrib->Value());
					}
				printf("\n");
				}
			}

		}
		
		// printf("Succesful Load of XML File\n\n");
	}else
	{
		printf("Failed to load file");
	}
	system("pause");
	return 0;
}