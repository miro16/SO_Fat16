//
// Created by mmiro on 19.12.2023.
//
#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "file_reader.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
#define Wolumin_Size 512


///Otwieranie, czytanie i zamykanie urządzenia blokowego (w formie pliku)
struct disk_t *disk_open_from_file(const char *volume_file_name) {
    if (volume_file_name == NULL) {
        errno = EFAULT;
        return NULL;
    }

    FILE *fp = fopen(volume_file_name, "rb");
    if (fp == NULL) {
        errno = ENOENT;
        return NULL;
    }

    struct disk_t *volume = (struct disk_t *) calloc(1, sizeof(struct disk_t));
    if (volume == NULL) {
        fclose(fp);
        errno = ENOMEM;
        return NULL;
    }

    volume->fp = fp;
    return volume;
}

int disk_read(struct disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read) {
    if (pdisk == NULL) {
        errno = EFAULT;
        return -1;
    }
    if (buffer == NULL) {
        errno = EFAULT;
        return -1;
    }

    long where = first_sector * Wolumin_Size;
    fseek(pdisk->fp, where, SEEK_SET);

    size_t read_res = fread(buffer, Wolumin_Size, sectors_to_read, pdisk->fp);
    if ((int) read_res != (int) sectors_to_read) {
        errno = ERANGE;
        return -1;
    }
    //printf("%zu\n", read_res);
    return (int) sectors_to_read;
}

int disk_close(struct disk_t *pdisk) {
    if (pdisk == NULL) {
        errno = EFAULT;
        return -1;
    }
    fclose(pdisk->fp);
    free(pdisk);
    pdisk = NULL;
    return 0;
}
//////////////////



