// func _sensor_db_wips_foreach_callback @ 004cf12c size=540

undefined4
_sensor_db_wips_foreach_callback
          (undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *__s1;
  char *__nptr;
  int iVar3;
  undefined1 auStack_88 [12];
  int local_7c;
  undefined1 auStack_78 [6];
  char acStack_72 [50];
  int local_40;
  undefined2 local_3c;
  int local_38;
  long local_34;
  long local_30;
  
  iVar3 = 0;
  while( true ) {
    if (param_2 <= iVar3) {
      uVar2 = wips_whitelist_entry_load(auStack_88);
      return uVar2;
    }
    __s1 = (char *)*param_4;
    if ((__s1 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) break;
    iVar1 = strcmp(__s1,"whitelist_id");
    if (iVar1 == 0) {
      local_7c = atoi(__nptr);
    }
    else {
      iVar1 = strcmp(__s1,"mac");
      if (iVar1 == 0) {
        wips_str2mac(__nptr,auStack_78);
      }
      else {
        iVar1 = strcmp(__s1,"ssid");
        if (iVar1 == 0) {
          strncpy(acStack_72,__nptr,0x31);
        }
        else {
          iVar1 = strcmp(__s1,"ssid_encode");
          if (iVar1 == 0) {
            local_40 = atoi(__nptr);
          }
          else {
            iVar1 = strcmp(__s1,"sensor_id");
            if (iVar1 == 0) {
              iVar1 = atoi(__nptr);
              local_3c = (undefined2)iVar1;
            }
            else {
              iVar1 = strcmp(__s1,"rssi");
              if (iVar1 == 0) {
                local_38 = atoi(__nptr);
              }
              else {
                iVar1 = strcmp(__s1,"last_discover_time");
                if (iVar1 == 0) {
                  local_34 = atol(__nptr);
                }
                else {
                  iVar1 = strcmp(__s1,"operation_time");
                  if (iVar1 == 0) {
                    local_30 = atol(__nptr);
                  }
                }
              }
            }
          }
        }
      }
    }
    iVar3 = iVar3 + 1;
    param_3 = param_3 + 1;
    param_4 = param_4 + 1;
  }
  if (sensor_err_switch == '\0') {
    return 0xffffffff;
  }
  printf("[SENSOR_ERROR]%s()/%d column_name or column_value is null\n",
         "_sensor_db_wips_foreach_callback",0x49b);
  return 0xffffffff;
}

