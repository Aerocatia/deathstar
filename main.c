#ifndef __VERSION__
#define __VERSION__ "Unknown"
#endif
#ifndef __DATE__
#define __DATE__ "Unknown"
#endif

#include "ZZTDeathstar.h"
#include "ZZTTagData.h"

#define PROG_VERSION "Deathstar 1.0a13"

static inline uint32_t swapEndian32(uint32_t integer) {
    char swappedValue[4];
    swappedValue[3] = integer       & 0xFF;
    swappedValue[2] = integer >> 8  & 0xFF;
    swappedValue[1] = integer >> 16 & 0xFF;
    swappedValue[0] = integer >> 24 & 0xFF;
    return *(uint32_t *)swappedValue;
}

int main(int argc, const char * argv[])
{
    if(argc == 1 || strcmp(argv[1],"--help") == 0) {
        if(argc <= 2) {
            printf("Deprotection\n");
            printf("deathstar --deprotect <map> [maps...] ; Deprotect map at path.\n");
            printf("deathstar --zteam <map> ; Only remove zteam protection.\n");
            printf("deathstar --name <map> [maps...]  ; Rename all tags to generic names.\n");
            printf("deathstar --preview <map>  ; Removes zteam protection without saving map.\n");
            printf("\n");
            printf("Information\n");
            printf("deathstar --help [--argument]; View this list, or help on an argument.\n");
            printf("deathstar --version ; View version.\n");
        }
        else if(strcmp(argv[2],"--version") == 0) {
            printf("Syntax: deathstar --version\n\n");
            printf("View the version of me.\n");
        }
        else if(strcmp(argv[2],"--help") == 0) {
            printf("Syntax: deathstar --help [--argument]\n\n");
            printf("Get help on arguments, or a list of arguments.\n");
            printf("If you need anything further explained, you can contact me at\n");
            printf("opencarnage.net.\n");
        }
        else if(strcmp(argv[2],"--zteam") == 0) {
            printf("Syntax: deathstar --zteam <map>\n\n");
            printf("Z-Team deprotection deobfuscates class names of tags.\n\n");
            printf("It will recursively deprotect obje tags referenced by the main\n");
            printf("scenario tag, or the globals\\globals matg tag.\n\n");
        }
        else if(strcmp(argv[2],"--name") == 0) {
            printf("Syntax: deathstar --name <map> [maps...]\n\n");
            printf("Name deprotection changes names of all tags to a generic name.\n\n");
            printf("You may optionally include a list of paths to maps to attempt to\n");
            printf("match any tags with maps.\n");
        }
        else if(strcmp(argv[2],"--deprotect") == 0) {
            printf("Syntax: deathstar --deprotect <map> [maps...]\n\n");
            printf("Death Star will do z-team deprotection, followed by name\n");
            printf("deprotection.\n\n");
            printf("Use deathstar --help --name for information on name.\n");
            printf("Use deathstar --help --zteam for information on zteam.\n");
        }
        else if(strcmp(argv[2],"--preview") == 0) {
            printf("Syntax: deathstar --preview <map>\n\n");
            printf("Death Star will do z-team deprotection, but it won't save\n");
            printf("the map. Instead, it will output the results.\n\n");
            printf("Use deathstar --help --zteam for information on zteam.\n");
        }
        else {
            printf("Unsupported help topic.\n");
        }
        return 0;
    }
    else if(strcmp(argv[1],"--preview") == 0) {
        if(argc != 3) {
            printf("Syntax: deathstar --preview <map>\n");
            printf("Use deathstar --help --preview for more information.\n");
            return 0;
        }
        MapData map = openMapAtPath(argv[2]);
        if(map.error == MAP_INVALID_PATH) {
            printf("Failed to open map at %s. Invalid path?\n",argv[2]);
            return 0;
        }
        else if(map.error == MAP_INVALID_INDEX_POINTER) {
            printf("Failed to open map. Path is valid, but map isn't.\n");
            return 0;
        }
        MapData final_map = zteam_deprotect(map);

        HaloMapHeader *header = ((HaloMapHeader *)final_map.buffer);
        HaloMapIndex *index = (HaloMapIndex *)(final_map.buffer + header->indexOffset);
        uint32_t mapMagic = 0x40440000 - header->indexOffset;

        uint32_t tagsOffset = index->tagIndexOffset - mapMagic;

        MapTag *tagsOriginal = (MapTag *)(map.buffer + tagsOffset);
        MapTag *tagsModified = (MapTag *)(final_map.buffer + tagsOffset);

        bool modification = false;

        for(uint32_t i=0;i<index->tagCount;i++) {
            if(tagsModified[i].classA != tagsOriginal[i].classA) {
                char *classOriginal = calloc(5,1);
                char *classModified = calloc(5,1);
                uint32_t class = swapEndian32(tagsOriginal[i].classA);
                memcpy(classOriginal,&class,4);
                class = swapEndian32(tagsModified[i].classA);
                memcpy(classModified,&class,4);
                printf("%s.%s -> %s\n",(char *)header + tagsModified[i].nameOffset - mapMagic,classOriginal,classModified);
                free(classOriginal);
                free(classModified);
                modification = true;
            }
        }
        if(!modification) {
            printf("No changes were made.\n");
        }

    }
    else if(strcmp(argv[1],"--argument") == 0) {
        printf("Syynantax:as: -arrrar-gummeargmetnetn\n"); //Funny!
        printf("urllo vg ferms lou unir qispbireed zl rigt\n");
        printf("za abj v uavr go sinq fbme orgtre jay tb u\n");
        printf("vde ml fghfs\n");
    }
    else if(strcmp(argv[1],"--name") == 0) {
        if(argc < 3) {
            printf("Syntax: deathstar --name <map> [index maps]\n");
            printf("Use deathstar --help --name for more information.\n");
            return 0;
        }
        else {
            MapData map = openMapAtPath(argv[2]);
            if(map.error == MAP_INVALID_PATH) {
                printf("Failed to open map at %s. Invalid path?\n",argv[2]);
                return 0;
            }
            else if(map.error == MAP_INVALID_INDEX_POINTER) {
                printf("Failed to open map. Path is valid, but map isn't.\n");
                return 0;
            }

            MapData *maps = malloc(sizeof(MapData) * (argc - 3));

            for(int i=3; i<argc; i++) {
                maps[i] = openMapAtPath(argv[i]);
            }

            MapData final_map = name_deprotect(map);
            if(saveMap(argv[2], final_map) == 0)
                printf("Completed. Map has been saved!\n");
            else
                printf("Failed to save map. It might be read-only.\n");
        }

    }
    else if(strcmp(argv[1],"--deprotect") == 0) {
        if(argc < 3) {
            printf("Syntax: deathstar --deprotect <map> [index maps]\n");
            printf("Use deathstar --help --deprotect for more information.\n");
            return 0;
        }
        else {
            MapData map = openMapAtPath(argv[2]);
            if(map.error == MAP_INVALID_PATH) {
                printf("Failed to open map at %s. Invalid path?\n",argv[2]);
                return 0;
            }
            else if(map.error == MAP_INVALID_INDEX_POINTER) {
                printf("Failed to open map. Path is valid, but map isn't.\n");
                return 0;
            }
            MapData zteam_map = zteam_deprotect(map);

            free(map.buffer);

            MapData *maps = malloc(sizeof(MapData) * (argc - 3));

            for(int i=3; i<argc; i++) {
                maps[i] = openMapAtPath(argv[i]);
            }

            MapData final_map = name_deprotect(zteam_map);

            if(saveMap(argv[2], final_map) == 0)
                printf("Completed. Map has been saved!\n");
            else
                printf("Failed to save map. It might be read-only.\n");
        }
        return 0;
    }
    else if(strcmp(argv[1],"--zteam") == 0) {
        if(argc != 3) {
            printf("Syntax: deathstar --zteam <map>\n");
            printf("Use deathstar --help --zteam for more information.\n");
            return 0;
        }
        else {
            MapData map = openMapAtPath(argv[2]);
            if(map.error == MAP_INVALID_PATH) {
                printf("Failed to open map at %s. Invalid path?\n",argv[2]);
                return 0;
            }
            else if(map.error == MAP_INVALID_INDEX_POINTER) {
                printf("Failed to open map. Path is valid, but map isn't.\n");
                return 0;
            }
            MapData final_map = zteam_deprotect(map);
            if(saveMap(argv[2], final_map) == 0)
                printf("Completed. Map has been saved!\n");
            else
                printf("Failed to save map. It might be read-only.\n");
        }
        return 0;
    }
    else if(strcmp(argv[1],"--version") == 0) {
        printf("Death Star version: %s\n",PROG_VERSION);
        printf("Compilation date: %s\n",__DATE__);
        return 0;
    }
    else {
        printf("Unknown option %s\n",argv[1]);
        printf("Use --help for help.\n");
    }
    return 0;
}

