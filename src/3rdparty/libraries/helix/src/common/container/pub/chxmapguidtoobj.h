/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: chxmapguidtoobj.h,v 1.13 2005/03/14 19:33:48 bobclark Exp $
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

#ifndef _CHXMAPGUIDTOOBJ_H_
#define _CHXMAPGUIDTOOBJ_H_

// Notes...
//
// Since we aren't using templates, we get to copy the same basic code all
// over the place.  So, if you change something in this class, chances are
// that the other CHXMap*To* classes may need the change as well.
// XXXSAB: Need to better abstract out the common code...
//
// This implementation has a few dynamically resized vectors - their
// "chunk sizes" (number of elements added to size when a new element
// addition requires a reallocation) can be adjusted via the following
// accessors.
//
//    m_items - This is the vector of actual key/value pairs (along with a
//        boolean "free" flag) where the data for the map is stored.  It's
//        chunk size is controlled via the optional argument to the map
//        ctor.  And the default value for that is controlled by the
//        static SetDefaultChunkSize() method.
//
//    m_buckets - This is the vector of hash buckets.  Each hash bucket is
//        a vector of int indices into the m_items vector.  The number of
//        buckets doesn't change over time and is controlled via the
//        InitHashTable() method (which has the effect of resetting the
//        map) and it defaults to z_defaultNumBuckets (101 at the moment).
//        The chunk size of the individual hash buckets is set by the
//        SetBucketChunkSize() method and the default for that is set by
//        the SetDefaultBucketChunkSize() method.
//

#include "hxcom.h"
#include "hxtypes.h"
#include "carray.h"
#include "hxstring.h"
#include "hxguid.h" /* for GUID_NULL */
#include "hxmaputils.h"
#include "chxmapbuckets.h"

class CHXMapGUIDToObj
{
public:
    typedef GUID key_type;
    typedef const GUID& key_arg_type;
    typedef const GUID& key_ref_type;
#if !defined (HELIX_FEATURE_FULLGUID)
    inline static key_arg_type key_nil() { static const key_type val = GUID_NULL; return val;}
#else
    inline static key_arg_type key_nil() { return GUID_NULL;}
#endif

    typedef void* value_type;
    typedef void* value_arg_type;
    typedef void*& value_ref_type;
    typedef void* value_const_ref_type;
    inline static value_ref_type val_nil() { static const value_type p = 0; return (value_ref_type)p; }

    struct Item
    {
        Item (key_arg_type key_ = key_nil(),
              value_arg_type val_ = val_nil(),
              bool bFree_ = true) :
            key(key_), val(val_), bFree(bFree_)
        {}

        key_type key;
        value_type val;
        bool  bFree;
    };
    DECLARE_ITEMVEC(ItemVec_t,Item,Item(),0,GUID_NULL);

    class Iterator
    {
    public:
        typedef const key_type* iter_key_type;
        friend class CHXMapGUIDToObj;

        // NOTE: (item == -1) is used to mean "set to end of pItems".
        Iterator(ItemVec_t* pItems = NULL,
                 int item = -1);

        // NOTE: Values of 'next' copied into iterator...since this
        //       iterator is caching key/value and doesn't return a
        //       value_type&, it can't be used to modify the values in the
        //       map.
        // NOTE: Strangely, for this class, the GUID is NOT cached in here
        //       - the ptr to the GUID key in the map is stored here.
        Iterator& operator++();
        Iterator  operator++(int); // XXXSAB: tested?

        HXBOOL operator==(const Iterator&) const;
        HXBOOL operator!=(const Iterator&) const;
        value_type operator*(); // returns the 'value'
        iter_key_type get_key  (); // returns the 'key'

    private:
        void GotoValid();

        ItemVec_t*      m_pItems;
        int             m_item;

        // cached key/value
        iter_key_type   m_key;
        value_type      m_val;
    };

private:

#if defined(HELIX_CONFIG_NOSTATICS)
    static const ULONG32 z_defaultNumBuckets;
    static const ULONG32 z_defaultChunkSize;
    static const ULONG32 z_defaultBucketChunkSize;
#else
    static ULONG32 z_defaultNumBuckets;
    static ULONG32 z_defaultChunkSize;
    static ULONG32 z_defaultBucketChunkSize;
#endif
    

public:
    // Construction

    // NOTE: Chunk size is the number of key/value pairs to grow by each
    //       time one of the hash buckets needs to be grown.
    CHXMapGUIDToObj(int chunkSize = z_defaultChunkSize);
    ~CHXMapGUIDToObj();

    // Attributes
    inline int GetCount() const;
    inline HXBOOL IsEmpty() const;

    HXBOOL Lookup(key_arg_type key, value_type& value) const;
    POSITION Lookup(key_arg_type key) const;

    // XXXSAB: I added GetKeyAt() and GetAt() since there was previously
    //         no easy way to get those data without advancing the
    //         POSITION.
    key_ref_type GetKeyAt(POSITION pos) const;
    value_const_ref_type GetAt(POSITION pos) const;
    value_ref_type GetAt(POSITION pos);

