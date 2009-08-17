/*
 * ============================================================================
 *  Name     : CGreg2Container from Greg2Container.h
 *  Part of  : greg2
 *  Created  : 12/11/2002 by 
 *  Implementation notes:
 *     Initial content was generated by Series 60 AppWizard.
 *  Version  :
 *  Copyright: 
 * ============================================================================
 */

// INCLUDE FILES
#include "Greg2Container.h"
#include <eiklabel.h>  // for example label control

#include <mdaaudiooutputstream.h> //For audio stream stuff.
#include <Mda\Common\Audio.h> //For TMdaAudioDataSettings.


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CGreg2Container::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CGreg2Container::ConstructL(const TRect& aRect)
{
    CreateWindowL();

    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Audio Device Test") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Use the 'options' menu") );

    
    iToDoLabel2 = new (ELeave) CEikLabel;
    iToDoLabel2->SetContainerWindowL( *this );
    iToDoLabel2->SetTextL( _L("to start the test.") );

    SetRect(aRect);
    ActivateL();
}

// Destructor
CGreg2Container::~CGreg2Container()
{
    delete iLabel;
    delete iToDoLabel;
    delete iToDoLabel2;
}

// ---------------------------------------------------------
// CGreg2Container::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CGreg2Container::SizeChanged()
{
    // TODO: Add here control resize code etc.
    iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10, 80), iToDoLabel->MinimumSize() );
    iToDoLabel2->SetExtent( TPoint(10,100), iToDoLabel2->MinimumSize() );
}

// ---------------------------------------------------------
// CGreg2Container::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CGreg2Container::CountComponentControls() const
{
    return 3; // return nbr of controls inside this container
}

// ---------------------------------------------------------
// CGreg2Container::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CGreg2Container::ComponentControl(TInt aIndex) const
{
    switch ( aIndex )
    {
       case 0:
           return iLabel;
       case 1:
           return iToDoLabel;
       case 2:
           return iToDoLabel2;
       default:
           return NULL;
    }
}

// ---------------------------------------------------------
// CGreg2Container::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CGreg2Container::Draw(const TRect& aRect) const
{
    CWindowGc& gc = SystemGc();
    // TODO: Add your drawing code here
    // example code...
    gc.SetPenStyle(CGraphicsContext::ENullPen);
    gc.SetBrushColor(KRgbGray);
    gc.SetBrushStyle(CGraphicsContext::ESolidBrush);
    gc.DrawRect(aRect);
}

// ---------------------------------------------------------
// CGreg2Container::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CGreg2Container::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
{
    // TODO: Add your control event handler code here
}

// End of File  
