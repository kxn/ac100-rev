// func wips_detail_entry_add @ 004c7b84 size=220

void wips_detail_entry_add(undefined4 param_1,void *param_2)

{
  void *__dest;
  
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d add detail to wips\n","wips_detail_entry_add",0x321);
  }
  __dest = (void *)FUN_00408450(0x3c,0x324);
  if (__dest == (void *)0x0) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_detail_entry_add",0x327);
      return;
    }
    return;
  }
  memcpy(__dest,param_2,0x3c);
  wips_detail_insert_to_list(param_1,__dest);
  return;
}

