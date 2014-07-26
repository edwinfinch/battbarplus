#pragma once
	
typedef enum {
	POSITION_B,
	POSITION_T,
} BattBarPos;

typedef enum {
	THEME_DARK,
	THEME_LIGHT,
} BattBarTheme;

typedef enum {
	ANIM_ONE_CHUNK,
	ANIM_ALL_CHUNKS,
} BattBarAnim;

typedef enum {
	STYLE_CIRCLES,
	STYLE_RECTANGLE,
	STYLE_LINE,
} BattBarStyle;

typedef struct BattBarOps {
	bool isWatchface;
	BattBarTheme theme;
	BattBarAnim anim;
	BattBarPos pos;
	BattBarStyle style;
} BattBarOps;

void init_battbar(BattBarOps ops, Window *window);
void get_default_battbar_ops();
void refresh_battbar(BatteryChargeState charge);
void deinit_battbar();
void custom_battbar_value_load(int value);
void battbar_set_hidden(bool hidden);
void override(uint8_t KEY, int value);