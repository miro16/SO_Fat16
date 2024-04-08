//
// Created by mmiro on 19.12.2023.
//

#ifndef FAT16_FILE_READER_H
#define FAT16_FILE_READER_H

#include <stdint.h>
#include <stdio.h>


struct disk_t{
    FILE *fp;
};
struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct bootsec {
    char jump_code[3];
    char oem[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_area;
    int8_t num_of_fats;
    uint16_t max_files_root;
    uint16_t file_sys_sectors;
    uint8_t media_type;
    uint16_t each_fat_size;
    uint16_t sectors_per_track;
    uint16_t number_of_heads;
    uint32_t number_of_sectors;
    uint32_t file_sys_sectors2;

    uint8_t bios_int;
    uint8_t not_used;
    uint8_t extended_boot_signature;
    uint32_t volume_serial_number;
    char volume_label[11];
    char type_level[8];
    char not_used2[448];
    uint16_t signature;
} __attribute__((__packed__));


struct root_dir_entry{
    char file_name[11];
    uint8_t atributes;
    uint8_t reserved;
    uint8_t creation_time_secs;
    uint16_t creation_time_all;
    uint16_t creation_date;
    uint16_t access_date;
    uint16_t high_order;
    uint16_t modified_time;
    uint16_t modified_date;
    uint16_t low_order;
    uint32_t file_size;
}__attribute__((__packed__));




struct volume_t{
    struct bootsec b_sector;
    struct disk_t *file;
    uint16_t *fat;
    struct root_dir_entry *rootsectors;

} __attribute__((__packed__));



struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct clusters_chain_t {
    uint16_t *clusters;
    size_t size;
};
struct file_t {
    struct volume_t *volume;
    struct clusters_chain_t *chains;
    uint16_t file_pos;
    size_t file_size;
};


struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t{
    void *dir_data;
    size_t size;
    size_t position;
};

struct dir_entry_t {
    char name[13];
    size_t size;
    unsigned int is_archived;
    unsigned int is_readonly;
    unsigned int is_system;
    unsigned int is_hidden;
    unsigned int is_directory;
};
struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);
#endif //FAT16_FILE_READER_H