/////// Otwieranie i zamykanie woluminu FAT12/16
struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector) {
    if (!pdisk) {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t *volumin = (struct volume_t *) calloc(1, sizeof(struct volume_t));
    if (volumin == NULL) {
        errno = ENOMEM;
        printf("MM1");
        return NULL;
    }
    int blocks_numb = disk_read(pdisk, (int32_t) first_sector, &volumin->b_sector, 1);
    if (blocks_numb == -1) {
        errno = ENOMEM;
        free(volumin);
        printf("MM2");
        return NULL;
    }

    volumin->file = pdisk;
    if (volumin->b_sector.signature != 0xaa55) {
        errno = EINVAL;
        free(volumin);
        printf("MM3");
        return NULL;
    }

    //////////////////////
    uint16_t *fat1 = calloc(1, volumin->b_sector.each_fat_size * volumin->b_sector.bytes_per_sector);
    if (fat1 == NULL) {
        free(volumin);
        errno = ENOMEM;
        printf("MM7");
        return NULL;
    }

    blocks_numb = disk_read(pdisk, (int32_t) first_sector + volumin->b_sector.reserved_area, fat1,
                            volumin->b_sector.each_fat_size);
    if (blocks_numb != volumin->b_sector.each_fat_size) {
        free(fat1);
        free(volumin);
        errno = EINVAL;
        printf("MM8");
        return NULL;
    }
    ////////////////////////////////

////////////////////////////////////////////////////
    uint16_t *fat2 = calloc(1, volumin->b_sector.each_fat_size * volumin->b_sector.bytes_per_sector);
    if (fat2 == NULL) {
        free(volumin);
        free(fat1);
        printf("MM9");
        errno = ENOMEM;
        return NULL;
    }

    blocks_numb = disk_read(pdisk,
                            (int32_t) first_sector + volumin->b_sector.reserved_area + volumin->b_sector.each_fat_size,
                            fat2, volumin->b_sector.each_fat_size);
    if (blocks_numb != volumin->b_sector.each_fat_size) {
        free(fat1);
        free(fat2);
        free(volumin);
        errno = EINVAL;
        printf("MM10");
        return NULL;
    }
/////////////////////////////////////////

    if (memcmp(fat1, fat2, volumin->b_sector.each_fat_size * volumin->b_sector.bytes_per_sector) != 0) {
        free(fat1);
        free(fat2);
        free(volumin);
        errno = EINVAL;
        printf("MM11");
        return NULL;
    }

    free(fat1);
    volumin->fat = fat2;


    volumin->rootsectors = calloc(volumin->b_sector.max_files_root, sizeof(struct root_dir_entry));
    if (volumin->rootsectors == NULL) {
        errno = ENOMEM;
        free(fat2);
        free(volumin);
        return NULL;
    }

    int res = disk_read(pdisk, volumin->b_sector.reserved_area + 2 * volumin->b_sector.each_fat_size,
                        volumin->rootsectors,
                        (volumin->b_sector.max_files_root * 32) / volumin->b_sector.bytes_per_sector);
    if (res != (volumin->b_sector.max_files_root * 32) / volumin->b_sector.bytes_per_sector) {
        free(fat2);
        free(volumin);
        return NULL;
    }

    printf("MM12");
    return volumin;
}

int fat_close(struct volume_t *pvolume) {
    if (!pvolume) {
        errno = EFAULT;
        return -1;
    }
    if(pvolume->rootsectors != NULL){
        free(pvolume->rootsectors);
    }
    if(pvolume->fat != NULL){
        free(pvolume->fat);
    }
    free(pvolume);
    pvolume = NULL;
    return 0;
}

///////////////////

/////////Get clustrow z zadania nr.1

struct clusters_chain_t *get_chain_fat16(const void * const buffer, size_t size, uint16_t first_cluster){
    if(buffer == NULL){
        return NULL;
    }
    if(size < 1){
        return NULL;
    }


    struct clusters_chain_t *res = malloc(sizeof(struct clusters_chain_t));
    if(res == NULL){
        return NULL;
    }


    res->clusters = malloc(size * sizeof(uint16_t));
    if(res->clusters == NULL){
        free(res);
        errno = ENOMEM;
        return NULL;
    }

    res->clusters[0] = first_cluster;
    uint16_t now = first_cluster;
    res->size = 1;

    while(now < 0xFFF8){
        uint16_t next = ((uint16_t*)buffer)[now];
        if(now > 0xFFF8 || next == 0){

            break;
        }

        res->clusters[res->size] = next;
        res->size++;
        now = next;
    }

    uint16_t *temp = realloc(res->clusters, res->size * sizeof(uint16_t));
    if(temp == NULL){
        free(res->clusters);
        free(temp);
        errno = ENOMEM;
        return NULL;
    }

    res->clusters = temp;

    return res;
}

//Otwieranie, przeszukiwanie, czytanie oraz zamykanie plików w systemie FAT
void fill_with_spaces(char tab[], int size) {
    for (int i = 0; i < size; ++i) {
        tab[i] = ' ';
    }
}

struct file_t *file_open(struct volume_t *pvolume, const char *file_name) {
    if (pvolume == NULL) {
        errno = EFAULT;
        return NULL;
    }
    if (file_name == NULL) {
        errno = EFAULT;
        return NULL;
    }

    struct file_t *res = calloc(1, sizeof(struct file_t));
    if (res == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    char *file_with_spaces = calloc(11, sizeof(char));
    if (file_with_spaces == NULL) {
        free(res);
        errno = ENOMEM;
        return NULL;
    }
    fill_with_spaces(file_with_spaces, 11);
    int filename_size = 11;
    int extension_start = 8;
    // z aaa.txt do aaa    txt
    for (int i = 0; i < filename_size; ++i) {
        if (file_name[i] == '.') {
            i += 1;
            for (int j = extension_start; j < filename_size; ++j) {
                if (file_name[i] == '\0') {
                    break;
                }
                file_with_spaces[j] = file_name[i];
                i++;
            }
        }
        if (file_name[i] == '\0') {
            break;
        }
        file_with_spaces[i] = file_name[i];
    }


    for (int i = 0; i < pvolume->b_sector.max_files_root; ++i) {
        int match = 1;
        for (int j = 0; j < filename_size; ++j) {
            if (pvolume->rootsectors[i].file_name[j] != file_with_spaces[j]) {
                match = 0;
                break;
            }
        }

        if (match == 1) {
            if ((pvolume->rootsectors[i].atributes & (1 << 4)) || (pvolume->rootsectors[i].atributes & (1 << 3))) {
                free(file_with_spaces);
                free(res);
                errno = EISDIR;
                return NULL;
            } else {
                res->file_pos = 0;
                res->volume = pvolume;
                res->file_size = res->volume->rootsectors[i].file_size;
                res->chains = get_chain_fat16(pvolume->fat,
                                              pvolume->b_sector.each_fat_size * pvolume->b_sector.bytes_per_sector,
                                              res->volume->rootsectors[i].low_order);
                if (res->chains == NULL) {
                    free(file_with_spaces);
                    free(res);
                    errno = ENOMEM;
                    return NULL;
                }
                free(file_with_spaces);
                return res;
            }
        }

    }

    free(file_with_spaces);
    free(res);
    return NULL;
}

int file_close(struct file_t *stream) {
    if (!stream) {
        errno = EFAULT;
        return -1;
    }

    if (stream->chains->clusters != NULL) {
        free(stream->chains->clusters);
        stream->chains->clusters = NULL;
    }
    if (stream->chains != NULL) {
        free(stream->chains);
        stream->chains = NULL;
    }

    free(stream);
    stream = NULL;
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) {
    if (ptr == NULL) {
        errno = EFAULT;
        return -1;
    }
    if (stream == NULL) {
        errno = EFAULT;
        return -1;
    }
    struct bootsec *boot = &stream->volume->b_sector;


    char *dataBuffer = calloc(boot->sectors_per_cluster * boot->bytes_per_sector, sizeof(char ));
    if(dataBuffer == NULL) {
        errno = ENOMEM;
        free(dataBuffer);
        return -1;
    }
    int index = 0;
    size_t readed = 0;
    size_t bytes_to_read = size * nmemb;
    printf("bytes to read: %zu \n", bytes_to_read);
    printf("File pos: %hu\n", stream->file_pos);
    printf("File psize: %zu\n", stream->file_size);
    printf("Leng clust %zu\n", stream->chains->size);
    printf("Cluster lenght %d\n", boot->bytes_per_sector * boot->sectors_per_cluster);
    while (bytes_to_read != 0) {
        if(stream->file_pos >= stream->file_size || readed == size * nmemb) {
            break;
        }
        struct disk_t *pdisk = stream->volume->file;

        size_t clusIdx = (stream->file_pos / (boot->bytes_per_sector * boot->sectors_per_cluster));
        printf("Cluster index: %zu\n", clusIdx);
        printf("Clust value: %d\n", (stream->chains->clusters[clusIdx] - 2));
        int32_t firstSector =
                boot->reserved_area + (boot->num_of_fats * boot->each_fat_size) + (boot->max_files_root * 32 / boot->bytes_per_sector) +
                (stream->chains->clusters[clusIdx] - 2) * boot->sectors_per_cluster;
        int32_t sectorsToRead = boot->sectors_per_cluster;

        if(readed == size * nmemb) {
            break;
        }
        int read_result = disk_read(pdisk, firstSector,dataBuffer,sectorsToRead);
        if (read_result == -1) {
            printf("\nerror\n");
            printf("Readed: %zu\n", readed);
            printf("Size: %zu\n", size);
            printf("R/S %zu\n", readed / size);
            free(dataBuffer);
            return -1;
        }
        for (size_t i = stream->file_pos % (boot->sectors_per_cluster * boot->bytes_per_sector); i < boot->sectors_per_cluster * boot->bytes_per_sector; ++i) {
            if(stream->file_pos >= stream->file_size || bytes_to_read == 0 || readed == size * nmemb) {
                break;
            }
            *((char *)ptr + index++) = dataBuffer[i];
            printf("%c", dataBuffer[i]);
            bytes_to_read--;
            readed++;
            stream->file_pos++;
        }
        if(stream->file_pos >= stream->file_size || bytes_to_read == 0 || readed == size * nmemb) {
            break;
        }

    }

    free(dataBuffer);
    printf("Readed: %zu\n", readed);
    printf("Size: %zu\n", size);
    printf("R/S %zu\n", readed / size);
    return readed / size;
}

int32_t file_seek(struct file_t *stream, int32_t offset, int whence) {
    if (stream == NULL) {
        return -1;
    }

    int32_t start = 0;
    switch (whence) {
        case SEEK_CUR:
            stream->file_pos = stream->file_pos + offset;
            break;
        case SEEK_SET:
            stream->file_pos = start + offset;
            break;
        case SEEK_END:
            stream->file_pos = stream->file_size + offset;
            break;
        default: {
            errno = EINVAL;
            return -1;
        }
    }

    return 1;
}



//Otwieranie, czytanie i zamykanie katalogów
int test_path(const char *dir_path) {
    int test_path = strcmp("\\", dir_path);
    if (test_path != 0) {
        errno = ENOENT;
        return -1;
    }
    return 0;
}

void set_res(struct dir_t *res, size_t size, void *dir_data, size_t position) {
    res->size = size;
    res->dir_data = dir_data;
    res->position = position;
}

struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path) {
    if (pvolume == NULL) {
        errno = EFAULT;
        return NULL;
    }
    if (dir_path == NULL) {
        errno = EFAULT;
        return NULL;
    }
    struct dir_t *res = malloc(sizeof(struct dir_t));
    if (res == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    int good_path = test_path(dir_path);
    if (good_path != 0) {
        errno = ENOENT;
        free(res);
        return NULL;
    }
    set_res(res, pvolume->b_sector.max_files_root, pvolume->rootsectors, 0);

    return res;
}

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry) {
    if(pdir == NULL){
        errno = EFAULT;
        return 1;
    }
    if(pentry == NULL){
        errno = EFAULT;
        return 1;
    }
    for (size_t i = pdir->position; i < pdir->size; ++i, pdir->position++) {
        struct root_dir_entry *my_pentry = &((struct root_dir_entry *) pdir->dir_data)[i];
        if (*(uint8_t *) my_pentry->file_name != 0x00 && *(uint8_t *) my_pentry->file_name != 0xe5) {
            memset(pentry->name, 0, 13);
            //from test    txt to test.txt
            int j = 0;
            for (; j < 8; ++j) {
                if(my_pentry->file_name[j] == ' '){
                    break;
                }
                pentry->name[j] = my_pentry->file_name[j];
                pentry->name[j + 1] = '\0';
            }

            if(my_pentry->file_name[8] != ' ') {
                pentry->name[j++] = '.';
                pentry->name[j] = '\0';
                for (int k = 0; k < 3; ++k) {
                    if(my_pentry->file_name[8 + k] == ' ') break;
                    pentry->name[j++] = my_pentry->file_name[8 + k];
                    pentry->name[j] = '\0';
                }
            }
            pentry->size = pdir->size;
            pentry->is_archived = (my_pentry->atributes & 0x20);
            pentry->is_system = (my_pentry->atributes & 0x04);
            pentry->is_hidden = (my_pentry->atributes & 0x02);
            pentry->is_readonly = (my_pentry->atributes & 0x01);
            pentry->is_directory = (my_pentry->atributes & 0x10);
            pdir->position++;
            return 0;
        }
    }
    errno = EIO;
    return 1;
}

int dir_close(struct dir_t *pdir) {
    if (!pdir) {
        errno = EFAULT;
        return -1;
    }

    free(pdir);
    pdir = NULL;
    return 0;
}


