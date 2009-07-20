/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: expatapi.h,v 1.2 2004/07/19 21:13:16 hubbe Exp $
 * 
 * Portions Copyright (c) 1995-2004 RealNetworks, Inc. All Rights Reserved.
 * 
 * The contents of this file, and the files included with this file,
 * are subject to the current version of the RealNetworks Public
 * Source License (the "RPSL") available at
 * http://www.helixcommunity.org/content/rpsl unless you have licensed
 * the file under the current version of the RealNetworks Community
 * Source License (the "RCSL") available at
 * http://www.helixcommunity.org/content/rcsl, in which case the RCSL
 * will apply. You may also obtain the license terms directly from
 * RealNetworks.  You may not use this file except in compliance with
 * the RPSL or, if you have a valid RCSL with RealNetworks applicable
 * to this file, the RCSL.  Please see the applicable RPSL or RCSL for
 * the rights, obligations and limitations governing use of the
 * contents of the file.
 * 
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 or later (the
 * "GPL") in which case the provisions of the GPL are applicable
 * instead of those above. If you wish to allow use of your version of
 * this file only under the terms of the GPL, and not to allow others
 * to use your version of this file under the terms of either the RPSL
 * or RCSL, indicate your decision by deleting the provisions above
 * and replace them with the notice and other provisions required by
 * the GPL. If you do not delete the provisions above, a recipient may
 * use your version of this file under the terms of any one of the
 * RPSL, the RCSL or the GPL.
 * 
 * This file is part of the Helix DNA Technology. RealNetworks is the
 * developer of the Original Code and owns the copyrights in the
 * portions it created.
 * 
 * This file, and the files included with this file, is distributed
 * and made available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS
 * ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
 * 
 * Technology Compatibility Kit Test Suite(s) Location:
 *    http://www.helixcommunity.org/content/tck
 * 
 * Contributor(s):
 * 
 * ***** END LICENSE BLOCK ***** */
// $Id: expatapi.h,v 1.2 2004/07/19 21:13:16 hubbe Exp $

#ifndef _EXPATAPI_H_
#define _EXPATAPI_H_


#ifdef __cplusplus
extern "C" {
#endif

void handleStartElement(void* parser, const XML_Char *name, const XML_Char **atts);
void handleEndElement(void* parser, const XML_Char *name);
void handleCharacterData(void* parser, const XML_Char *s, int len);
void handleProcessingInstruction(void* parser, const XML_Char *target, const XML_Char *data);
void handleComment(void* parser, const XML_Char *data);
void handleStartCdataSection(void* parser);
void handleEndCdataSection(void* parser);
void handleDefault(void* parser, const XML_Char *s, int len);
void handleUnparsedEntityDecl(void* parser,
			    const XML_Char *entityName,
			    const XML_Char *base,
			    const XML_Char *systemId,
			    const XML_Char *publicId,
			    const XML_Char *notationName);
void handleNotationDecl(void* parser,
		      const XML_Char *notationName,
		      const XML_Char *base,
		      const XML_Char *systemId,
		      const XML_Char *publicId);
void handleStartNamespaceDecl(void *parser, 
			      const XML_Char *prefix,
			      const XML_Char *uri);
void handleEndNamespaceDecl(void *parser, const XML_Char *prefix);
int handleNotStandalone(void *parser);
void handleStartDoctypeDecl(void* parser, const XML_Char *doctypeName);
void handleEndDoctypeDecl(XML_Parser parser);

#ifdef __cplusplus
}
#endif


#endif /* _EXPATAPI_H_ */

