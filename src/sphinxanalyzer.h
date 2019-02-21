//
// $Id$
//

//
// Copyright (c) 2019, Randy
// Copyright (c) 2019, Sogou Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#ifndef _sphinx_analyzer_
#define _sphinx_analyzer_

#include "sphinxstd.h"


class ISphAnalyzer
{
public:
    /// trivial ctor
                                    ISphAnalyzer();

    /// trivial dtor
    virtual                         ~ISphAnalyzer () {}

    /// setup analyzer using given settings
    virtual void                    Setup ( const CSphAnalyzerSettings & tSettings );

    virtual const CSphAnalyzerSettings &   GetSettings () const { return m_tSettings; }

    virtual void                    SetText ( const BYTE * sBuffer, int iLength ) = 0;

    /// get next token
    virtual BYTE *                  GetToken () = 0;


protected:
    CSphAnalyzerSettings m_tSettings;

};





#endif 