    // Lookup & add if not there
    value_ref_type operator[](key_arg_type key);

    // add a new (key, value) pair
    POSITION SetAt(key_arg_type key, value_type value);

    // remove existing (key, ?) pair
    POSITION Remove(key_arg_type key);

    HXBOOL RemoveKey(key_arg_type key);

    void RemoveAll();

    // Iteration
    POSITION GetStartPosition() const;

    // GUID passes out a non-const GUID*, but it should be const - don't
    // change it.
    void GetNextAssoc (POSITION& pos, key_type*& key, value_type& value) const;

    Iterator Begin();
    Iterator End();
    Iterator Erase(Iterator it);
    // XXXSAB: Added Find() command to parallel STL style method
    Iterator Find(key_arg_type key);

    // Returns the number of hash buckets
    inline ULONG32 GetHashTableSize() const;

    // This will reset the internal storage so that any the map will be
    // empty when this returns.
    HX_RESULT InitHashTable(ULONG32 numBuckets = z_defaultNumBuckets,
                       HXBOOL bAlloc = TRUE);

    typedef ULONG32 (*HashFunc_t) (key_arg_type key);
    static ULONG32 DefaultHashFunc (key_arg_type key);
    inline HashFunc_t SetHashFunc (HashFunc_t hf = DefaultHashFunc); // XXXSAB: tested???

    // Overrideables: special non-virtual (XXXSAB: Huh?)
    inline ULONG32 HashKey(key_arg_type key) const;

    inline static void SetDefaultNumBuckets (ULONG32 numBuckets);
    inline static void SetDefaultChunkSize (ULONG32 chunkSize);
    inline static void SetDefaultBucketChunkSize (ULONG32 chunkSize);
    inline void SetBucketChunkSize (ULONG32 chunkSize);

    // In _DEBUG mode, this does a bunch of DPRINTF's...
    void Dump() const;

private:
    inline HXBOOL Lookup(key_arg_type key, int& retItem) const;
    HXBOOL LookupInBucket(ULONG32 bucket, key_arg_type key, int& retItem) const;
    Item* LookupItem(ULONG32 bucket, key_arg_type key);
    inline const Item* LookupItem(ULONG32 bucket, key_arg_type key) const
    {
        return ((CHXMapGUIDToObj*)this)->LookupItem(bucket, key);
    }

    // Internal function - key already verified not to exist
    HXBOOL AddToBucket(ULONG32 bucket, key_arg_type key, value_type value, int& retItem);


    inline POSITION Item2Pos(int item) const;
    inline int Pos2Item(POSITION pos) const;

private:

    HashFunc_t          m_hf;

    ItemVec_t           m_items;
    HlxMap::IntVec_t    m_free;

    CHlxMapBuckets      m_buckets;
    ULONG32             m_numBuckets;
    ULONG32             m_chunkSize;
    ULONG32             m_bucketChunkSize;

    // Members specific to the type of key and/or value goes below here.
    void ConstructTypeSpecifics();
    inline HXBOOL IsKeyMatch (key_arg_type k1, key_arg_type k2) const
    {
        return (memcmp(&k1, &k2, sizeof(k1)) == 0);
    }
};

int CHXMapGUIDToObj::GetCount() const
{
    return m_items.size() - m_free.size();
}

HXBOOL CHXMapGUIDToObj::IsEmpty() const
{
    return GetCount() == 0;
}

ULONG32 CHXMapGUIDToObj::GetHashTableSize() const
{
    return m_numBuckets;
}

CHXMapGUIDToObj::HashFunc_t CHXMapGUIDToObj::SetHashFunc (
    CHXMapGUIDToObj::HashFunc_t hf)
{
    HashFunc_t old = m_hf;
    m_hf = hf;
    return old;
}

ULONG32 CHXMapGUIDToObj::HashKey (key_arg_type key) const
{
    if (m_hf) return m_hf(key);
    return DefaultHashFunc(key);
}

void CHXMapGUIDToObj::SetDefaultNumBuckets (ULONG32 numBuckets)
{
#if !defined(HELIX_CONFIG_NOSTATICS)
    z_defaultNumBuckets = numBuckets;
#endif
}

void CHXMapGUIDToObj::SetDefaultChunkSize (ULONG32 chunkSize)
{
#if !defined(HELIX_CONFIG_NOSTATICS)
    z_defaultChunkSize = chunkSize;
#endif
}

void CHXMapGUIDToObj::SetDefaultBucketChunkSize (ULONG32 chunkSize)
{
#if !defined(HELIX_CONFIG_NOSTATICS)
    z_defaultBucketChunkSize = chunkSize;
#endif
}

void CHXMapGUIDToObj::SetBucketChunkSize (ULONG32 chunkSize)
{
    m_bucketChunkSize = chunkSize;
}

#endif // _CHXMAPGUIDTOOBJ_H_
