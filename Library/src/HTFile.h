/*  */

/*                      File Access                             HTFile.h
**                      ===========
**
**      These are routines for file access used by WWW browsers.
**
*/

#ifndef HTFILE_H
#define HTFILE_H

#include "HTFormat.h"
#include "HTAccess.h"


/*      Controlling globals
*/
extern int HTDirAccess;         /* Directory access level */

#define HT_DIR_FORBID           0       /* Altogether forbidden */
#define HT_DIR_SELECTIVE        1       /* If .www_browsable exists */
#define HT_DIR_OK               2       /* Any accesible directory */

#define HT_DIR_ENABLE_FILE      ".www_browsable" /* If exists, can browse */

extern int HTDirReadme;         /* Include readme files? */
                                /* Values: */
#define HT_DIR_README_NONE      0
#define HT_DIR_README_TOP       1
#define HT_DIR_README_BOTTOM    2

#define HT_DIR_README_FILE              "README"


/*      Convert filenames between local and WWW formats
**      -----------------------------------------------
**      Make up a suitable name for saving the node in
**
**      E.g.    $(HOME)/WWW/news/1234@cernvax.cern.ch
**              $(HOME)/WWW/http/crnvmc/FIND/xx.xxx.xx
*/
#ifdef __STDC__
extern char * HTLocalName(const char * name);
#else
extern char * HTLocalName();
#endif

/*      Make a WWW name from a full local path name
**
*/
extern char * WWW_nameOfFile PARAMS((const char * name));


/*      Generate the name of a cache file
*/

extern char * HTCacheFileName PARAMS((CONST char * name));


/*      Define the representation for a file suffix
**      -------------------------------------------
**
** On entry,
**      suffix          includes the "." if that is important (normally, yes!)
**      representation  is MIME-style
**      quality         an a priori judgement of the quality of such files
**
** Example:   HTSetSuffix(".ps", "application/postscript", 1.0);
**
*/

extern void HTSetSuffix PARAMS((
        CONST char *    suffix,
        CONST char *    representation,
        float           quality));
        

/*      Determine file format from file name
**      ------------------------------------
*/

#ifdef __STDC__
extern HTFormat HTFileFormat(const char * filename);
#else
extern HTFormat HTFileFormat();
#endif


/*      Determine file format from file name
**      ------------------------------------
*/

extern float HTFileValue PARAMS((CONST char * filename));


/*      Determine write access to a file
//      --------------------------------
//
// On exit,
//      return value    YES if file can be accessed and can be written to.
//
//      Isn't there a quicker way?
*/

#ifdef __STDC__
extern BOOL HTEditable(const char * filename);
#else
extern BOOL HTEditable();
#endif


/*      Determine a suitable suffix, given the representation
**      -----------------------------------------------------
**
** On entry,
**      rep     is the atomized MIME style representation
**
** On exit,
**      returns a pointer to a suitable suffiz string if one has been
**              found, else NULL.
*/
extern CONST char * HTFileSuffix PARAMS((HTAtom* rep));


/*      Open a file descriptor for a document
**      -------------------------------------
**
** On entry,
**      addr            must point to the fully qualified hypertext reference.
**
** On exit,
**      returns         <0              Error has occured.
**                      HT_LOADED       Done OK
**
**      *pFormat        Set to the format of the file, if known.
**                      (See WWW.h)
**
*/
/*
extern int HTLoadFile
PARAMS
((
  const char * addr,
  HTParentAnchor * anchor,
  int diagnostic
));
*/
extern HTProtocol HTFTP, HTFile;
#endif /* HTFILE_H */
/*

    */
