/***********************************************************************
    filename:   CEGUIRapidXMLParser.h
    created:    Mar 27 2010
    author:     Jay Sprenkle
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2010 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIRapidXMLParser_h_
#define _CEGUIRapidXMLParser_h_

#include "../../CEGUIXMLParser.h"

#if (defined( __WIN32__ ) || defined( _WIN32 )) && !defined(CEGUI_STATIC)
#   ifdef CEGUIRAPIDXMLPARSER_EXPORTS
#       define CEGUIRAPIDXMLPARSER_API __declspec(dllexport)
#   else
#       define CEGUIRAPIDXMLPARSER_API __declspec(dllimport)
#   endif
#else
#   define CEGUIRAPIDXMLPARSER_API
#endif

// Start of CEGUI namespace section
namespace CEGUI
{
//! Implementation of XMLParser using RapidXML
class CEGUIRAPIDXMLPARSER_API RapidXMLParser : public XMLParser
{
public:
    RapidXMLParser(void);
    ~RapidXMLParser(void);

    // Implementation of public abstract interface
    void parseXMLFile(XMLHandler& handler, const String& filename,
                      const String& schemaName, const String& resourceGroup);

protected:
    // Implementation of abstract interface.
    bool initialiseImpl(void);
    void cleanupImpl(void);
};

} // End of  CEGUI namespace section


#endif  // end of guard _CEGUIRapidXMLParser_h_

