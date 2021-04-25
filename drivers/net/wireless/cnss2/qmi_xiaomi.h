#include <soc/qcom/socinfo.h>

#define ELF_BDF_FILE_NAME               "bdwlan.elf"

#define ELF_BDF_FILE_NAME_J11           "bd_j11.elf"
#define ELF_BDF_FILE_NAME_J11_B_BOM     "bd_j11_b.elf"
#define ELF_BDF_FILE_NAME_J11_INDIA     "bd_j11in.elf"
#define ELF_BDF_FILE_NAME_J11_GLOBAL    "bd_j11gl.elf"

#define ELF_BDF_FILE_NAME_GLOBAL        "bd_j1gl.elf"
#define ELF_BDF_FILE_NAME_INDIA         "bd_j1in.elf"
#define ELF_BDF_FILE_NAME_B_BOM         "bd_j1_b.elf"

#define ELF_BDF_FILE_NAME_J1S           "bd_j1s.elf"

#define ELF_BDF_FILE_NAME_J2S           "bd_j2s.elf"

#define ELF_BDF_FILE_NAME_J3S           "bd_j3s.elf"
#define ELF_BDF_FILE_NAME_J3S_GLOBAL    "bd_j3sgl.elf"
#define ELF_BDF_FILE_NAME_J3S_INDIA     "bd_j3sin.elf"

#define ELF_BDF_FILE_NAME_K11A          "bd_k11a.elf"
#define ELF_BDF_FILE_NAME_K11A_GLOBAL   "bd_k11agl.elf"
#define ELF_BDF_FILE_NAME_K11A_INDIA    "bd_k11ain.elf"

#define REGDB_FILE_NAME                 "regdb.bin"
#define REGDB_FILE_NAME_J11             "regdb_j11.bin"

char *get_bdf_file_name(void);

char *get_regdb_file_name(void);
