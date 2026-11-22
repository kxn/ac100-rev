// func whitelist_entry_add @ 004cbd34 size=1048

undefined4 whitelist_entry_add(void *param_1,char *param_2,char *param_3,int param_4)

{
  int iVar1;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  void *__s;
  undefined4 uVar4;
  int iVar5;
  char local_2a0 [20];
  undefined1 auStack_28c [92];
  undefined1 auStack_230 [524];
  
  memset(auStack_28c,0,0x5c);
  local_2a0[0] = '\0';
  local_2a0[1] = '\0';
  local_2a0[2] = '\0';
  local_2a0[3] = '\0';
  local_2a0[4] = '\0';
  local_2a0[5] = '\0';
  local_2a0[6] = '\0';
  local_2a0[7] = '\0';
  local_2a0[8] = '\0';
  local_2a0[9] = '\0';
  local_2a0[10] = '\0';
  local_2a0[0xb] = '\0';
  local_2a0[0xc] = '\0';
  local_2a0[0xd] = '\0';
  local_2a0[0xe] = '\0';
  local_2a0[0xf] = '\0';
  local_2a0[0x10] = '\0';
  local_2a0[0x11] = '\0';
  memset(auStack_230,0,0x205);
  wips_mac2str(param_1,local_2a0);
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d add to whitelist. mac: %s, ssid: %s[%d]\n","whitelist_entry_add",
           0x281,local_2a0,param_2,param_3);
  }
  iVar1 = memcmp(param_1,&DAT_006a81e4,6);
  iVar5 = 1;
  if (iVar1 == 0) {
    if ((*param_2 != '\0') && (param_3 != (char *)0x0)) {
      iVar5 = 2;
      goto LAB_004cbdf4;
    }
    if (sensor_err_switch != '\0') {
      uVar4 = 0xfffffffe;
      printf("[SENSOR_ERROR]%s()/%d para of whitelist error\n","whitelist_entry_add",0x287);
      __s = (void *)0x0;
      goto LAB_004cbe38;
    }
    uVar4 = 0xfffffffe;
  }
  else {
LAB_004cbdf4:
    iVar1 = wips_whitelist_get(param_1,param_2,param_3,iVar5,auStack_28c);
    if (iVar1 == 0) {
      if (sensor_warning_switch != '\0') {
        __format = "[SENSOR_WARNING]%s()/%d device[mac=%s]/ssid %s[%d] is already in whitelist\n";
        uVar3 = 0x28f;
        pcVar2 = local_2a0;
        param_3 = param_2;
LAB_004cbf6c:
        uVar4 = 0xfffffffd;
        printf(__format,"whitelist_entry_add",uVar3,pcVar2,param_3);
        __s = (void *)0x0;
        goto LAB_004cbe38;
      }
      uVar4 = 0xfffffffd;
    }
    else {
      iVar1 = wserv_db_get_entry_by_ssid(param_2,param_3,auStack_230);
      if (iVar1 != 0) {
        __s = (void *)FUN_00408450(0x5c,0x29c);
        if (__s == (void *)0x0) {
          uVar4 = 0xffffffff;
          if (sensor_err_switch == '\0') goto LAB_004cbe38;
          pcVar2 = "[SENSOR_ERROR]%s()/%d out of memory\n";
          uVar3 = 0x29f;
        }
        else {
          memset(__s,0,0x5c);
          FUN_004082d0(wips_global_mutex,0xffffffff);
          uVar3 = FUN_004085b0(g_whitelist_id_allocator);
          uVar4 = wips_global_mutex;
          *(undefined4 *)((int)__s + 0xc) = uVar3;
          FUN_00407f30(uVar4);
          if (*(int *)((int)__s + 0xc) == -1) {
            uVar4 = 0xfffffffb;
            if (sensor_warning_switch == '\0') goto LAB_004cbe38;
            pcVar2 = "[SENSOR_WARNING]%s()/%d alloc whitelist id error\n";
            uVar3 = 0x2aa;
          }
          else {
            if (iVar5 == 1) {
              memcpy((void *)((int)__s + 0x10),param_1,6);
              strcpy((char *)((int)__s + 0x16),"");
              *(undefined4 *)((int)__s + 0x48) = 0;
            }
            else {
              memcpy((void *)((int)__s + 0x10),&DAT_006a81e4,6);
              strcpy((char *)((int)__s + 0x16),param_2);
              *(char **)((int)__s + 0x48) = param_3;
            }
            uVar4 = wips_local_time_get();
            *(undefined4 *)((int)__s + 0x58) = uVar4;
            if (param_4 == 0) {
              *(undefined4 *)((int)__s + 0x54) = 0;
              *(undefined2 *)((int)__s + 0x4c) = 0xffff;
              *(undefined4 *)((int)__s + 0x50) = 0x7f;
LAB_004cc048:
              FUN_004082d0(wips_global_mutex,0xffffffff);
              FUN_00408240(&g_white_list,__s);
              FUN_00407f30(wips_global_mutex);
              sensor_db_sqlite_notify_msg(3,__s,0x5c);
              wips_update_due_to_whitelist(__s,1);
              return 0;
            }
            iVar1 = FUN_004081b0(param_4 + 0x9c);
            if (iVar1 != 0) {
              *(undefined2 *)((int)__s + 0x4c) = *(undefined2 *)(iVar1 + 0x38);
              *(undefined4 *)((int)__s + 0x50) = *(undefined4 *)(iVar1 + 0x30);
              *(undefined4 *)((int)__s + 0x54) = *(undefined4 *)(iVar1 + 0x24);
              goto LAB_004cc048;
            }
            uVar4 = 0xfffffffc;
            if (sensor_err_switch == '\0') goto LAB_004cbe38;
            pcVar2 = "[SENSOR_ERROR]%s()/%d get wips detail from wips_info failed\n";
            uVar3 = 0x2c5;
          }
        }
        printf(pcVar2,"whitelist_entry_add",uVar3);
        goto LAB_004cbe38;
      }
      if (sensor_warning_switch != '\0') {
        __format = "[SENSOR_WARNING]%s()/%d ssid %s[%d] is already in wserv\n";
        uVar3 = 0x297;
        pcVar2 = param_2;
        goto LAB_004cbf6c;
      }
      uVar4 = 0xfffffffd;
    }
  }
  __s = (void *)0x0;
LAB_004cbe38:
  FUN_004082d0(wips_global_mutex,0xffffffff);
  if (((__s != (void *)0x0) && (*(int *)((int)__s + 0xc) != -1)) &&
     (iVar1 = FUN_004086a0(g_whitelist_id_allocator), iVar1 == 1)) {
    FUN_004080f0(g_whitelist_id_allocator,*(undefined4 *)((int)__s + 0xc));
  }
  FUN_00407f30(wips_global_mutex);
  if (__s != (void *)0x0) {
    FUN_00407df0(__s);
  }
  return uVar4;
}

