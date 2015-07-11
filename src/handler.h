/* ***********************************************************************\
*  _____ _            ____                  _       _                     *
* |_   _| |__   ___  |  _ \  ___  _ __ ___ (_)_ __ (_) ___  _ __          *
*   | | | '_ \ / _ \ | | | |/ _ \| '_ ` _ \| | '_ \| |/ _ \| '_ \         *
*   | | | | | |  __/ | |_| | (_) | | | | | | | | | | | (_) | | | |        *
*   |_| |_| |_|\___| |____/ \___/|_| |_| |_|_|_| |_|_|\___/|_| |_|        *
*                                                                         *
*  File:  HANDLER.H                                    Based on CircleMUD *
*  Usage: Header: Prototypes of Handling and Utility Functions            *
*  Programmer(s): Original code by Jeremy Elson (Ras)                     *
*                 All modifications by Sean Mountcastle (Glasgian)        *
\*********************************************************************** */

#ifndef __HANDLER_H__
#define __HANDLER_H__

/* handling the affected-structures */
void    affect_total(struct char_data *ch);
void    affect_modify(struct char_data *ch, byte loc, sbyte mod, long bitv, bool add, bool harmful);
void    affect_to_char(struct char_data *ch, struct affected_type *af, bool harmful);
void    affect_remove(struct char_data *ch, struct affected_type *af, bool harmful);
void    affect_from_char(struct char_data *ch, sh_int type, bool harmful);
bool    affected_by_spell(struct char_data *ch, sh_int type, bool harmful);
void    affect_join(struct char_data *ch, struct affected_type *af,
	bool add_dur, bool avg_dur, bool add_mod, bool avg_mod, bool harmful);


/* utility */
char    *money_desc(long amount);
struct  obj_data *create_money(long amount);
int     isname(char *str, char *namelist);
char    *fname(char *namelist);
int     get_number(char **name);

/* ******** objects *********** */

void    obj_to_char(struct obj_data *object, struct char_data *ch);
void    obj_from_char(struct obj_data *object);

void    equip_char(struct char_data *ch, struct obj_data *obj, int pos);
struct  obj_data *unequip_char(struct char_data *ch, int pos);

struct  obj_data *get_obj_in_list(char *name, struct obj_data *list);
struct  obj_data *get_obj_in_list_num(long num, struct obj_data *list);
struct  obj_data *get_obj(char *name);
struct  obj_data *get_obj_num(long nr);
int     find_lodged_obj(struct char_data *ch, char *arg);

void    obj_to_room(struct obj_data *object, long room);
void    obj_from_room(struct obj_data *object);
void    obj_to_obj(struct obj_data *obj, struct obj_data *obj_to);
void    obj_from_obj(struct obj_data *obj);
void    object_list_new_owner(struct obj_data *list, struct char_data *ch);

void    extract_obj(struct obj_data *obj);

/* ******* characters ********* */

struct  char_data *get_char_room(char *name, long room);
struct  char_data *get_char_num(long nr);
struct  char_data *get_char(char *name);

void    char_from_room(struct char_data *ch);
void    char_to_room(struct char_data *ch, long room);
void    extract_char(struct char_data *ch);

/* find if character can see */
struct  char_data *get_char_room_vis(struct char_data *ch, char *name);
struct  char_data *get_char_scan_vis(struct char_data * ch, char *name);
struct  char_data *get_player_vis(struct char_data *ch, char *name, long inroom);
struct  char_data *get_char_vis(struct char_data *ch, char *name);
struct  obj_data *get_obj_in_list_vis(struct char_data *ch, char *name,
	struct obj_data *list);
struct  obj_data *get_obj_vis(struct char_data *ch, char *name);
struct  obj_data *get_object_in_equip_vis(struct char_data *ch,
	char *arg, struct obj_data *equipment[], int *j);

/* find all dots */

int     find_all_dots(char *arg);

#define FIND_INDIV      0
#define FIND_ALL        1
#define FIND_ALLDOT     2


/* Generic Find */

int     generic_find(char *arg, int bitvector, struct char_data *ch,
	struct char_data **tar_ch, struct obj_data **tar_obj);

#define FIND_CHAR_ROOM     1
#define FIND_CHAR_WORLD    2
#define FIND_OBJ_INV       4
#define FIND_OBJ_ROOM      8
#define FIND_OBJ_WORLD    16
#define FIND_OBJ_EQUIP    32

/* prototypes from crash save system */

int     Crash_get_filename(char *orig_name, char *filename);
int     Crash_delete_file(char *name);
int     Crash_delete_crashfile(struct char_data *ch);
int     Crash_clean_file(char *name);
void    Crash_listrent(struct char_data *ch, char *name);
int     Crash_load(struct char_data *ch);
void    Crash_crashsave(struct char_data *ch);
void    Crash_idlesave(struct char_data *ch);
void    Crash_save_all(void);

/* prototypes from fight.c */
void    set_fighting(struct char_data *ch, struct char_data *victim);
void    stop_fighting(struct char_data *ch);
void    stop_follower(struct char_data *ch);
void    hit(struct char_data *ch, struct char_data *victim, int type);
void    forget(struct char_data *ch, struct char_data *victim);
void    remember(struct char_data *ch, struct char_data *victim);
void    damage(struct char_data *ch, struct char_data *victim, int dam, int attacktype, int hitloc);
int     skill_message(int dam, struct char_data *ch, struct char_data *vict,
		      int attacktype);

#endif     /* #ifndef _HANDLER_H */

