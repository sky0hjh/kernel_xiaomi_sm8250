#include "qmi_xiaomi.h"

int initialized = -1;
int hw_platform_ver = -1;
uint32_t hw_country_ver = 0;
uint32_t hw_version_major = 0;
uint32_t hw_version_minor = 0;
int global = 0;
int india = 0;
int version_b = 0;

void get_info() {
    hw_platform_ver = get_hw_version_platform();
    hw_country_ver = get_hw_country_version();
    hw_version_major = get_hw_version_major();
    hw_version_minor = get_hw_version_minor();
    global = (hw_country_ver == (uint32_t)CountryGlobal);
    india = (hw_country_ver == (uint32_t)CountryIndia);
    version_b = ((get_hw_version_minor() == (uint32_t)HW_MINOR_VERSION_B) 
                 && (get_hw_version_major() == (uint32_t)HW_MAJOR_VERSION_B));
    initialized = 1;
    return;
}

char *get_bdf_file_name() {
    char *file_name = ELF_BDF_FILE_NAME;

    if (!initialized)
        get_info();

    switch (hw_platform_ver) {
        case HARDWARE_PLATFORM_LMI:
            if (global)
                file_name = ELF_BDF_FILE_NAME_J11_GLOBAL;
            else if (india)
                file_name = ELF_BDF_FILE_NAME_J11_INDIA;
            else {
                if (version_b)
                    file_name = ELF_BDF_FILE_NAME_J11_B_BOM;
                else
                    file_name = ELF_BDF_FILE_NAME_J11;
            }
            break;
        case HARDWARE_PLATFORM_CAS:
            file_name = ELF_BDF_FILE_NAME_J1S;
            break;
        case HARDWARE_PLATFORM_THYME:
            file_name = ELF_BDF_FILE_NAME_J2S;
            break;
        case HARDWARE_PLATFORM_APOLLO:
            if (global)
                file_name = ELF_BDF_FILE_NAME_J3S_GLOBAL;
            else if (india)
                file_name = ELF_BDF_FILE_NAME_J3S_INDIA;
            else
                file_name = ELF_BDF_FILE_NAME_J3S;
            break;
        case HARDWARE_PLATFORM_ALIOTH:
            if (global)
                file_name = ELF_BDF_FILE_NAME_K11A_GLOBAL;
            else if (india)
                file_name = ELF_BDF_FILE_NAME_K11A_INDIA;
            else
                file_name = ELF_BDF_FILE_NAME_K11A;
            break;
        default:
            if (global)
                file_name = ELF_BDF_FILE_NAME_GLOBAL;
            else if (india)
                file_name = ELF_BDF_FILE_NAME_INDIA;
            else {
                if (version_b)
                    file_name = ELF_BDF_FILE_NAME_B_BOM;
                else
                    file_name = ELF_BDF_FILE_NAME;
            }
            break;
    }

    return file_name;
}

char *get_regdb_file_name() {
    char *file_name = ELF_BDF_FILE_NAME;

    if (!initialized)
        get_info();

    if (hw_platform_ver == HARDWARE_PLATFORM_LMI)
        file_name = REGDB_FILE_NAME_J11;
    else
        file_name = REGDB_FILE_NAME;

    return file_name;
}
