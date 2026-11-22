// func _sensor_di_db_check_sensor_exists_in_cached_list @ 004dca04 size=176

int _sensor_di_db_check_sensor_exists_in_cached_list(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = FUN_004081b0(&l_sensor_di_cached_sensor_list);
  do {
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists in cached lsit\n";
        uVar2 = 0x6af;
LAB_004dcaa4:
        printf(__format,"_sensor_di_db_check_sensor_exists_in_cached_list",uVar2);
      }
      return iVar1;
    }
    if (param_1 == *(int *)(iVar1 + 0xc)) {
      if (sensor_di_debug_switch == 0) {
        return iVar1;
      }
      __format = "[SENSOR_DI_DEBUG]%s()/line %d : find sensor exists in cached list.\n";
      uVar2 = 0x6ab;
      goto LAB_004dcaa4;
    }
    iVar1 = FUN_00408680(iVar1);
  } while( true );
}

