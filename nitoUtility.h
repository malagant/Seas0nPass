//
//  nitoUtility.h
//  Seas0nPass
//
//  Created by Kevin Bradley on 3/20/09.
//  Copyright 2009 nito, LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PatchedFile.h"

#define XPWN [[NSBundle mainBundle] pathForResource:@"xpwntool" ofType:@"" inDirectory:@"bin"]
#define VFDECRYPT [[NSBundle mainBundle] pathForResource:@"vfdecrypt" ofType:@"" inDirectory:@"bin"]
#define CYDIA_TAR [[NSBundle mainBundle] pathForResource:@"Cydia" ofType:@"tgz" inDirectory:@"archives"]
#define SPACE_SCRIPT [[NSBundle mainBundle] pathForResource:@"space" ofType:@"sh" inDirectory:@"scripts"]

#define HDIUTIL @"/usr/bin/hdiutil"
#define ASR @"/usr/sbin/asr"
#define BSPATCH @"/usr/bin/bspatch"
#define FM [NSFileManager defaultManager]
#define TMP_ROOT @"/private/tmp/tk"
#define IPSW_TMP @"/private/tmp/tk/ipsw"

enum{
	kDMGReadWrite = 0,
	kDMGReadOnly = 1,
	
};

@interface nitoUtility : NSObject {
	
	id delegate;
	BOOL enableScripting;

}
	@property (readwrite, assign) BOOL enableScripting;
@property (nonatomic, assign) id delegate;

+ (int)bunZip:(NSString *)inputTar toRoot:(NSString *)toLocation excluding:(NSString *)excludeFile;
+ (int)extractGZip:(NSString *)inputTar toRoot:(NSString *)toLocation;
+ (int)bunZip:(NSString *)inputTar toRoot:(NSString *)toLocation;
+ (int)extractGZip:(NSString *)inputTar toLocation:(NSString *)toLocation;
+ (BOOL)unzipFile:(NSString *)theFile toPath:(NSString *)newPath;
+ (int)extractTar:(NSString *)inputTar toLocation:(NSString *)toLocation;

+ (void)unmountVolume:(NSString *)theVolume;
+ (NSString *)mountImage:(NSString *)irString;
+ (BOOL)checkFile:(NSString *)inputFile againstMD5:(NSString *)properMD5;
+ (int)scanForRestore:(NSString *)drivepath;
+ (int)resizeVolume:(NSString *)theVolume toSize:(NSString *)theSize;

+ (void)changeOwner:(NSString *)theOwner onFile:(NSString *)theFile isRecursive:(BOOL)isR;
+ (void)changePermissions:(NSString *)perms onFile:(NSString *)theFile isRecursive:(BOOL)isR;

+ (int)patchFile:(NSString *)patchFile withPatch:(NSString *)thePatch endMD5:(NSString *)desiredMD5;
- (int)modifyPT:(NSString *)ptFile;
+ (int)decryptRamdisk:(NSString *)theRamdisk toPath:(NSString *)outputDisk withIV:(NSString *)iv key:(NSString *)key;
+ (int)repackRamdisk:(NSString *)theRamdisk toPath:(NSString *)outputDisk withIV:(NSString *)iv key:(NSString *)key originalPath:(NSString *)original;
+ (int)decryptFilesystem:(NSString *)fileSystem withKey:(NSString *)fileSystemKey;
+ (NSString *)convertImage:(NSString *)irString toFile:(NSString *)outputFile toMode:(int)theMode;
+ (int)patchIBSS:(NSString *)ibssFile;
- (void)patchFilesystem:(NSString *)inputFilesystem;
- (NSString *)pwnctionaryFromPath:(NSString *)mountedPath original:(NSString *)original withBundle:(NSDictionary *)theBundle;
- (void)permissionedPatch:(NSString *)theFile withOriginal:(NSString *)originalDMG;
+ (int)migrateFiles:(NSArray *)migration toPath:(NSString *)finalPath;
+ (void)createTempSetup;
- (int)patchRamdisk:(NSString *)theRamdisk;
+ (int)runScript:(NSString *)theScript withInput:(NSString *)theInput;
+ (void)createIPSWToFile:(NSString *)theName;
@end
