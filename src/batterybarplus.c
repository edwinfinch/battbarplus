#include <pebble.h>
#include "batterybarplus.h"
	
Layer *battery_bar_layer;
BattBarOps ops;
AppTimer *anim_timer;
BatteryChargeState global_charge;

BattBarOps get_default_battbar_ops(){
	BattBarOps ops_return;
	
	ops_return.watchfaceIsTrue = 1;
	ops_return.BattBarTheme = THEME_LIGHT;
	ops_return.BattBarAnim = ANIM_ONE_CHUNK;
	ops_return.BattBarPos = POSITION_B;
	ops_return.BattBarStyle = STYLE_CIRCLES;
	
	return ops_return;
}

void update_proc(Layer *layer, GContext *ctx){
	if(ops.theme == THEME_LIGHT){
		APP_LOG(APP_LOG_LEVEL_DEBUG, "Theme is light.");
		graphics_context_set_stroke_color(ctx, GColorWhite);
		graphics_context_set_fill_color(ctx, GColorWhite);
	}
	else{
		APP_LOG(APP_LOG_LEVEL_DEBUG, "Theme is dark.");
		graphics_context_set_stroke_color(ctx, GColorBlack);
		graphics_context_set_fill_color(ctx, GColorBlack);
	}
	
	if(charge.is_charging){
		
	}
	
	if(ops.style = STYLE_CIRCLES){
		
	}
}

void init_battbar(BattBarOps received_ops, Window *received_window){
	ops = received_ops;
	
	battery_bar_layer = layer_create(GRect(0, 0, 144, 168));
	layer_set_update_proc(battery_bar_layer, update_proc);
	layer_add_child(window_get_root_layer(received_window), battery_bar_layer);
	
	global_charge = battery_state_service_peek();
	layer_mark_dirty(battery_bar_layer);
}

void custom_battbar_value_load(int value){
	
}

void deinit_battbar(){
	
}

void refresh_battbar(BatteryChargeState charge){
	
}

void battbar_set_hidden(bool hidden){
	layer_set_hidden(battery_bar_layer, hidden);
}