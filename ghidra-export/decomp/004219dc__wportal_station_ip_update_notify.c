// func _wportal_station_ip_update_notify @ 004219dc size=968

undefined4 _wportal_station_ip_update_notify(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char local_338 [20];
  char acStack_324 [40];
  undefined1 auStack_2fc [223];
  undefined1 auStack_21d [141];
  undefined1 auStack_190 [12];
  undefined1 auStack_184 [76];
  char acStack_138 [244];
  int local_44;
  
  memset(auStack_190,0,0x180);
  memset(auStack_2fc,0,0x168);
  memset(acStack_324,0,0x28);
  local_338[0] = '\0';
  local_338[1] = '\0';
  local_338[2] = '\0';
  local_338[3] = '\0';
  local_338[4] = '\0';
  local_338[5] = '\0';
  local_338[6] = '\0';
  local_338[7] = '\0';
  local_338[8] = '\0';
  local_338[9] = '\0';
  local_338[10] = '\0';
  local_338[0xb] = '\0';
  local_338[0xc] = '\0';
  local_338[0xd] = '\0';
  local_338[0xe] = '\0';
  local_338[0xf] = '\0';
  local_338[0x10] = '\0';
  local_338[0x11] = '\0';
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Sta ip update: mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
           "_wportal_station_ip_update_notify",0x2736,(uint)*(byte *)(param_1 + 0x68),
           (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
           (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
           (uint)*(byte *)(param_1 + 0x6d));
  }
  memset(auStack_190,0,0x180);
  iVar1 = wportal_db_aut_get(param_1 + 0x68,auStack_190);
  if (iVar1 == 0) {
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Already authed MAC: %02x:%02x:%02x:%02x:%02x:%02x status:%d\n",
             "_wportal_station_ip_update_notify",0x273e,(uint)*(byte *)(param_1 + 0x68),
             (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
             (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
             (uint)*(byte *)(param_1 + 0x6d),local_44);
    }
    if ((local_44 == 9) && (*(char *)(param_1 + 0x3c) == '\x01')) {
      memset(acStack_324,0,0x28);
      FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                   *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                   *(undefined4 *)(param_1 + 0x4c),acStack_324,0x28,"---");
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d [%s]->[%s] \n\n","_wportal_station_ip_update_notify",0x2747,
               acStack_324,acStack_138);
      }
      iVar1 = strncmp(acStack_324,acStack_138,0x28);
      if (iVar1 != 0) {
        iVar1 = json_object_new_object();
        snprintf(local_338,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x68),
                 (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
                 (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
                 (uint)*(byte *)(param_1 + 0x6d));
        uVar2 = json_object_new_string(local_338);
        json_object_object_add(iVar1,"mac",uVar2);
        uVar2 = json_object_new_int(0xe);
        json_object_object_add(iVar1,"type",uVar2);
        uVar2 = json_object_new_string(acStack_324);
        json_object_object_add(iVar1,&DAT_00677c24,uVar2);
        wportal_send_to_nginx(iVar1);
        if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d ip changed !\n\n","_wportal_station_ip_update_notify",0x2753)
          ;
        }
        memset(acStack_138,0,0x28);
        memcpy(acStack_138,acStack_324,0x28);
        wportal_db_aut_set(auStack_190);
        _wportal_update_entry_radius(auStack_190);
        memset(auStack_2fc,0,0x168);
        iVar3 = wportal_db_nsa_get(auStack_184,auStack_2fc);
        if (iVar3 == 0) {
          if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d update nsaEntry\n","_wportal_station_ip_update_notify",
                   0x275e);
          }
          memcpy(auStack_21d,acStack_138,0x28);
          wportal_db_nsa_set(auStack_2fc);
        }
        if (iVar1 != 0) {
          json_object_put(iVar1);
        }
      }
    }
  }
  return 0;
}

