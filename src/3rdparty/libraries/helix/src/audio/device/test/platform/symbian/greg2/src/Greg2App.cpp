/*
 * ============================================================================
 *  Name     : CGreg2App from Greg2App.cpp
 *  Part of  : greg2
 *  Created  : 12/11/2002 by 
 *  Implementation notes:
 *
 *     Initial content was generated by Series 60 AppWizard.
 *  Version  :
 *  Copyright: 
 * ============================================================================
 */

// INCLUDE FILES
#include    "Greg2App.h"
#include    "Greg2Document.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CGreg2App::AppDllUid()
// Returns application UID
// ---------------------------------------------------------
//
TUid CGreg2App::AppDllUid() const
{
    return KUidgreg2;
}

   
// ---------------------------------------------------------
// CGreg2App::CreateDocumentL()
// Creates CGreg2Document object
// ---------------------------------------------------------
//
CApaDocument* CGreg2App::CreateDocumentL()
{
    return CGreg2Document::NewL( *this );
}

// ================= OTHER EXPORTED FUNCTIONS ==============
//
// ---------------------------------------------------------
// NewApplication() 
// Constructs CGreg2App
// Returns: created application object
// ---------------------------------------------------------
//
EXPORT_C CApaApplication* NewApplication()
{
    return new CGreg2App;
}

// ---------------------------------------------------------
// E32Dll(TDllReason) 
// Entry point function for EPOC Apps
// Returns: KErrNone: No error
// ---------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason )
{
    return KErrNone;
}

// End of File  

