#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <vector>
#include <thread>
#include <jni.h>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <unwind.h>
#include <dlfcn.h>
#include <libgen.h>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <stdlib.h>
#include <cstdint>
#include <cstdio>
#include <stdbool.h>
#include "Main/Tools.h" 
#include "Main/Logger.h"
#include "Main/oxorany.h"
//clude "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#include <random> //
#include "Main/Dobby/Dobby.h"
#include "Main/Macros.h"
//#include "xhook/xhook.h"
class _BYTE;
class _QWORD;
class _DWORD;
class _WORD;

class LODWORD;
#define LODWORD long

#define _QWORD long
#define _DWORD long
#define _BYTE long
#define _WORD long
//#define HOOK_LIB
#define targetLibName oxorany("libanogs.so")
#define targetLibName oxorany("libUE4.so")
#include <unordered_map>
using namespace std;
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define _OWORD uint64_t
#define _BOOL8 uint64_t
char *Offset;
#define ret_zero
#define j_j__free
#define log_suspicious_activity
#define apply_cheat_penalty
#define check_memory_integrity
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define HIWORD
#define JUMPOUT
#define byte_4
#define ARM64_SYSREG
#include <random>
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define sub_95A8204
#define IsMemoryReadable
#define BYTE1
#define BYTE3
#define MEMORY_BASIC_INFORMATION mbi
#define BYTE2
#define _WriteStatusReg
typedef long long int64; 
typedef short int16;     
uintptr_t ANOGS;
uintptr_t UE5;
DWORD EGLBase = 0;
DWORD EGLSize = 0;
DWORD EGLAlloc = 0;
DWORD libcBase = 0;
DWORD libcSize = 0;
DWORD libcAlloc = 0;
DWORD libUE4Base = 0;
DWORD UE4Base = 0;
DWORD libanogsBase = 0;
DWORD libanortBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;
unsigned int libanogsSize  = 0;
unsigned int libUE4Size  = 0;
DWORD NewBase = 0;
DWORD libaviwaBase = 0;
DWORD libaviwaSize = 0;
DWORD libaviwaAlloc = 0;

#include <sys/stat.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <android/log.h>






__int64 CHIKU()
{
    return 0;
}

//===={{===={{{{{{{{ }}}}}}}}}}

 
#define COLDX(RET, NAME, ARGS) \
    typedef RET (*NAME##_t) ARGS;   \
    NAME##_t o##NAME = nullptr;     \
    RET h##NAME ARGS

static std::atomic<int> hard_block_count{0};
__attribute__((noreturn)) static void HardBlockExit() {
    __builtin_trap();
}

std::atomic<bool> triggered{false};
std::atomic<bool> safe_exit_started{false};

void DeepSafeExit() {
    prctl(PR_SET_PDEATHSIG, SIGKILL); // अगर parent7 मरे तो kill (safety)
    sleep(1);                         // गेम को time दो stable दिखने का
    syscall(SYS_exit, 0);             // direct syscall-based exit
}


uintptr_t getLibraryBase(void *addr) {
    Dl_info info;
    if (dladdr(addr, &info) && info.dli_fbase)
        return (uintptr_t) info.dli_fbase;
    return 0;
}

uintptr_t string2Offsets(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}

//================================================================================


void *COLDX_CHEAT_thread(void *) {
        UE5 = Tools::GetBaseAddress("libUE4.so");
        while (!UE5) {
        UE5 = Tools::GetBaseAddress("libUE4.so");
            sleep(5);
    }
    
    ANOGS = Tools::GetBaseAddress("libanogs.so");
        while (!ANOGS) {
        ANOGS = Tools::GetBaseAddress("libanogs.so");
            sleep(1);
    }
    
    while (!isLibraryLoaded("libUE4.so")) { sleep(5); }
	while (!isLibraryLoaded("libanogs.so")) { sleep(1); }
    
    libanogsBase = findLibrary("libanogs.so");
    libUE4Base   = findLibrary("libUE4.so");
    
    libanogsAlloc = (DWORD)malloc(libanogsSize);
    libUE4Alloc   = (DWORD)malloc(libUE4Size);
    memcpy((void *)libanogsAlloc, (void *)libanogsBase, libanogsSize);
    memcpy((void *)libUE4Alloc, (void *)libUE4Base, libUE4Size);
    LOGI(" @VOLDXFIREE BYPASS LOADED");
    LOGI("UE4 size : 0x%04X | ANOGS size : 0x%04X",libUE4Size,libanogsSize);
   #if defined(__aarch64__)
LOGI("=====================================================");
LOGI("=========< LIBRARY LOADED BY PAPAJI >=========");
LOGI("=====================================================");
//================================================================================
PATCH_LIB("libanogs.so", "0x2191B0", " C0 03 5F D6"); //5min game crash fix
PATCH_LIB("libanogs.so", "0x3379F0", "00 00 80 D2 C0 03 5F D6");//1day fix
PATCH_LIB("libanogs.so", "0x4D376C", "00 00 80 D2 C0 03 5F D6");//10yr 
PATCH_LIB("libanogs.so", "0x22EF80", "00 00 80 D2 C0 03 5F D6");//case 35
PATCH_LIB("libanogs.so", "0x22F374", "00 00 80 D2 C0 03 5F D6");//case 37
PATCH_LIB("libanogs.so", "0x367C28", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x390870", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x218EE8", "C0 03 5F D6");

   LOGI(OBFUSCATE("Done"));
#endif

  return NULL;
}


__attribute__((constructor)) void mainload() {
    
   pthread_t ptid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&ptid, &attr, COLDX_CHEAT_thread, NULL);
    pthread_attr_destroy(&attr);
   
   
    
}











